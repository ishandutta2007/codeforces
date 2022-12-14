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

int n, a[100005], d[100005][3], l;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	d[n - 1][0] = 1;
	d[n - 1][1] = 1;
	d[n - 1][2] = 1;
	l = 1;
	for (int i = n - 2; i >= 0; i--)
	{
	    if (a[i] < a[i + 1])
	    	d[i][0] = d[i + 1][0] + 1;
	    else
	    	d[i][0] = 1;
	    d[i][2] = d[i + 1][0] + 1;
	    d[i][1] = 2;
		if (a[i] < a[i + 1])
	    	d[i][1] = max(d[i][1], d[i + 1][1] + 1);
		if (i != n - 2 && a[i] < a[i + 2] - 1)
			d[i][1] = max(d[i][1], d[i + 2][0] + 2);
   		l = max(l, max(d[i][0], max(d[i][1], d[i][2])));
   	} 
   	printf("%d\n", l);
    return 0;
}