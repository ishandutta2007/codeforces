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

const int MAXN = 1005;

int col[MAXN], used[MAXN], was[MAXN];
vector <int> c[MAXN], lst[MAXN], comp[MAXN];

void dfs(int v, int color)
{
    was[v] = 1;
    comp[color].pb(v);
    for (int i = 0; i < (int) c[v].size(); i++)
        if (was[c[v][i]] == 0)
            dfs(c[v][i], color);
}

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
    int color = 0;
    for (int i = 0; i < n; i++)
        if (was[i] == 0)
            dfs(i, color++);
    int ANS = 0;
    for (int cur = 0; cur < color; cur++)
    {
    int Max = -1;
    for (int i = 0; i < (int) comp[cur].size(); i++)
    {
        bool ok = 1;
        for (int j = 0; j < (int) comp[cur].size(); j++)
            col[comp[cur][j]] = -1;
        col[comp[cur][i]] = 0;
        lst[0].clear();
        lst[0].pb(comp[cur][i]);
        int cnt = comp[cur].size() - 1;
        int j = 0;
        //printf("start = %d\n", comp[cur][i]);
        while(1)
        {
            lst[j + 1].clear();
            //for (int k = 0; k < (int) lst[j].size(); k++)
            //    printf("%d ", lst[j][k]);
            //puts("");
            //for (int g = 0; g < n; g++)
            //    printf("%d", used[g]);
            //puts("");
            for (int g = 0; g < (int) lst[j].size(); g++)
            {
                int v = lst[j][g];
                for (int k = 0; k < (int) c[v].size(); k++)
                {
                    //printf("%d %d\n", v, c[v][k]);
                    if (used[c[v][k]] == 0 && col[c[v][k]] != -1 && col[c[v][k]] != j - 1)
                    {
                        //printf("FAIL %d %d\n", c[v][k], col[c[v][k]]);
                        ok = 0;
                        break;
                    } 
                    if (col[c[v][k]] == -1)
                    {
                        if (used[c[v][k]] == 0)
                        {
                            lst[j + 1].pb(c[v][k]);
                            cnt--;
                            col[c[v][k]] = j + 1;
                        }
                        used[c[v][k]] = 1;
                    }
                }
                if (ok == 0)
                    break;
            } 
            if (ok == 0)
                break;
            for (int g = 0; g < (int) lst[j].size(); g++)
            {
                int v = lst[j][g];
                for (int k = 0; k < (int) c[v].size(); k++)
                {
                    used[c[v][k]] = 0;    
                }
                if (ok == 0)
                    break;
            } 
            j++;
            if (lst[j].size() == 0)
            {
                j--;
                break;
            }
            //printf("jjj = %d\n", j);
        }
        if (ok)
        {
            Max = max(Max, j);
        }
        //printf("Max = %d\n", Max);
        for (int g = 0; g < (int) comp[cur].size(); g++)
            used[comp[cur][g]] = 0;
    }
    if (Max == -1)
    {
        puts("-1");
        return 0;
    }
    ANS += Max;
    }
    printf("%d\n", ANS);
    return 0;
}