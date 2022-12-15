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

int n, u, v, lvl[500005];
vector<int> adj[500005], ans;

void dfs(int x)
{
    for (int nex: adj[x]) if(!lvl[nex])
    {
        lvl[nex] = 1 + lvl[x];
        dfs(nex);
    }
    if (adj[x].size() == 1) ans.pb(lvl[x]);
}

int main() {
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
    lvl[1] = 1;
    int res = 0;
    for (int i: adj[1])
    {
        ans.clear();
        lvl[i] = 1;
        dfs(i);
        sort(ans.begin(), ans.end());
        int tmp = 0;
        for (int j: ans) tmp = max(tmp + 1, j);
        res = max(res, tmp);
    }
    cout << res;
}