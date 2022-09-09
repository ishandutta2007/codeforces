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

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> can(m, 1);
    
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        can[x] = false;
    }
    
    vector<vector<int>> who(m + 1);
    for (int i = 0; i < m; ++i)
        if (can[i])
            who[gcd(i, m)].push_back(i);

    vector<int> dp(m + 1, -1);
    vector<int> prev(m + 1, -1);
    
    for (int g = 1; g <= m; ++g) {
        if (m % g != 0)
            continue;
        int sz = who[g].size();
        dp[g] = sz;
        for (int x = 1; x * x <= g; ++x) {
            if (g % x == 0) {
                if (g > x && dp[x] + sz > dp[g])
                    dp[g] = dp[x] + sz, prev[g] = x;
                if (x > 1 && dp[g / x] + sz > dp[g])
                    dp[g] = dp[g / x] + sz, prev[g] = g / x;
            }
        }
    }
    
    int last = max_element(bend(dp)) - dp.begin();
    vector<int> ans;
    for (; last != -1; last = prev[last]) {
        ans.insert(ans.end(), bend(who[last]));
    }
    
    reverse(bend(ans));
    //for (int x : ans)
    //    cerr << x << ' ';
    //cerr << '\n';
    
    int phi = 0;
    for (int i = 0; i < m; ++i)
        if (gcd(i, m) == 1)
            ++phi;

    vector<int> out(ans.size());
    out[0] = ans[0];
    for (int i = 1; i < (int)ans.size(); ++i) {
        int a = ans[i];
        int b = ans[i - 1];
        
        int g = gcd(b, m);
        int b1 = b / g;
        int m1 = m / g;
        assert(a % g == 0);
        int a1 = a / g;
        
        int den = 1;
        for (int x = b1, y = phi - 1; y > 0; y /= 2) {
            if (y % 2 == 1)
                den = (ll) den * x % m1;
            x = (ll) x * x % m1;
        }
        
        out[i] = (ll)a1 * den % m1;
        
    }
    
    cout << out.size() << '\n';
    for (int x : out)
        cout << x << ' ';
    cout << '\n';
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