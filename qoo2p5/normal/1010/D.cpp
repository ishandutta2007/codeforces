#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (long long) (1e18 + 1e9 + 123);

template<class A, class B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<class A, class B> bool maxi(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

const int N = (int) 1e6 + 123;

int n;
vector<int> g[N];
string type[N];
int val[N];
int dp[N][2];

void find_val(int v) {
    if (type[v] == "IN") {
        return;
    }
    for (int u : g[v]) {
        find_val(u);
    }
    if (type[v] == "NOT") {
        val[v] = !val[g[v][0]];
    } else {
        int l = g[v][0];
        int r = g[v][1];
        if (type[v] == "AND") {
            val[v] = val[l] & val[r];
        } else if (type[v] == "OR") {
            val[v] = val[l] | val[r];
        } else {
            assert(type[v] == "XOR");
            val[v] = val[l] ^ val[r];
        }
    }
}

int other(int v, int p) {
    for (int u : g[p]) {
        if (u != v) {
            return u;
        }
    }
    assert(false);
    return -1;
}

void solve(int v, int p = -1) {
    if (p == -1) {
        dp[v][0] = 0;
        dp[v][1] = 1;
    } else {
        if (type[p] == "NOT") {
            dp[v][0] = dp[p][1];
            dp[v][1] = dp[p][0];
        } else {
            int u = other(v, p);
            if (type[p] == "AND") {
                for (int x = 0; x < 2; x++) {
                    dp[v][x] = dp[p][x & val[u]];
                }
            } else if (type[p] == "OR") {
                for (int x = 0; x < 2; x++) {
                    dp[v][x] = dp[p][x | val[u]];
                }
            } else {
                assert(type[p] == "XOR");
                for (int x = 0; x < 2; x++) {
                    dp[v][x] = dp[p][x ^ val[u]];
                }
            }
        }
    }
    for (int u : g[v]) {
        solve(u, v);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> type[i];
        if (type[i] == "IN") {
            cin >> val[i];
        } else if (type[i] == "NOT") {
            int to;
            cin >> to;
            g[i].push_back(to);
        } else {
            int l, r;
            cin >> l >> r;
            g[i].push_back(l);
            g[i].push_back(r);
        }
    }
    find_val(1);
    solve(1);

    string res;
    for (int i = 1; i <= n; i++) {
        if (type[i] == "IN") {
            int to = dp[i][val[i] ^ 1];
            if (to == 1) {
                res += "1";
            } else {
                res += "0";
            }
        }
    }
    cout << res << "\n";

    return 0;
}