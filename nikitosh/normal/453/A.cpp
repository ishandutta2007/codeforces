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

int n, m;
double ans;

double binpow (double k, int n)
{
	if (n == 0)
		return 1;
   	double kk = binpow(k, n / 2);
   	if (n % 2 == 0)
   		return kk * kk;
	else
		return k * kk * kk;
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d", &m, &n);
	ans = m;
	for (int i = 1; i < m; i++)
	{
		ans -= binpow(i / (double) m, n);
   	} 
   	printf("%.20lf\n", ans);
    return 0;
}