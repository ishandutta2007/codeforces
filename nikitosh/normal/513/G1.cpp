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

int n, k, a[10], b[10], cnt;
double C;
pair <int, int> d[10];

void gen (int l)
{
	if (l == k)
	{
		for (int i = 0; i < n; i++)
			b[i] = a[i];
		for (int j = 0; j < k; j++)
			for (int i = d[j].first; i <= (d[j].second + d[j].first) / 2; i++)
				swap(b[i], b[d[j].second - (i - d[j].first)]);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (b[i] > b[j])
					cnt++;
		return;
	}
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			d[l] = mp(i, j);
			gen(l + 1);
		}
}

int main()
{
#ifdef LOCAL
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	gen(0);
	C = cnt;
	for (int i = 0; i < k; i++)
		C = (2 * C / (double) (n * (n + 1)));
	printf("%.20lf\n", C);
    return 0;
}