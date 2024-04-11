#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);
const ll MOD = (ll) (1e9 + 7);

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

long long power(long long x, long long y) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power(x * x % MOD, y / 2);
    } else {
        return power(x, y - 1) * x % MOD;
    }
}

const int K = (int) 1e4 + 123;
const int P = 55;

vector<ll> get_primes(ll n) {
    vector<ll> res;
    for (ll d = 2; d * d <= n; d++) {
        if (n % d != 0) {
            continue;
        }
        while (n % d == 0) {
            n /= d;
        }
        res.push_back(d);
    }
    if (n > 1) {
        res.push_back(n);
    }
    return res;
}

vector<ll> primes;
ll dp[K][P];
ll rev[P];

void run() {
    for (int i = 0; i < P; i++) {
        rev[i] = power(i + 1, MOD - 2);
    }
    ll n;
    int k;
    cin >> n >> k;
    primes = get_primes(n);
    ll answer = 1;
    for (ll p : primes) {
        int c = 0;
        while (n % p == 0) {
            c++;
            n /= p;
        }
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= c + 1; j++) {
                dp[i][j] = 0;
            }
        }
        dp[0][c] = 1;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j <= c; j++) {
                dp[i + 1][j] += dp[i][j] * rev[j] % MOD;
                dp[i + 1][j] %= MOD;
            }
            for (int j = c; j >= 0; j--) {
                dp[i + 1][j] += dp[i + 1][j + 1];
                dp[i + 1][j] %= MOD;
            }
        }
        ll t = 1;
        ll cur = 0;
        for (int i = 0; i <= c; i++) {
            cur += dp[k][i] * t % MOD;
            t *= p % MOD;
            t %= MOD;
            cur %= MOD;
        }
        answer *= cur;
        answer %= MOD;
    }
    cout << answer << "\n";
}