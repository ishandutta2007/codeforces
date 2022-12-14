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

int x, k, t, t1, t2, ans1, ans2, len;
vector <int> v;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &x, &k);
	v.pb(x);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%d%d", &t1, &t2);
			v.pb(t1);
			v.pb(t2);
		}
		else
		{
			scanf("%d", &t1);
			v.pb(t1);
		}
	}
	v.pb(0);
	sort(v.begin(), v.end());
	for (int i = 1; i < (int) v.size(); i++)
	{
		len = v[i] - v[i - 1] - 1;
		ans1 += len;
		ans2 += (len + 1) / 2;		
	}
	printf("%d %d\n", ans2, ans1);
	return 0;
}