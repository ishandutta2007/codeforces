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

int n, m, vst[1111], ans, u, v;
vector<int> adj[1111];
queue<int> q;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    if (m != n - 1)
    {
        cout << "no";
        return 0;
    }
    REP (i, m)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    q.push(1);
    vst[1] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        //BUG(u);
        ans++;
        for (int nex: adj[u]) if (!vst[nex])
        {
            vst[nex] = 1;
            q.push(nex);
        }
    }
    cout << (ans == n ? "yes" : "no");
}