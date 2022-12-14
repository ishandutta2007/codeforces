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

int n;

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
 	if (!prime(n - 4))
	{
		printf("%d %d\n", 4, n - 4); 		   
 		return 0;
 	}
 	if (!prime(n - 6))
	{
		printf("%d %d\n", 6, n - 6); 		   
 	 		return 0;
 	}
	if (!prime(n - 8))
		printf("%d %d\n", 8, n - 8); 		   
    return 0;
}