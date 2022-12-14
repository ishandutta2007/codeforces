#include<cstdio>
#include<cstring>

int N, len, a[2000];
char s[1000];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++)
	{
		//printf("C2");	
		gets(s);
		len = strlen(s);
		//printf("D2");	
		for (int j = 0; j < len; j++)
			a[s[j] - 'a'] = 1;
	 	//printf("B2");	
	
		for (int j = 0; j < len - 1; j++)
			a[26 * (s[j] - 'a' + 1) + s[j + 1] - 'a'] = 1;  
		//printf("A2");	
	}
	for (int i = 0; i < 1000; i++)
	{
		if (a[i] == 0)
		{
			if (i < 26)
				printf("%c", i + 'a');
			else
				printf("%c%c", i / 26 + 'a' - 1, i % 26 + 'a');
			return 0;
		}
	}
	return 0;
}