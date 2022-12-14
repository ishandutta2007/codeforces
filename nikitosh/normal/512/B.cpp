#define FNAME "test"

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornr(i, n) for (int i = int(n - 1); i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)
#define forba(i, b, a) for (int i = b - 1; i >= a; i--)

#ifndef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

const int INF = 1e9;

int n, a[305], c[305], k, l, d[100005], ans, mask;
vector <int> v[305];
map <int, int> used[305];

int main()
{
#ifdef LOCAL
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		k = a[i];
		for (int j = 2; j * j <= k; j++)
			if (k % j == 0)
			{
				v[i].pb(j);
				while (k % j == 0)
					k /= j;
			}
		if (k != 1)
			v[i].pb(k);
		for (int j = 0; j < (int) v[i].size(); j++)
			used[i][v[i][j]] = 1;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	ans = INF;
	for (int i = 0; i < n; i++)
	{
		l = v[i].size();
		for (int j = 0; j < (1 << l); j++)
			d[j] = INF;
		d[(1 << l) - 1] = c[i];
		for (int j = 0; j < i; j++)
		{
			mask = 0;
			for (int k = 0; k < l; k++)
				if (used[j][v[i][k]] == 1)
					mask |= (1 << k);
			//printf("%d %d %d\n", i + 1, j + 1, mask);
			for (int k = 0; k < (1 << l); k++)
				d[k & mask] = min(d[k & mask], d[k] + c[j]);
		}
		ans = min(ans, d[0]);
	}
	if (ans == INF)
		puts("-1");
	else
		printf("%d\n", ans);
    return 0;
}