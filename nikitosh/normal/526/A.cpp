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

int n;
char s[1005];

int main() {
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d\n", &n);
    gets(s);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i + 4 * j < n && s[i] == '*' && s[i + j] == '*' && s[i + 2 * j] == '*' && s[i + 3 * j] == '*' && s[i + 4 * j] == '*')
            {
                puts("yes");
                return 0;
            }
        }
    } 
    puts("no");
    return 0;
}