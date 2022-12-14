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

int n, k;
vector <int> b;
vector < pair <int, int> > ans;

int foo (vector <int> b, int k)
{
	vector <int> v;
   	v.clear();
   	v.pb(0);
	for (int i = 1; i < n - 1; i++)
		if (abs(b[i - 1] - b[i]) != 1 || abs(b[i + 1] - b[i]) != 1)
			v.pb(i);	
	v.pb(n - 1);
	int m = (int) v.size();
	if (m > 4 * k + 2)
		return 0;
	if (k == 0)
	{
		if (b[0] == 1)
			return 1;
		return 0;
	}
	for (int i = 0; i < m; i++)
		for (int j = i; j < m; j++)
			{
				vector <int> w = b;
				int k1 = v[i];
				int k2 = v[j];
				for (int g = k1; g <= (k1 + k2) / 2; g++)
					swap(w[g], w[k2 - (g - k1)]);
				if (foo(w, k - 1) == 1)
				{
					if (i != j)
						ans.pb(mp(k1 + 1, k2 + 1));
					if (k == 3)
					{
						printf("%d\n", (int) ans.size());
						for (int i = 0; i < (int) ans.size(); i++)
							printf("%d %d\n", ans[i].first, ans[i].second);
						exit(0);
					}
					return 1;
				}
				//printf("%d %d %d\n", i, j, m); 
			}
	return 0;	
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		b.pb(k);
	}
	if (foo(b, 3) == 1)
		puts("AAA");
	return 0;
}