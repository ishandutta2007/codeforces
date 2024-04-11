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

#define FNAME "1"
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

int n, m, l, r, a[10], x[100005], y[100005], z[100005];
char s[100005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	gets(s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
			z[i] = z[i - 1];
		}
		if (s[i] == 'x')
			x[i]++;
		if (s[i] == 'y')
			y[i]++;
		if (s[i] == 'z')
			z[i]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l, &r);
		l--;
		r--;
		if (r - l < 2)
		{
			puts("YES");
			continue;
		}
        a[0] = x[r];
		if (l != 0)
			a[0] -= x[l - 1];
		a[1] = y[r];
		if (l != 0)
			a[1] -= y[l - 1];
		a[2] = z[r];
		if (l != 0)
			a[2] -= z[l - 1];
		sort(a, a + 3);
		//printf("%d %d %d\n", a[0], a[1], a[2]);
		if (a[0] + 1 < a[2]) 
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}