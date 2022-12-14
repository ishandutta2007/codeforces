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

int n, k, l, l2, m, ans[300005];
multiset < pair <int, int> > s;

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
		s.insert(mp(k, i));
	}
	m = 0;
	for (int i = 0; i < n; i++)
	{
		l = s.begin()->first;
		l2 = s.begin()->second;
		if (m < l)
			m = l;
		ans[l2] = m++;
		s.erase(s.begin());
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	return 0;
}