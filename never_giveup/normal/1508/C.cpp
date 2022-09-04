//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("fast-math")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#ifdef ONPC
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-const-variable"
#endif
#define fr first
#define sc second
#define m_p make_pair
#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
#define low_bo(a, x) ((int)(lower_bound(a.begin(), a.end(), x) - a.begin()))
#define up_bo(a, x) ((int)(upper_bound(a.begin(), a.end(), x) - a.begin()))
#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
#define popcnt(x) __builtin_popcount(x)
#define shuffle(a) shuffle(a.begin(), a.end(), rnd)
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;

/*const int MEMSIZE = 1e9;
char memory[MEMSIZE];
int memorypos;
inline void * operator new(size_t n){
    if (memorypos + n >= MEMSIZE)
        memorypos = MEMSIZE / 3;
    char * ret = memory + memorypos;
    memorypos += n;
    return (void *)ret;
}
inline void operator delete(void *){}
*/

using ll = long long;

#ifndef ONPC
#define cerr cerr_maksim
struct Cerr : public ostream {
    template<typename T>
    Cerr& operator<<(T const&) {
        return *this;
    }
} cerr;
#endif

#ifdef ONPC
mt19937 rnd(23);
mt19937_64 rndll(231);
#else
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rndll(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif


template<typename T>
void setmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void setmax(T &x, T y) {
    x = max(x, y);
}

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)

// WARNING!!!!!!
// Maksim reads solution
// be careful!!!!

// solution starts here

using ld = double;

const int maxn = 2e5 + 100, maxw = 4 * maxn, inf = 1e9 + 100, llinf = 1e18 + 100;

struct dsu {
    int p[maxn];
    void init(int n) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int get(int x) {
        return x == p[x] ? x : p[x] = get(p[x]);
    }

    int uni(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y)
            return 0;
        if (x > y)
            swap(x, y);
        p[y] = x;
        return 1;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> e(m);
    int tot = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        tot ^= w;
        e[i] = {w, u, v};
    }
    sort(e.begin(), e.end());
    dsu a, b;
    a.init(n);
    b.init(n);
    vector<vector<int>> who(n);
    for (auto [w, v, u] : e) {
        if (v > u)
            swap(v, u);
        who[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        sort(who[i].begin(), who[i].end());
        who[i].push_back(i + 1);
        who[i].insert(who[i].begin(), -1);
        for (int j = 0; j + 1 < who[i].size(); j++) {
            int l = who[i][j] + 1, r = who[i][j + 1] - 1;
            if (l <= r) {
                while (1) {
                    int t = b.get(r);
                    if (t > l) {
                        a.uni(t, t - 1);
                        b.uni(t, t - 1);
                    } else {
                        break;
                    }
                }
                a.uni(i, r);
            }
        }
    }
    set<int> comp;
    for (int i = 0; i < n; i++)
        comp.insert(a.get(i));

    b.init(n);
    vector<bool> tak(m);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        auto [w, v, u] = e[i];
        if (a.uni(v, u)) {
            b.uni(v, u);
            ans += w;
            tak[i] = 1;
        }
    }
    for (int i = 0; i < m; i++)
    if (!tak[i]) {
        auto [w, v, u] = e[i];
        if (b.get(v) != b.get(u)) {
            tot = min(tot, w);
            break;
        }
    }
    if (n * (ll)(n - 1) / 2 - m > n - comp.size()) {
        cout << ans << '\n';
    } else {
        cout << ans + tot << '\n';
    }
}
// check test counter

int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(20);
    if (false) {
        int te = 0;
        while (1) {
            cerr << ++te << '\n';
            solve();
        }
    }
    int ts;
    ts = 1;
    //cin >> ts;
    for (int its = 1; its <= ts; its++) {
        cerr << "\nts " << its << '\n';
        solve();
    }
#ifdef ONPC
    cerr << "\n\nConsumed " << TIME << '\n';
#endif
}