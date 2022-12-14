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

int cnt[2];

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int n, k, m;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        cnt[m % 2]++;
    }
    int r = n - k;
    if (r == 0)
    {
        if (cnt[1] % 2 == 1)
            puts("Stannis");
        else
            puts("Daenerys");
        return 0;
    }
    int sec = r / 2;
    int fst = r - sec;
    if (fst >= cnt[0] && k % 2 == 1)
    {
        puts("Stannis");
        return 0;
    }
    if (sec >= cnt[1])
    {
        puts("Daenerys");
        return 0;
    }
    if (sec >= cnt[0] && k % 2 == 0)
    {
        puts("Daenerys");
        return 0;
    }
    if (r % 2 == 0)
    {
        puts("Daenerys");
        return 0;
    }
    puts("Stannis");
    return 0;
}