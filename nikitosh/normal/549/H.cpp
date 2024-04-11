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

const long double EPS = 1e-18;

long double a[10], b[10];

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    long double L = 0, R = 1e18;
    long double det = a[0] * a[3] - a[1] * a[2];
    for (int k = 0; k < 21000; k++)
    {
        long double M = (L + R) / 2;
        bool ok = 0;
        for (int mask = 0; mask < 16; mask++)
        {
            for (int j = 0; j < 4; j++)
            {
                b[j] = a[j] - M;
                if ((mask >> j) & 1)
                    b[j] += 2 * M;
            }
            long double det2 = b[0] * b[3] - b[1] * b[2];
            if (det * det2 <= EPS)
                ok = 1;
        } 
        if (ok)
            R = M;
        else
            L = M;
    } 
    printf("%.20f\n", (double) R);
    return 0;
}