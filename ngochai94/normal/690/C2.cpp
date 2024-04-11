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

int n, m, vst[100005], ans, u, v;
vector<int> adj[100005];
queue<int> q;

int bfs(int x)
{
    while (!q.empty()) q.pop();
    int ret = x;
    q.push(x);
    reset(vst, 0);
    vst[x] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int nex: adj[u]) if (!vst[nex])
        {
            vst[nex] = 1 + vst[u];
            q.push(nex);
        }
        ret = u;
    }
    return ret;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REP (i, m)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int x = bfs(1);
    x = bfs(x);
    cout << vst[x] - 1;
}