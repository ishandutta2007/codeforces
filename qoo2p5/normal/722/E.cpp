#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-9;

#define TASK ""

const int N = (int) 2e5 + 123;
const int K = 2016;
const int MOD = (int) 1e9 + 7;

ll power(ll a, ll p) {
    if (p == 0) {
        return 1;
    }
    
    if (p & 1) {
        return (power(a, p - 1) * a) % MOD;
    }
    
    ll tmp = power(a, p / 2);
    return (tmp * tmp) % MOD;
}

ll fact[N];
ll rev_fact[N];

ll cnk(ll n, ll k) {
    return (((fact[n] * rev_fact[k]) % MOD) * rev_fact[n - k]) % MOD;
}

ll calc(const pair<int, int> &a, const pair<int, int> &b) {
    if (!(a.first <= b.first && a.second <= b.second)) {
        return 0;
    }
    
    return cnk((b.first - a.first) + (b.second - a.second), b.first - a.first);
}

void cut(ll &x) {
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

int n, m, k, s;
pair<int, int> p[K];

ll dp[K][K];

int run() {
    fact[0] = 1;
    for (ll i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    for (int i = 0; i < N; i++) {
        rev_fact[i] = power(fact[i], MOD - 2);
    }
    
    cin >> n >> m >> k >> s;
    for (int i = 0; i < k; i++) {
        cin >> p[i].first >> p[i].second;
    }
    
    auto cmp_sum = [] (const pair<int, int> &a, const pair<int, int> &b) {
        return a.first + a.second < b.first + b.second;
    };
    
    sort(p, p + k, cmp_sum);
    p[k] = {n, m};
    k++;
    
    for (int i = 0; i < k; i++) {
        dp[i][0] = calc({1, 1}, p[i]);
        for (int j = 0; j < i; j++) {
            dp[i][0] -= (dp[j][0] * calc(p[j], p[i])) % MOD;
            cut(dp[i][0]);
        }
    }
    
    for (int cnt = 1; cnt <= 21; cnt++) {
        for (int i = 0; i < k; i++) {
            dp[i][cnt] = calc({1, 1}, p[i]);
            for (int j = 0; j < i; j++) {
                dp[i][cnt] -= (dp[j][cnt] * calc(p[j], p[i])) % MOD;
                cut(dp[i][cnt]);
            }
            
            for (int j = 0; j < cnt; j++) {
                dp[i][cnt] -= dp[i][j];
                cut(dp[i][cnt]);
            }
        }
    }
    
    ll ans = 0;
    ll all = calc({1, 1}, {n, m});
    ll rest = all;
    
    for (int cnt = 0; cnt <= 21; cnt++) {
        ll x = s;
        for (int i = 0; i < cnt; i++) {
            x = x / 2 + x % 2;
        }
        
        rest -= dp[k - 1][cnt];
        cut(rest);
        ans += (x * dp[k - 1][cnt]) % MOD;
        cut(ans);
    }
    
    ans += rest;
    cut(ans);
    
    ans = (ans * power(all, MOD - 2)) % MOD;
    cout << ans << "\n";
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef DEBUG
    if (strlen(TASK) > 0) {
        freopen(TASK ".in", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
#endif

    return run();
}