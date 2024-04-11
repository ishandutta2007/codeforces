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

ll get(int x) {
    if (x >= 60)
        return 1e18 + 1000;
    return (1ll << max(0, x));
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    k--;
    int ps = 0;
    vector<int> ans;
    while (ps < n) {
        int m = n - ps;
        int i = 0;
        while (i < m && k >= get(m - i - 1 - 1)) {
            k -= get(m - i - 1 - 1);
            i++;
        }
        if (i == m) {
            cout << -1 << '\n';
            return;
        }
        cerr << i << '\n';
        for (int j = i; j >= 0; j--)
            ans.push_back(ps + j);
        ps += i + 1;
    }
    for (int i : ans)
        cout << i + 1 << ' ';
    cout << '\n';
    cerr << "done\n";
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
    cin >> ts;
    for (int its = 1; its <= ts; its++) {
        cerr << "\nts " << its << '\n';
        solve();
    }
#ifdef ONPC
    cerr << "\n\nConsumed " << TIME << '\n';
#endif
}