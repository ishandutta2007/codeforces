#ifdef LOCAL
//#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>

using namespace std;
#define next __next
#define prev __prev
#define right __right
#define left __left
#define index __index

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

typedef pair<int, int> ipair;
#define szof(x) ((int)(x).size())
#define bend(x) (x).begin(), (x).end()
#define X first
#define Y second

int const INF = 100 + (int) 1e9;
ll const INFL = 100 + (ll) 1e18;
ld const PI = 3.141592653589793238462643L;
mt19937 tw(960172);

int millis() { static auto s = chrono::system_clock::now(); return 1e3 * chrono::duration<double>(chrono::system_clock::now() - s).count(); }
bool is_prime(ll x) { for (ll y = 2; y * y <= x; ++y) if (x % y == 0) return 0; return x > 1; }
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }
ll sqr(int a) { return (ll) a * a; } template<class T> T sqr(T const& a) { return a * a; }
ll gcd(ll a, ll b) { while (b > 0) { ll t = a % b; a = b; b = t; } return a; }

int const N = 2020;

int w[N][N];
bool good[N];
ll dist[N];
bool used[N];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            scanf("%d", w[i] + j);
            w[j][i] = w[i][j];
        }
    }
    int mi_edge = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            mi_edge = min(mi_edge, w[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                w[i][j] -= mi_edge;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        good[i] = false;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                good[i] |= w[i][j] == 0;
            }
        }
    }
    fill(dist, dist + n, INFL);
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            dist[i] = 0;
        } else {
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                if (!good[j]) {
                    dist[i] = min(dist[i], w[i][j] * 2LL);
                } else {
                    dist[i] = min(dist[i], w[i][j] * 1LL);
                }
            }
        }
    }
    fill(used, used + n, false);
    for (int it = 0; it < n; ++it) {
        int v = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && (v < 0 || dist[v] > dist[i])) {
                v = i;
            }
        }
        used[v] = true;
        for (int to = 0; to < n; ++to) {
            dist[to] = min(dist[to], dist[v] + w[v][to]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << dist[i] + (ll(n - 1) * mi_edge) << '\n';
    }
}

int main() {
    millis();
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    cout << setprecision(15) << fixed;
#ifdef LOCAL
    cerr << setprecision(6) << fixed;
#endif
    int tcnt = 1;
    //scanf("%d", &tcnt);
    for (int test = 1; test <= tcnt; ++test)
        solve();
#ifdef LOCAL
    cerr << "time: " << millis() << " ms" << endl;
#endif
}