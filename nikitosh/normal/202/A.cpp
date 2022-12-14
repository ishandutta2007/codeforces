#include<cstdio>
#include<cstring>

int i, j, a[100];
char s[100];

int main()
{
	gets(s);                   
	for (i = 0; i < (int) strlen(s); i++)
	{
		a[s[i] - 'a']++;
	}        
	for (i = 25; i >= 0; i--)
	{
		if (a[i] != 0)
		{
			for (j = 0; j < a[i]; j++)
				printf("%c", 'a' + i);
			return 0; 
		}
	}
	return 0;
}