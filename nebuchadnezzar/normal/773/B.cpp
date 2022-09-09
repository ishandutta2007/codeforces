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

int const N = 222;

int n;
int a[N][5];
int type[5];
bool dp[5][6];

int get_score(int i) {
    int ret = 0;
    for (int t = 0; t < 5; ++t) {
        if (a[i][t] < 0)
            continue;
        int v = (type[t] + 1) * 500;
        ret += v - v / 250 * a[i][t];
    }
    return ret;
}

bool go(int task) {
    if (task == 5) {
        int p = get_score(0);
        int v = get_score(1);
        return p > v;
    }
    for (type[task] = 0; type[task] < 6; ++type[task]) {
        if (dp[task][type[task]]) {
            if (go(task + 1))
                return true;
        }
    }
    return false;
}

bool intersect(int a, int b, int x, int y) {
    return !(b < x || y < a);
}

bool check(int cnt) {
    for (int x = 0; x < 5; ++x) {
        int oks = 0;
        for (int i = 0; i < n; ++i)
            if (a[i][x] >= 0)
                ++oks;
        for (int y = 0; y < 6; ++y) {
            int mi = (n + cnt) / (1 << (y + 1)) + 1;
            if (y == 5)
                mi = 0;
            int ma = (n + cnt) / (1 << y);
            dp[x][y] = mi <= ma && intersect(mi, ma, oks, oks + (a[0][x] >= 0 ? cnt : 0));
        }
    }
    return go(0);
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int x = 0; x < 5; ++x) {
            scanf("%d", a[i] + x);
        }
    }
    int ans = 0;
    while (ans < 33 * n && !check(ans)) {
        ++ans;
    }
    if (!check(ans))
        ans = -1;
    cout << ans << '\n';
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