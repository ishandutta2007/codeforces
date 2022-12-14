#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#define FNAME "1"

char s[10005];
int n;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%s", s);
	n = strlen(s);
	if (s[0] == '9')
		printf("9");
	else
		printf("%d", min(s[0] - '0', 9 - (s[0] - '0')));
	for (int i = 1; i < n; i++)
		printf("%d", min(s[i] - '0', 9 - (s[i] - '0')));
		    
    return 0;
}