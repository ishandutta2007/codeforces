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

const int MAXN = 3005, INF = 1e9;

int s[5], t[5], l[5], used[MAXN], q[MAXN], d[MAXN][MAXN];
vector <int> c[MAXN];

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int k, l;
        scanf("%d%d", &k, &l);
        k--;
        l--;
        c[k].pb(l);
        c[l].pb(k);
    } 
    for (int i = 0; i < 2; i++)
    {
        scanf("%d%d%d", &s[i], &t[i], &l[i]);
        s[i]--;
        t[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        int head = 0, tail = 0;
        q[tail++] = i;
        for (int j = 0; j < n; j++)
            d[i][j] = INF, used[j] = 0;
        d[i][i] = 0;
        used[i] = 1;
        while (tail > head)
        {
            int v = q[head++];
            for (int j = 0; j < (int) c[v].size(); j++)
            {   
                int u = c[v][j];
                if (used[u] == 0)
                {
                    q[tail++] = u;
                    used[u] = 1;
                    d[i][u] = d[i][v] + 1;
                }
            }
        }
    }
    for (int i = 0; i < 2; i++)
        if (d[s[i]][t[i]] > l[i])
        {
            puts("-1");
            return 0;
        }
    int ans = d[s[0]][t[0]] + d[s[1]][t[1]];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int ok = 1;
            int sumDist = 0;
            for (int k = 0; k < 2; k++)
            {
                int dist = d[i][s[k]] + d[i][j] + d[j][t[k]];
                if (dist > l[k])
                    ok = 0;
                sumDist += dist;
            }
            if (ok)
                ans = min(ans, sumDist - d[i][j]);
            //printf("%d %d %d %d\n", i, j, sumDist, ok);
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int ok = 1;
            int sumDist = 0;
            
            int dist1 = d[i][s[0]] + d[i][j] + d[j][t[0]];
            if (dist1 > l[0])
                    ok = 0;
            sumDist += dist1;
            
            int dist2 = d[j][s[1]] + d[i][j] + d[i][t[1]];
            if (dist2 > l[1])
                    ok = 0;
            sumDist += dist2;
            
            if (ok)
                ans = min(ans, sumDist - d[i][j]);
            //printf("%d %d %d %d\n", i, j, sumDist, ok);
            //printf("%d %d %d\n", i, j, ans);
        }


    printf("%d\n", m - ans);
    return 0;
}