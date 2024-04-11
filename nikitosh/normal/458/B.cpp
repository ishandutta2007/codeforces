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

int n, m, a[100005], b[100005];
long long sum, ans;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int j = 0; j < m; j++)
		scanf("%d", &b[j]);
	sort(a, a + n);
	sort(b, b + m);
	if (a[n - 1] >= b[m - 1])
	{
		sum = 0;
		for (int i = 0; i < m; i++)
			sum += b[i];
		ans = sum;
		for (int i = 0; i < n - 1; i++)
			ans += min(sum, (long long) a[i]);
		printf("%I64d\n", ans);
	} 
    else
    {
		sum = 0;
		for (int i = 0; i < n; i++)
			sum += a[i];
		ans = sum;
		for (int i = 0; i < m - 1; i++)
			ans += min(sum, (long long) b[i]);
		printf("%I64d\n", ans);

    }
    return 0;
}