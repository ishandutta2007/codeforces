#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
 
using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif
 
#define FNAME "1"

int n, sz, ans, cnt, tmp, used[100005];
vector <int> p, v, z;

bool prime (int k)
{
	for (int i = 2; i * i <= k; i++)
		if (k % i == 0)
			return 0;
	return 1;
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		if (prime(i))
			p.pb(i);
	sz = (int) p.size();
	for (int i = sz - 1; i >= 0; i--)
	{
		cnt = 0;
		for (int j = 0; j < n / p[i]; j++)
			if (used[p[i] * (j + 1)] == 0)
			{
				cnt++;
				used[p[i] * (j + 1)] = 1;
			}
		ans += cnt / 2;
		if (cnt % 2 == 1 && cnt > 1)
			tmp++;
	}
	ans += tmp / 2;
	printf("%d\n", ans);
	for (int i = 0; i <= n; i++)
		used[i] = 0;
	for (int i = sz - 1; i >= 0; i--)
	{       
		z.clear();
		cnt = 0;
		for (int j = 0; j < n / p[i]; j++)
			if (used[p[i] * (j + 1)] == 0)
			{
				cnt++;
				used[p[i] * (j + 1)] = 1;
				z.pb(p[i] * (j + 1));
			}
		if (cnt % 2 == 0)
		{
			for (int j = 0; j < (int) z.size(); j += 2)
				printf("%d %d\n", z[j], z[j + 1]);
		}
		else if (cnt > 1)
		{
		    printf("%d %d\n", z[0], z[2]);
			for (int j = 3; j < (int) z.size(); j += 2)
				printf("%d %d\n", z[j], z[j + 1]);
			v.pb(z[1]);
		}
	}	
	for (int i = 1; i < (int) v.size(); i += 2)
		printf("%d %d\n", v[i - 1], v[i]);
    return 0;
}