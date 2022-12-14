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

const int MAXN = 5e5 + 5;
const int MAXSZ = 2e5;

int last[MAXN + 5];
int a[MAXSZ];
vector <int> c[MAXSZ];
int ans[MAXN + 5], was[MAXN + 5];

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    for (int i = 2; i <= MAXN; i++)
    {
        if (last[i] == 0)
        {
            for (int j = i; j <= MAXN; j += i)
                if (last[j] == 0)
                    last[j] = i;
        }
    }
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        int k = a[i];
        while (k != 1)
        {
            c[i].pb(last[k]);
            k /= last[k];
        }
        sort(c[i].begin(), c[i].end());
        c[i].resize(unique(c[i].begin(), c[i].end()) - c[i].begin());
    } 
    LL curAns = 0;
    int curCnt = 0;
    for (int qq = 0; qq < q; qq++)
    {
        int t;
        scanf("%d", &t);
        t--;
        vector <int> &v = c[t];
        LL res = 0;
        if (was[t])
        {
            for (int i = 0; i < (1 << ((int) v.size())); i++)
            {
                int cur = 1;
                for (int j = 0; j < (int) v.size(); j++)
                    if ((i >> j) & 1)
                        cur *= v[j];
                ans[cur]--;
            }
            curCnt--;
        }
        for (int i = 1; i < (1 << ((int) v.size())); i++)
        {
            int cur = 1, cnt = 0;
            for (int j = 0; j < (int) v.size(); j++)
                if ((i >> j) & 1)
                    cur *= v[j], cnt++;
            if (cnt & 1)
                res += ans[cur];
            else
                res -= ans[cur];                            
        }
        res = curCnt - res;
        if (was[t])
            curAns -= res;
        else
            curAns += res;
        if (!was[t])
        {
            for (int i = 0; i < (1 << ((int) v.size())); i++)
            {
                int cur = 1;
                for (int j = 0; j < (int) v.size(); j++)
                    if ((i >> j) & 1)
                        cur *= v[j];
                ans[cur]++;
            }
            curCnt++;
        }
        was[t] ^= 1;
        printf("%I64d\n", curAns);
    }
    return 0;
}