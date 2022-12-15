#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000003
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, u, v, tot, ind, par[200005], rep[200005];
vector<pair<int, int> > adj[200005];
vector<int> ans[200005];
queue<int> q;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    FOR (i, 1, n - 1)
    {
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u ,i});
    }
    q.push(1);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        //BUG(u);
        int cur = 1;
        int forbid = rep[par[u]];
        if (cur == forbid) cur++;
        for (auto p: adj[u]) if (p._2 != par[u])
        {
            //cout << p._1 << ' ' << p._2 << endl;
            tot = max(tot, cur);
            par[p._1] = p._2;
            rep[p._2] = cur;
            ans[cur].pb(p._2);
            q.push(p._1);
            cur++;
            if (cur == forbid) cur++;
        }
    }
    //FOR (i, 1, n - 1) cout << i << ' ' << rep[i] << endl;
    cout << tot << endl;
    FOR (i, 1, tot)
    {
        cout << ans[i].size();
        for (int ii: ans[i]) cout << ' ' << ii;
        cout << endl;
    }
}