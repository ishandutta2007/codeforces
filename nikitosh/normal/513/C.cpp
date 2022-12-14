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

int n, l[10], r[10];
vector <int> v;
double sum;

LL foo (int k, vector <int> v)
{
	LL ans = 1;
	sort(v.begin(), v.end());
	int it = 0;
	for (int g = 0; g < n; g++)
	{
	    if (it == (int) v.size() || g != v[it])
 		{
 			if (k > r[g])
				ans *= (r[g] - l[g] + 1);
			else
				ans *= max(0, k - l[g] + 1);
 		}
 		else
 			it++;
 	}	
 	return ans;
}

LL check (int k, vector <int> v)
{
	return foo(k, v) - foo(k - 1, v);
}

int main()
{
#ifdef LOCAL
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &l[i], &r[i]);
	for (int mask = 1; mask < (1 << n); mask++)
	{
		v.clear();
		for (int j = 0; j < n; j++)
			if ((mask >> j) & 1)
				v.pb(j);
		if (v.size() == 1)
		{
			for (int j = 1; j <= 10000; j++)
				sum += double(check(j, v)) * max(0, r[v[0]] - max(l[v[0]], j + 1) + 1) * double(j);	
		}
		else
		{
			int minR = 1e9, maxL = -1e9;
			for (int j = 0; j < (int) v.size(); j++)
				minR = min(minR, r[v[j]]), maxL = max(maxL, l[v[j]]);
			for (int j = 1; j <= 10000; j++)
			{
				LL ss = foo(j - 1, v);
				if (j >= maxL && j <= minR)
					sum += double(ss) * (double) j ;	
			}
		}
	}
	for (int i = 0; i < n; i++)
		sum /= (double) (r[i] - l[i] + 1);
	printf("%.20lf\n", sum);
    return 0;
}