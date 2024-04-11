
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define pb                    push_back
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))
#define eprintf(...)          fprintf(stderr, __VA_ARGS__)
#define endl                  "\n"

typedef  long long int            ll;
typedef  pair<int,int> 	          ii;
typedef  vector<int> 	          vi;
typedef  vector<string> 	      vs;
typedef  vector<char>	          vc;
#define sf                    scanf
#define pf                    printf
 
#define sf1(a)                scanf("%d", &a)
 
#define sf1ll(a)              scanf("%I64d", &a)

 
void check_time()
{
#ifdef the_badcoder
    eprintf("%.5lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
 
const int res = 1e5 + 50;
const ll mod = 1e9 + 7;
 
int n, sum, total, ans, dp[res];
ii a[res];
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    sf1( n );
 
    for( int i = 0; i < n; i++ )
    {
        sf1( a[i].ff );
        a[i].ss = i;
    }
 
    sort( a, a + n );
 
    for( int i = 0; i < n; i++ )
    {
        if( a[i].ss > ans ){
            ans = a[i].ss;
        }
        dp[ a[i].ss ] = ans - a[i].ss - 1;
    }
 
    for( int i = 0; i < n; i++ )
    {
        cout << dp[i] << space;
    }
}