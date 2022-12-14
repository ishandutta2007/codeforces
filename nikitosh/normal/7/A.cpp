#include<cstdio>

char s[10][10];
int ans, boo;

int main()
{
	for (int i = 0; i < 8; i++)
		gets(s[i]);
	for (int i = 0; i < 8; i++)
	{
		boo = 0;
		for (int j = 0; j < 8; j++)
			if (s[i][j] == 'W')
				boo = 1;
		if (boo == 0)
			ans++;
	}
	if (ans == 8)
	{
		printf("%d\n", ans);
		return 0;
	}
	for (int i = 0; i < 8; i++)
	{
		boo = 0;
		for (int j = 0; j < 8; j++)
			if (s[j][i] == 'W')
				boo = 1;
		if (boo == 0)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}