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

LL C, Hr, Hb, Wr, Wb, Max;

int main() {
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%I64d%I64d%I64d%I64d%I64d", &C, &Hr, &Hb, &Wr, &Wb);
    if (Wr < Wb)
    {
        swap(Wr, Wb);
        swap(Hr, Hb);
    }
    if (Wr >= 100)
    {
        for (LL i = 0; i * Wr <= C; i++)
        {
            LL l = (C - (i * Wr)) / Wb;
            Max = max(Max, i * Hr + l * Hb);
        }
        printf("%I64d\n", Max);
        return 0;
    }
    if (Hr * Wb < Wr * Hb)
    {
        swap(Wr, Wb);
        swap(Hr, Hb);
    }
    LL s = C / Wr;
    for (LL i = s; i >= max(0ll, s - 1000000); i--)
    {
        LL l = (C - (i * Wr)) / Wb;
        Max = max(Max, i * Hr + l * Hb);
    }
    printf("%I64d\n", Max);
    return 0;
}