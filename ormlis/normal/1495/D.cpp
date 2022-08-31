#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 405;
const int md = 998244353; //1e9 + 7, 1e9 + 9

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 2e5 + 5;
int fact[maxF];
int rfact[maxF];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int dist[maxN][maxN];
vector<int> g[maxN];

void solve() {
    int n, m; cin >> n >> m;
    range(i, n) range(j, n) dist[i][j] = 1e9;
    range(_, m) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        dist[a][b] = 1;
        dist[b][a] = 1;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    range(i, n) dist[i][i] = 0;
    range(k, n) {
        range(i, n) {
            range(j, n) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    range(i, n) {
        range(j, n) {
            vector<int> to(n, -1);
            vector<bool> was(n);
            vector<int> h(n, -1);
            bool ok = true;
            vector<int> ord;
            range(w, n) {
                if (dist[i][w] + dist[w][j] == dist[i][j]) {
                    if (was[dist[i][w]]) {
                        ok = false;
                        break;
                    }
                    was[dist[i][w]] = true;
                    to[w] = dist[i][w];
                    h[w] = 0;
                    continue;
                }
                int dd = dist[i][w] + dist[j][w] - dist[i][j];
                if (dd % 2 == 1) {
                    ok = false;
                    break;
                }
                dd /= 2;
                h[w] = dd;
                to[w] = dist[i][w] - dd;
                ord.push_back(w);
            }
            if (!ok) {
                cout << "0 ";
                continue;
            }
            int cnt = 1;
            for(auto &v : ord) {
                int ct = 0;
                for(auto &u : g[v]) {
                    if (to[u] != to[v] || h[u] != h[v] - 1) continue;
                    ct++;
                }
                cnt = mul(cnt, ct);
            }
            cout << cnt << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}