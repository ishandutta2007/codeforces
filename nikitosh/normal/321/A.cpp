#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int a, b, len, x, y, dx, dy, k, l, m1, m2, boo1, boo2, boo3, boo4;
char s[1000];
vector <pair <int, int> > c;

int main()
{
	scanf("%d%d\n", &a, &b);
	gets(s);
	len = strlen(s);
	c.push_back(make_pair(0, 0));
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'R')
			x++;
		if (s[i] == 'L')
			x--;
		if (s[i] == 'U')
			y++;
		if (s[i] == 'D')
			y--;
		c.push_back(make_pair(x, y));
	}
	k = x;
	l = y;
	for (int i = 0; i < (int) c.size(); i++)
	{
		dx = a - c[i].first;
		dy = b - c[i].second;
		boo1 = 0;
		boo2 = 0;
		boo3 = 0;
		boo4 = 0;
		m1 = -1;
		m2 = -2;
		if (k == 0)
		{
			if (dx == 0)
				boo1 = 1;
		}	
		else
			if (((long long) dx * (long long) k >= 0) && dx % k == 0)
			{
				m1 = dx / k;
				boo3 = 1;
			}
		if (l == 0)
		{
			if (dy == 0)
				boo2 = 1;
		}	
		else
			if (((long long) dy * (long long) l >= 0) && dy % l == 0)
			{
				m2 = dy / l;
				boo4 = 1;
			}
		if (boo1 == 1 && boo2 == 1)
		{
			printf("Yes\n");
			return 0;
		}
		if (boo1 == 1 && boo4 == 1)
		{
			printf("Yes\n");
			return 0;
		}
		if (boo3 == 1 && boo2 == 1)
		{
			printf("Yes\n");
			return 0;
		}
		if (boo3 == 1 && boo4 == 1 && m1 == m2)
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}