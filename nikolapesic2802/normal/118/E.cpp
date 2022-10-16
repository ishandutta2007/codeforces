#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define dec(x, y) fixed << setprecision((y)) << (x)
#define xx first
#define yy second
#define srt(v) sort((v).begin(), (v).end())
#define srtr(v) sort((v).rbegin(), (v).rend())
#define pb push_back
#define popb pop_back
#define sz(a) (int)(a).size()
#define len(a) (int)(a).length()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector<pii> e;
vector<pii> graf[100010];
bool pos[100010], ba[300010];
int Time, in[100010], low[100010];
void dfs(int node, int par) {
    pos[node]=true;
    low[node]=in[node]=++Time;
assert(Time <= n+5);
    for(auto adj:graf[node]) {
        if(adj.xx==par) continue;
        if(pos[adj.xx]) {
            low[node]=min(low[node], in[adj.xx]);
            ba[adj.yy]=(node==e[adj.yy].xx?1:0);
            continue;
        }
        dfs(adj.xx, node);
        low[node]=min(low[node], low[adj.xx]);
        ba[adj.yy]=(node==e[adj.yy].xx?0:1);
        if(low[adj.xx]>in[node]) {
            cout << 0;
            exit(0);
        }
    }
}
int main() {
    ios;
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        graf[u].pb(mp(v, i));
        graf[v].pb(mp(u, i));
        e.pb(mp(u, v));
    }
    dfs(1, -1);
    for(int i=0; i<m; ++i) {
        if(ba[i]) cout << e[i].yy << ' ' << e[i].xx;
        else cout << e[i].xx << ' ' << e[i].yy;
        cout << endl;
    }
    return 0;
}