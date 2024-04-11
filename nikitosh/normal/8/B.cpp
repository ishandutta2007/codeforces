#include<cstdio>
#include<cstring>

using namespace std;

char s[105];
int x, y, used[230][230], len;

int main()
{
	gets(s);
	len = strlen(s);
	x = 105;
	y = 105;
	for (int i = 0; i < len; i++)
	{
		if (used[x][y] == 1)
		{
			puts("BUG");
			return 0;
		}
		used[x][y] = 1;
		if (s[i] == 'L')
			x--;
		if (s[i] == 'R')
			x++;
		if (s[i] == 'D')
			y--;
		if (s[i] == 'U')
			y++;
	}
	used[x][y] = 1;
	for (int i = 1; i < 210; i++)
		for (int j = 1; j < 210; j++)
		{
			if (used[i][j] == 1)
			{
				int sz = 0;
				sz += used[i - 1][j] + used[i + 1][j] + used[i][j - 1] + used[i][j + 1];
				if (sz >= 3)
				{
					puts("BUG");
					return 0;
				}
				if (i == x && j == y && sz >= 2)
				{
					puts("BUG");
					return 0;
				}
			}
		}
	puts("OK");
	return 0;
}