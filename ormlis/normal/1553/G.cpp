#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 1e6 + 5;
const int md = 31607;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct dsu {
    vector<int> dsu;
    vector<int> rnk;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        dsu.resize(n);
        rnk.resize(n, 1);
        iota(all(dsu), 0);
    }

    bool unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (a == b) return false;
        if (rnk[a] > rnk[b]) swap(a, b);
        rnk[b] += rnk[a];
        dsu[a] = b;
        return true;
    }
};

int mp[maxN];
vector<int> primes;

void init() {
    for (int i = 2; i < maxN; ++i) {
        if (!mp[i]) {
            mp[i] = i;
            primes.push_back(i);
        }
        for (auto &p : primes) {
            if (1ll * p * i >= maxN || p > mp[i]) break;
            mp[i * p] = p;
        }
    }
}

int to[maxN];

vector<int> get_primes(int x) {
    vector<int> pr;
    while (x != 1) {
        int p = mp[x];
        while (x % p == 0) x /= p;
        pr.push_back(p);
    }
    return pr;
}

int has[maxN];

void solve() {
    init();
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    range(i, maxN) has[i] = -1;
    range(i, n) {
        cin >> a[i];
        has[a[i]] = i;
    }
    dsu d;
    d.build(n);
    for(int i = 2; i < maxN; ++i) {
        if (mp[i] != i) continue;
        int was = -1;
        for(int j = i; j < maxN; j += i) {
            if (has[j] == -1) continue;
            if (was == -1) was = has[j];
            d.unio(has[j], was);
        }
    }
    range(i, maxN) to[i] = -1;
    range(i, n) {
        int x = d.get_dsu(i);
        auto pr = get_primes(a[i]);
        for(auto &p : pr) {
            to[p] = x;
        }
    }
    vector<set<int>> g(n);
    range(i, n) {
        auto pr = get_primes(a[i] + 1);
        int x = d.get_dsu(i);
        vector<int> kek;
        for(auto &p : pr) {
            if (to[p] == -1) continue;
            g[x].insert(to[p]);
            kek.push_back(to[p]);
        }
        sort(all(kek));
        kek.resize(unique(all(kek)) - kek.begin());
        for(auto &xx : kek) {
            for(auto &yy : kek) {
                g[xx].insert(yy);
            }
        }
    }
    range(_, q) {
        int s, t; cin >> s >> t;
        s--;
        t--;
        s = d.get_dsu(s);
        t = d.get_dsu(t);
        if (s == t) {
            cout << "0\n";
        } else if (g[s].count(t) || g[t].count(s)) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}