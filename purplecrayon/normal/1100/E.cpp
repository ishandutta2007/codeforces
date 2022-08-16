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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int n, m, deg[MAXN], loc[MAXN];
vector<ar<int, 2>> adj[MAXN];
ar<int, 3> ed[MAXN];
vector<int> top;

bool v(int x) {
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < m; i++) if (ed[i][2] > x) deg[ed[i][1]]++;

    top.clear();
    queue<int> q;
    for (int i = 0; i < n; i++) if (!deg[i]) q.push(i);
    while (sz(q)) {
        int c=q.front(); q.pop();
        top.push_back(c);

        for (auto nxt : adj[c]) if (nxt[1] > x) {
            if ((--deg[nxt[0]]) == 0) q.push(nxt[0]);
        }
    }
    return sz(top) == n;
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c, --a, --b;
        adj[a].push_back({b, c});
        ed[i] = {a, b, c};
    }

    top.reserve(n);
    int lo=-1, hi=1e9+10, mid=(lo+hi)/2;
    while (lo < mid && mid < hi) {
        if (v(mid)) hi = mid;
        else lo = mid;
        mid = (lo+hi)/2;
    }
    bool b = v(hi); assert(b);
    assert(sz(top) == n);

    for (int i = 0; i < n; i++) loc[top[i]] = i;
    vector<int> ans;
    for (int i = 0; i < m; i++) if (ed[i][2] <= hi && loc[ed[i][0]] > loc[ed[i][1]]) ans.push_back(i);

    cout << hi << ' ' << sz(ans) << '\n';
    for (int i : ans) cout << i+1 << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}