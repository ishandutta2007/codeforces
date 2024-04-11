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

const int maxn = 3e5 + 100, maxw = 4 * maxn, inf = 1e9 + 100, llinf = 1e18 + 100;

vector<int> e[maxn];

int par[maxn];

int tin[maxn], tout[maxn], h[maxn];

int tnow;

void predfs(int v) {
    tin[v] = tnow;
    tnow++;
    for (int i : e[v]) {
        h[i] = h[v] + 1;
        predfs(i);
    }
    tout[v] = tnow++;
}

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

bool good[maxn];

int a[maxn], ob[maxn];

bool dod[maxn];

int ans[maxn];

void go(int v) {
    ans[v] = tnow++;
    for (int i : e[v])
        if (dod[i])
            go(i);
        else
            break;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        ob[a[i]] = i;
    }
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        e[v].push_back(u);
        par[u] = v;
    }
    for (int i = 0; i < n; i++)
        sort(e[i].begin(), e[i].end(), [&](int x, int y) {return a[x] < a[y];});
    predfs(0);
    ll answer = 0;
    int root = 0;
    int v;
    for (v = 0; v < n; v++) {
        int u = ob[v];
        answer += h[u];
        if (!anc(root, u)) {
            break;
        }
        bool done = 0;
        for (int i : e[u])
            if (!good[i]) {
                done = 1;
                break;
            }
        if (done)
            break;
        good[u] = 1;
        root = par[u];
    }
    if (v == n) {
        for (int i = 0; i < n; i++)
            dod[i] = 1;
        tnow = 0;
        go(0);
    } else {
        int id = v;
        v = ob[v];
        while (1) {
            bool done = 0;
            for (int i : e[v])
                if (!good[i]) {
                    swap(a[v], a[i]);
                    v = i;
                    done = 1;
                    break;
                }
            if (!done)
                break;
        }
        int tu = id + h[v];
        int tt = tu;
        good[v] = 1;
        if (v != 0) {
            v = par[v];
            while (1) {
                if (a[v] != tu) {
                    cout << "NO\n";
                    return;
                }
                good[v] = 1;
                if (v == 0)
                    break;
                v = par[v];
                tu--;
            }
        }
        for (int i = 0; i < n; i++) {
            dod[i] = good[i];
            good[i] = 0;
        }
        root = 0;
        for (int i = n - 1; i > tt; i--) {
            int v = ob[i];
            ans[v] = i;
            if (!anc(root, v)) {
                cout << "NO\n";
                return;
            }
            for (int j : e[v])
                if (!good[j]) {
                    cout << "NO\n";
                    return;
                }
            good[v] = 1;
            root = par[v];
        }
        tnow = 0;
        go(0);
    }
    cout << "YES\n";
    cout << answer << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
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