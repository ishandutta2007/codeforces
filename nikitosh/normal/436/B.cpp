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

int n, m, k, cnt;
char s[2005][2005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d%d\n", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		gets(s[i]);
	}
	for (int i = 0; i < m; i++)
	{
		cnt = 0;
		if (s[0][i] != '.')
			cnt++;
		for (int j = 1; j < n; j++)
		{
			if (s[0][i] == 'D')
				cnt++;
			if (2 * j < n && s[2 * j][i] == 'U')
				cnt++;
			if (i - j >= 0 && s[j][i - j] == 'R')
				cnt++;
			if (i + j < m && s[j][i + j] == 'L')
				cnt++;
		}
		printf("%d ", cnt);
	}
	return 0;
}