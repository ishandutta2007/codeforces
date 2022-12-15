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

struct Edge{
    long long u, v, z;
    bool used;
    Edge(long long a, long long b, long long c) {
        u = a; v = b; z = c;
        used = false;
    }
    Edge() {
        used = false;
    }
};

long long n, m, x, y, z, dis[100005], edgeto[100005];
Edge edges[100005];
vector<pair<long long, int> > adj[100005];
set<pair<long long, long long> > s;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REP (i, m)
    {
        cin >> x >> y >> z;
        edges[i] = Edge(x, y, z);
        adj[x].pb({y, i});
        adj[y].pb({x, i});
    }
    reset(dis, 55);
    dis[1] = 0;
    s.insert({0, 1});
    while (s.size())
    {
        auto it = s.begin();
        z = it -> first;
        x = it -> second;
        s.erase(it);
        if (z > dis[x]) continue;
        for (auto p: adj[x])
        {
            y = p.first;
            Edge tmp = edges[p.second];
            if (dis[y] > dis[x] + 1e6 + 1 - tmp.z)
            {
                dis[y] = dis[x] + 1e6 + 1 - tmp.z;
                s.insert({dis[y], y});
                edgeto[y] = p.second;
            }
        }
    }
    long long x = n;
    while (x != 1)
    {
        edges[edgeto[x]].used = true;
        if (edges[edgeto[x]].u == x) x = edges[edgeto[x]].v;
        else x = edges[edgeto[x]].u;
    }
    //BUG(dis[n]);
    int cnt = 0;
    REP (i, m) if (edges[i].used && !edges[i].z || !edges[i].used && edges[i].z) cnt++;
    cout << cnt << endl;
    REP (i, m)
    {
        if (edges[i].used && !edges[i].z) cout << edges[i].u << ' ' << edges[i].v << ' ' << 1 << endl;
        if (!edges[i].used && edges[i].z) cout << edges[i].u << ' ' << edges[i].v << ' ' << 0 << endl;
    }
    //BUG(edges)
}