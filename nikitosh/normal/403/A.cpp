#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME ""
#define FILE 0

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

int t, n, p, a[40][40];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &t);
	for (int g = 0; g < t; g++)
	{
		scanf("%d%d", &n, &p);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = 0;
		int l = 5 + n % 5;
		if (l == 5)
		{
			a[0][1] = 1;
			a[0][2] = 1;
			a[0][3] = 1;
			a[0][4] = 1;
			a[1][2] = 1;
			a[1][3] = 1;
			a[1][4] = 1;
			a[2][3] = 1;
			a[2][4] = 1;
			a[3][4] = 1;
		}
		if (l == 6)
		{
			a[0][1] = 1;
			a[0][2] = 1;
			a[0][3] = 1;
			a[0][4] = 1;
			a[1][2] = 1;
			a[1][4] = 1;
			a[1][5] = 1;
			a[2][3] = 1;
			a[2][5] = 1;
			a[3][4] = 1;
			a[3][5] = 1;
			a[4][5] = 1;
		}
		if (l == 7)
		{
			a[0][1] = 1;
			a[0][2] = 1;
			a[0][3] = 1;
			a[0][4] = 1;
			a[1][2] = 1;
			a[1][3] = 1;
			a[1][4] = 1;
			a[2][5] = 1;
			a[2][6] = 1;
			a[3][5] = 1;
			a[3][6] = 1;
			a[4][5] = 1;
			a[4][6] = 1;
			a[5][6] = 1;
		}
		if (l == 8)
		{
			a[0][1] = 1;
			a[0][2] = 1;
			a[0][3] = 1;
			a[0][4] = 1;
			a[1][2] = 1;
			a[1][3] = 1;
			a[1][4] = 1;
			a[2][5] = 1;
			a[2][6] = 1;
			a[3][5] = 1;
			a[3][7] = 1;
			a[4][6] = 1;
			a[4][7] = 1;
			a[5][6] = 1;
			a[5][7] = 1;
			a[6][7] = 1;
		}
		if (l == 9)
		{
			a[0][1] = 1;
			a[0][2] = 1;
			a[0][3] = 1;
			a[0][4] = 1;
			a[1][2] = 1;
			a[1][3] = 1;
			a[1][4] = 1;
			a[2][3] = 1;
			a[2][6] = 1;
			a[3][5] = 1;
			a[4][7] = 1;
			a[4][8] = 1;
			a[5][6] = 1;
			a[5][7] = 1;
			a[5][8] = 1;
			a[6][7] = 1;
			a[6][8] = 1;
			a[7][8] = 1;
		}
		while (l < n)
		{
			a[l][l + 1] = 1;
			a[l][l + 2] = 1;
			a[l][l + 3] = 1;
			a[l][l + 4] = 1;
			a[l + 1][l + 2] = 1;
			a[l + 1][l + 3] = 1;
			a[l + 1][l + 4] = 1;
			a[l + 2][l + 3] = 1;
			a[l + 2][l + 4] = 1;
			a[l + 3][l + 4] = 1;
			l += 5;
		}
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (p != 0 && a[i][j] == 0)
				{
					a[i][j] = 1;
					p--;
				}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (a[i][j] == 1)
					printf("%d %d\n", i + 1, j + 1);
	}
	return 0;
}