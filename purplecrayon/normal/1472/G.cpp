#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 110, INF = 1e9+10, MAXA = 62, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m, d[MAXN], best[MAXN];
vector<int> adj[MAXN], one[MAXN];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b);
    }
    fill(d, d+n, 1e9);
    queue<int> q; q.push(0); d[0] = 0;
    while (sz(q)){
        int c=q.front(); q.pop();
        for (auto nxt : adj[c]) if (d[nxt] > d[c]+1) d[nxt] = d[c]+1, q.push(nxt);
    }
    fill(best, best+n, 1e9);
    for (int i = 0; i < n; i++) for (auto j : adj[i]) {
        if (d[i] < d[j]) one[j].push_back(i);
        else best[i] = min(best[i], d[j]);
    }
    vector<int> p(n); iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](auto i, auto j){
        return best[i] < best[j];
    });

    vector<bool> v(n);
    auto push = [&](int a){
        if (v[a]) return;
        q.push(a), v[a]=1;
        while (sz(q)){
            int c=q.front(); q.pop();
            best[c] = best[a];
            for (auto nxt : one[c]) if (!v[nxt]) q.push(nxt), v[nxt]=1;
        }
    };
    for (auto& it : p) push(it);

    for (int i = 0; i < n; i++) cout << min(d[i], best[i]) << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) adj[i].clear(), one[i].clear();
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}