#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

const int N = (int) 1e5 + 123;
const ll MOD = (ll) 1e9 + 7;

ll power(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return x * power(x, y - 1) % MOD;
    } else {
        ll t = power(x, y / 2);
        return t * t % MOD;
    }
}

int n, f;
int ptr;
int divs[N];
ll fact[N], rfact[N];
ll dp[N];
vector<int> precalc[N];

ll cnk(ll n, ll k) {
    return fact[n] * rfact[k] % MOD * rfact[n - k] % MOD;
}

void add(ll &x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void sub(ll &x, ll y) {
    x -= y;
    if (x < 0) x += MOD;
}

void solve() {
    ptr = 0;
    for (int d : precalc[n]) {
        dp[d] = 0;
    }
    
    for (int i = (int) precalc[n].size() - 1; i >= 0; i--) {
        int x = precalc[n][i];
        int have = n / x;
        
        if (have >= f) {
            add(dp[x], cnk(have - 1, have - f));
        }
        
        for (int d : precalc[x]) {
            if (d != x) {
                sub(dp[d], dp[x]);
            }
        }
    }
    
    cout << dp[1] << "\n";
}

void run() {
    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        rfact[i] = power(fact[i], MOD - 2);
        
        for (int d = 1; d * d <= i; d++) {
            if (i % d == 0) {
                int subd = i / d;
                precalc[i].push_back(d);
                if (d != subd) {
                    precalc[i].push_back(subd);
                }
            }
        }
        
        sort(precalc[i].begin(), precalc[i].end());
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n >> f;
        solve();
    }
}