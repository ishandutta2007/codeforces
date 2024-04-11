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

int n, m;
vector <int> v;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	if (n >= m)
	{
		if (n > m + 1)
		{
			puts("-1");
			return 0;
		}
		if (n > m)
			printf("0");
		for (int i = 0; i < m; i++)
			printf("10");
	}
	else
	{
		v.pb(1);
		m--;
		if (n < m)
		{
			v.pb(1);
			m--;
		}
		while(n < m && n > 0)
		{
			v.pb(0);
			v.pb(1);
			v.pb(1);
			n--;
			m -= 2;
		}
		if (n == 0 && m > 0)
		{
			puts("-1");
			return 0;	
		}
		for (int i = 0; i < n; i++)
			v.pb(0), v.pb(1);
		for (int i = 0; i < (int) v.size(); i++)
			printf("%d", v[i]);
	}
	return 0;
}