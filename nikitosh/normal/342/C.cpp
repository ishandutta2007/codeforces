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

int r, h, m, d, ans;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &r, &h);
	m = h / r;
	ans = 2 * m;
	d = h % r;
	if (2 * d >= r)
	{
		ans += 2;
		if (2 * (double) d >= sqrt(3) * (double) r)
		ans++;
	}
	else
		ans++;
		printf("%d\n", ans);
	return 0;
}