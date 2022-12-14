#include<cstdio>
#include<cstring>

int len, day, month, year, p, q, r, max1 = -100, a[50][20][10];
char s[200000];

int c(char ch)
{
	if (ch >= '0' && ch <= '9')
		return 1;
	return 0;
}

int d(char ch)
{
	if (ch == '-')
		return 1;
	return 0;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	gets(s);
	len = strlen(s);
	for (int i = 0; i < len - 9; i++)
	{
		if (c(s[i]) && c(s[i + 1]) && d(s[i + 2]) && c(s[i + 3]) && c(s[i + 4]) 
		&& d(s[i + 5]) && c(s[i + 6]) && c(s[i + 7]) && c(s[i + 8]) && c(s[i + 9]))
		{
			day = 10 * (s[i] - '0') + s[i + 1] - '0';
			month = 10 * (s[i + 3] - '0') + s[i + 4] - '0';
			year = 1000 * (s[i + 6] - '0') + 100 * (s[i + 7] - '0') + 10 * (s[i + 8] - '0') + s[i + 9] - '0';
			//printf("%d %d %d\n", day, month, year);
			if (month == 0 || month > 12)
				continue;
			if (day == 0)
				continue;
			if (month == 1 && day > 31)
				continue;
			if (month == 3 && day > 31)
				continue;
			if (month == 5 && day > 31)
				continue;
			if (month == 7 && day > 31)
				continue;
			if (month == 8 && day > 31)
				continue;
			if (month == 10 && day > 31)
				continue;
			if (month == 12 && day > 31)
				continue;
			if (month == 4 && day > 30)
				continue;
			if (month == 6 && day > 30)
				continue;
			if (month == 9 && day > 30)
				continue;
			if (month == 11 && day > 30)
				continue;
			if (month == 2 && day > 28)
				continue;
			if (year < 2013 || year > 2015)
				continue;
			//printf("A");
			a[day][month][year - 2012]++;
		}
	}
	for (int i = 1; i < 32; i++)
		for (int j = 1; j < 13; j++)
			for (int g = 1; g < 4; g++)
				if (a[i][j][g] > max1)
				{
					max1 = a[i][j][g];
					p = i;
					q = j;
					r = g;
				}
	if (p < 10)
		printf("0");
	printf("%d-", p);
	if (q < 10)
		printf("0");
	printf("%d-", q);
	printf("%d\n", r + 2012);
	return 0;
}