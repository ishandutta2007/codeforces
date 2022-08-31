#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 5e5 + 100;
const int md2 = 998244353;
const int md = 1e9 + 7;


int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

struct dsu {
    vector<int> dsu;
    vector<int> to;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        dsu.resize(n);
        to.resize(n, 0);
        range(i, n)dsu[i] = i;
    }

    bool unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (rand() % 2) {
            swap(a, b);
        }
        dsu[a] = b;
        to[b] |= to[a];
        return a == b;
    }
};

vector<int>  g[maxN];
bool good[maxN];
int was[maxN];

void seted(int v) {
    was[v] = 2;
    good[v] = true;
    for(auto &u : g[v]) {
        if (was[u] == 2) continue;
        seted(u);
    }
}

bool finded = false;

int dfs(int v) {
    was[v] = 1;
    int sz = 1;
    if (good[v]) finded = true;
    for (auto &u : g[v]) {
        if (was[u]) continue;
        sz += dfs(u);
    }
    return sz;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a;
    a.reserve(n);
    range(i, n) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            a.push_back({x});
            good[x] = true;
            continue;
        }
        int x1, x2;
        cin >> x1 >> x2;
        g[x1].push_back(x2);
        g[x2].push_back(x1);
        a.push_back({x1, x2});
    }
    int sz = 1;
    for (int i = 1; i <= m; ++i) {
        if (was[i]) continue;
        int w = dfs(i);
        if (finded) {
            seted(i);
            finded = false;
        }
        if (good[i]) {
            sz = mul(sz, binpow(2, w));
        } else {
            sz = mul(sz, binpow(2, w - 1));
        }
    }
    vector<int> answer;
    dsu d;
    d.build(m + 5);
    range(i, n) {
        if (a[i].size() == 1) {
            int x = a[i][0];
            int w = d.get_dsu(x);
            if (d.to[w]) continue;
            d.to[w] = 1;
            answer.push_back(i + 1);
            continue;
        }
        int x1 = a[i][1];
        int x2 = a[i][0];
        if (good[x1]) {
            x1 = d.get_dsu(x1);
            x2 = d.get_dsu(x2);
            if (x1 == x2) continue;
            if (!d.to[x1] || !d.to[x2]) {
                d.unio(x1, x2);
                answer.push_back(i + 1);
            }
        } else {
            if (!d.unio(x1, x2)) {
                answer.push_back(i + 1);
            }
        }
    }
    cout << sz << ' ';
    cout << answer.size() << '\n';
    for(auto &i : answer) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}