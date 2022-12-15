#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define pb push_back

long long n, m, k, u, v, x, ans, dis[100005], vst[100005];
vector<pair<long long, long long> > adj[100005];
set<pair<long long, long long> > s;
bool byTrain[100005];

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    reset(dis, 55);
    while (m--) {
        cin >> u >> v >> x;
        adj[u].pb({v, x});
        adj[v].pb({u, x});
    }
    reset(byTrain, 0);
    while (k--) {
        cin >> u >> x;
        if (byTrain[u]) ans++;
        byTrain[u] = true;
        dis[u] = min(dis[u], x);
        s.insert({x, u});
    }
    s.insert({0, 1});
    while (!s.empty()) {
        auto it = s.begin();
        x = it -> first;
        u = it -> second;
        s.erase(it);
        if (vst[u]) continue;
        vst[u] = 1;
        for (auto p: adj[u]) {
            if (p.second + x <= dis[p.first]) {
                if (byTrain[p.first]) {
                    byTrain[p.first] = false;
                    ans++;
                }
                dis[p.first] = x + p.second;
                s.insert({dis[p.first], p.first});
            }
        }
    }
    cout << ans;
}