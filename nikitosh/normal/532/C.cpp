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
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif

#define FNAME "1"

int x_1, y_1, x_2, y_2;

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
    if (x_1 + y_1 <= max(x_2, y_2) || (x_1 <= x_2 && y_1 <= y_2))
    {
        puts("Polycarp");
        return 0;
    } 
    puts("Vasiliy");
    return 0;
}