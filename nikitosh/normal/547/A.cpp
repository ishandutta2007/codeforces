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

const int MAXN = 1e6 + 5;

int m;
LL h[2], a[2], x[2], y[2], fst[2], per[2], P[2];
int last[MAXN + 5];

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d", &m);
    for (int i = 0; i < 2; i++)
    {
        scanf("%I64d%I64d%I64d%I64d", &h[i], &a[i], &x[i], &y[i]);
        int t = 0;
        for (int j = 0; j < m; j++)
            last[j] = -1;
        int cur = h[i];
        int p = -1;
        while (1)
        {
            last[cur] = t++;
            cur = (cur * 1ll * x[i] + y[i]) % m;
            if (last[cur] != -1)
            {
                p = t - last[cur];
                break;
            } 
        }
        if (last[a[i]] == -1)
        {
            puts("-1");
            return 0;
        }
        fst[i] = last[a[i]];
        if (last[a[i]] < t - p)
            per[i] = 0;
        else
            per[i] = 1;
        P[i] = p;
    } 
    if (per[0] == 0)
    {
        if (per[1] == 0)
        {
            if (fst[0] == fst[1])
                printf("%I64d\n", fst[0]);
            else
                puts("-1");
            return 0;
        }
        if (fst[0] >= fst[1] && (fst[0] % P[1] == fst[1] % P[1]))
            printf("%I64d\n", fst[0]);
        else
            puts("-1");
        return 0;
    }
    if (per[1] == 0)
    {
        if (fst[1] >= fst[0] && (fst[1] % P[0] == fst[0] % P[0]))
            printf("%I64d\n", fst[1]);
        else
            puts("-1");
        return 0;
    }
    for (int i = 0; i < MAXN; i++)
    {
        if (fst[0] >= fst[1] && (fst[0] % P[1] == fst[1] % P[1]))
        {
            printf("%I64d\n", fst[0]);
            return 0;
        }
        fst[0] += P[0];
    }
    puts("-1");
    return 0;
}