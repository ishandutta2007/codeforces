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

int n, u, v, col[200005], vst[200005], tot, ans;
vector<int> adj[200005], adj2[200005];
queue<pair<int, int> > pending;
queue<int> q;

void dfs(int newx, int x)
{
    vst[x] = 1;
    for (int nex: adj[x])
    {
        if (!vst[nex])
        {
            if (col[nex] == col[x]) dfs(newx, nex);
            else
            {
                tot++;
                //cout << tot << ' ' << newx << endl;
                adj2[tot].pb(newx);
                adj2[newx].pb(tot);
                pending.push({tot, nex});
            }
        }
    }
}

int bfs(int x)
{
    reset(vst, -1);
    int tmp = 1;
    while(!q.empty()) q.pop();
    q.push(x);
    vst[x] = 0;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        tmp = u;
        for (int nex: adj2[u]) if (vst[nex] == -1)
        {
            vst[nex] = 1 + vst[u];
            q.push(nex);
        }
    }
    return tmp;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    FOR (i, 1, n) cin >> col[i];
    FOR (i, 2, n)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    tot = 1;
    pending.push({1, 1});
    while (!pending.empty())
    {
        auto pp = pending.front();
        pending.pop();
        dfs(pp.first, pp.second);
    }
    //BUG(adj2[1].size());
    //BUG(tot);
    v = bfs(1);
    //BUG(v);
    ans = bfs(v);
    cout << (1 + vst[ans]) / 2;
}