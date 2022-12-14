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

int n, a[100005], used[100005];
long long d[100005];

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		used[a[i]]++;
   	} 
    d[1] = used[1];
    d[2] = max(used[1], 2 * used[2]);
    for (int i = 3; i <= 100000; i++)
   	{
   		d[i] = max(d[i - 2] + (long long) i * used[i], d[i - 3] + (long long) (i - 1) * used[i - 1]);
   	} 
   	printf("%I64d\n", d[100000]);
    return 0;
}