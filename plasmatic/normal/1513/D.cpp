// ./d-gcd-and-mst.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;
using T = tuple<int, int, int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

struct DSU {
    vector<int> dsu;
    void init(int N) {
        dsu.resize(N + 1);
        iota(dsu.begin(), dsu.end(), 0);
    }
    int rt(int x) { return dsu[x] == x ? x : dsu[x] = rt(dsu[x]); }
    void merge(int x, int y) { // x -> y
        dsu[rt(x)] = rt(y); }
    bool same(int x, int y) { return rt(x) == rt(y); }
};

const int MN = 2e5 + 1;
int N, P,
    A[MN];

void solve() {
    cin >> N >> P;
    vector<pii> vals;
    for (auto i = 0; i < N; i++) {
        cin >> A[i];
        vals.emplace_back(A[i], i);
    }

    vector<T> es;
    for (auto i = 0; i < N-1; i++) es.emplace_back(P, i, i+1);

    sort(vals.begin(), vals.end());
    vector<bool> vis(N);
    for (auto [v, i] : vals) {
        if (!vis[i]) {
            int minv = v, gcdv = v, l = i, r = i;
            for (; l >= 0; l--) {
                minv = min(minv, A[l]);
                gcdv = gcd(gcdv, A[l]);
                if (gcdv != minv) break;
                es.emplace_back(v, l, i);
                if (vis[l]) break;
                vis[l] = true;
            }
            minv = gcdv = v; vis[i] = false;
            for (; r < N; r++) {
                minv = min(minv, A[r]);
                gcdv = gcd(gcdv, A[r]);
                if (gcdv != minv) break;
                es.emplace_back(v, r, i);
                if (vis[r]) break;
                vis[r] = true;
            }
        }
    }

    sort(es.begin(), es.end());
    ll ans = 0;
    DSU dsu; dsu.init(N);
    for (auto [w, a, b] : es) {
        if (!dsu.same(a, b)) {
            ans += w;
            dsu.merge(a, b);
        }
    }

    cout << ans << '\n';
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}