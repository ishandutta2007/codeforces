#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
#define offset 1100

int n, m, par[100005], anc[100005][18], lvl[100005], below[100005], u, v;
vector<int> adj[100005];

void dfs(int x)
{
    for (int nex: adj[x]) if(!lvl[nex])
    {
        par[nex] = x;
        lvl[nex] = 1 + lvl[x];
        dfs(nex);
        below[x] += 1 + below[nex];
    }
}

void init()
{
    FOR (i, 1, n) anc[i][0] = par[i];
    FOR (j, 1, 17) FOR (i, 1, n) anc[i][j] = anc[anc[i][j - 1]][j - 1];
}

int lca(int x, int y)
{
    if (lvl[x] > lvl[y]) swap(x, y);
    int tmp = 17;
    while (lvl[x] != lvl[y])
    {
        if (lvl[anc[y][tmp]] >= lvl[x]) y = anc[y][tmp];
        tmp--;
    }
    if (x == y) return x;
    FORD (i, 17, 0) if (anc[x][i] != anc[y][i])
    {
        x = anc[x][i];
        y = anc[y][i];
    }
    return par[x];
}

int query(int x, int y)
{
    if (x == y) return n;
    if (lvl[x] > lvl[y]) swap (x, y);
    int z = lca(x, y);
    if (lvl[x] != lvl[y])
    {
        int gap = lvl[y] + lvl[x] - 2 * lvl[z];
        if (gap & 1) return 0;
        gap /= 2;
        gap --;
        REP (i, 18) if (gap & (1 << i)) y = anc[y][i];
        return below[par[y]] - below[y];
    }
    else
    {
        int gap = lvl[y] - lvl[z] - 1;
        //BUG(gap);
        REP (i, 18) if (gap & (1 << i))
        {
            x = anc[x][i];
            y = anc[y][i];
            //BUG(x);
        }
        //BUG(lvl[z]);
        return n - 2 - below[x] - below[y];
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n - 1)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    par[1] = 1;
    lvl[1] = 1;
    dfs(1);
    init();
    //cout << lca(4, 2); return 0;
    cin >> m;
    while (m--)
    {
        cin >> u >> v;
        cout << query(u, v) << endl;
    }
}