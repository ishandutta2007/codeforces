#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int n;
int fac[maxn];
int invfac[maxn];

int binpow(int x, int p) {
    if (p == 0) return 1;
    if (p & 1) return x * binpow(x, p - 1) % mod;
    return binpow(x * x % mod, p >> 1);
}

int inv(int x) {
    return binpow(x, mod - 2);
}

void precalc() {
    fac[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    invfac[maxn - 1] = inv(fac[maxn - 1]);
    for (int i = maxn - 2; i >= 0; --i) {
        invfac[i] = invfac[i + 1] * (i + 1) % mod;
    }
}

vector<int> primes[maxn];
vector<int> graph[maxn];
int cntdiv[maxn];
int dp[maxn];
bool good[maxn];

void precalc_primes() {
    for (int i = 2; i <= n; ++i) {
        if (primes[i].empty()) {
            for (int j = i; j <= n; j += i) {
                primes[j].push_back(i);
            }
        }
    }
    cntdiv[1] = 1;
    int maxcnt = 1;
    for (int i = 2; i <= n; ++i) {
        int t = primes[i].back();
        cntdiv[i] = 1 + cntdiv[i / t];
        maxcnt = max(maxcnt, cntdiv[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (cntdiv[i] == maxcnt) {
            good[i] = true;
        }
    }
    for (int i = n; i >= 1; --i) {
        if (!good[i]) continue;
        for (auto p: primes[i]) {
            good[i / p] = true;
            graph[i / p].push_back(i);
        }
    }
}

void calc_dp(int k) {
    if (!good[k]) return;
    if (graph[k].empty()) {
        dp[k] = 1;
        return;
    }
    for (auto to: graph[k]) {
        int num = n / k - n / to;
        int a = n - n / k;
        dp[k] += fac[a + num - 1] * invfac[a] % mod * dp[to] % mod * num;
        dp[k] %= mod;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    precalc();
    
    cin >> n;
    precalc_primes();
    for (int i = n; i >= 1; --i) {
        calc_dp(i);
    }
    cout << dp[1] << '\n';
}