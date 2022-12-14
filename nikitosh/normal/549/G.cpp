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

const int MAXN = 4e5 + 5;

int a[MAXN];
int b[MAXN];

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);    
        b[i] = a[i] - (n - 1 - i);
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++)
        b[i] += (n - 1 - i);
    for (int i = 0; i < n - 1; i++)
        if (b[i] > b[i + 1])
        {
            puts(":(");
            return 0;
        }
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    return 0;
}