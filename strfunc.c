#include "shell.h"

/**
 * _puts - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
ssize_t _puts(char *str)
{
	ssize_t num, leng;

	num = _strlen(str);
	leng = write(STDOUT_FILENO, str, num);
	if (leng != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (leng);
}

/**
 * _strdup - returns pointer to new mem alloc space which contains copy
 * @strtodup: string to be duplicated
 * Return: a pointer to the new duplicated string
 */
char *_strdup(char *strtodup)
{
	char *copy;

		int leng, i;

	if (strtodup == 0)
		return (NULL);

	for (leng = 0; strtodup[leng]; leng++)
		;
	copy = malloc((leng + 1) * sizeof(char));

	for (i = 0; i <= leng; i++)
		copy[i] = strtodup[i];

	return (copy);
}

/**
 * _strcmpr - compares two strings
 * @strcmp1: first string, of two, to be compared in length
 * @strcmp2: second string, of two, to be compared
 * Return: 0 on success, anything else is a failure
 */
int _strcmpr(char *strcmp1, char *strcmp2)
{
	int i;

	i = 0;
	while (strcmp1[i] == strcmp2[i])
	{
		if (strcmp1[i] == '\0')
			return (0);
		i++;
	}
	return (strcmp1[i] - strcmp2[i]);
}

/**
 * _strcat - concatenates two strings
 * @strc1: first string
 * @strc2: second string
 * Return: pointer
 */
char *_strcat(char *strc1, char *strc2)
{
	char *newstring;
	unsigned int leng1, leng2, newleng, i, j;

	leng1 = 0;
	leng2 = 0;
	if (strc1 == NULL)
		leng1 = 0;
	else
	{
		for (leng1 = 0; strc1[leng1]; leng1++)
			;
	}
	if (strc2 == NULL)
		leng2 = 0;
	else
	{
		for (leng2 = 0; strc2[leng2]; leng2++)
			;
	}
	newlen = leng1 + leng2 + 2;
	newstring = malloc(newleng * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	for (i = 0; i < leng1; i++)
		newstring[i] = strc1[i];
	newstring[i] = '/';
	for (j = 0; j < leng2; j++)
		newstring[i + 1 + j] = strc2[j];
	newstring[leng1 + leng2 + 1] = '\0';
	return (newstring);
}

/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int leng;

	leng = 0;

	for (leng = 0; str[leng]; leng++)
		;
	return (leng);
}
