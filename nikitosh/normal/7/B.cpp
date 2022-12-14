#include<cstdio>
#include<vector>

using namespace std;

int t, m, boo, k, BOO, l, a[105], sz;
vector <int> v; 
char c, ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8, ch9;
long long x;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d\n", &t, &m);
	for (int g = 0; g < t; g++)
	{
		scanf("%c", &c);
		if (c == 'a')
		{
			sz++;
			scanf("%c%c%c%c %d\n", &ch1, &ch2, &ch3, &ch4, &k);
			BOO = 0;
			for (int i = 0; i < m - k + 1; i++)
			{
			    boo = 0;
				for (int j = i; j < i + k; j++)
					if (a[j] != 0)
						boo = 1;
				if (boo == 0)
				{
					for (int j = i; j < i + k; j++)
						a[j] = sz;
					BOO = 1;
					printf("%d\n", sz);
					break;
				}
			}
			if (BOO == 0)
			{
				puts("NULL");
				sz--;
			}
		}
		if (c == 'e')
		{
			scanf("%c%c%c%c %I64d\n", &ch1, &ch2, &ch3, &ch4, &x);
			boo = 0;
			for (int i = 0; i < m; i++)
				if (a[i] == x)
				{
					boo = 1;
					l = i;
					break;
				}
			if (boo == 0 || x == 0)
				puts("ILLEGAL_ERASE_ARGUMENT");
			else
				while(a[l] == x && l != m)
				{
					a[l] = 0;
					l++;
				}
		}
		if (c == 'd')
		{
			scanf("%c%c%c%c%c%c%c%c%c\n", &ch1, &ch2, &ch3, &ch4, &ch5, &ch6, &ch7, &ch8, &ch9);
			v.clear();
			for (int i = 0; i < m; i++)
				if (a[i] != 0)
					v.push_back(a[i]);
			for (int i = 0; i < m; i++)
				a[i] = 0;
			for (int i = 0; i < (int) v.size(); i++)
				a[i] = v[i];
		}
	}
	return 0;
}