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

int n, it1, it2, ans[105], sz;
LL m, cnt;

int main()
{
#ifdef LOCAL
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
#endif

	scanf("%d%I64d", &n, &m);
	cnt = 1ll << (n - 1);
	it1 = 0;
	it2 = n - 1;
	while (it1 <= it2)
	{
		if (m <= cnt / 2)
		{
			ans[it1++] = sz++;
		}	
		else
		{
			ans[it2--] = sz++;
			m -= cnt / 2;
		}
		cnt /= 2;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i] + 1);
    return 0;
}