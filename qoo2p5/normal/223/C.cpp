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

const int N = 2002;
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

int n, k;
ll a[N];
ll fact[N], rfact[N];
ll dp[N];
ll ans[N];

ll cnk(ll n, ll k) {
    ll p = 1;
    for (int i = 0; i < k; i++) {
        p = p * (n - i) % MOD;
    }
    p = p * rfact[k] % MOD;
    return p;
}

void run() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    for (int i = 0; i < N; i++) {
        rfact[i] = power(fact[i], MOD - 2);
    }
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int dist = 0; dist < N; dist++) {
        dp[dist] = cnk(dist + k - 1, dist);
    }
    
    for (int i = 0; i < n; i++) {
        for (int dist = 0; i + dist < n; dist++) {
            ans[i + dist] += a[i] * dp[dist];
            ans[i + dist] %= MOD;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}