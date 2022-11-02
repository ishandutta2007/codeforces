#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <numeric>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

const ll mod = 1e9 + 7;

void imult(ll & lhs, const ll & rhs) {
    lhs = (lhs * rhs) % mod;
}

void iadd(ll & lhs, const ll & rhs) {
    lhs = (lhs + rhs) % mod;
}

void isubt(ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll & lhs, const ll & rhs) {
    if (rhs == 0)return 1;
    ll ret = bpw(lhs, rhs >> 1);
    imult(ret, ret);
    if (rhs & 1) imult(ret, lhs);
    return ret;
}

ll inv(const ll & x) {
    return bpw(x, mod - 2);
}

ll mult(const ll & lhs, const ll & rhs) {
    return (lhs * rhs) % mod;
}

ll add(const ll & lhs, const ll & rhs) {
    return (lhs + rhs) % mod;
}

ll subt(const ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll & lhs, const ll & rhs) {
    return mult(lhs, inv(rhs));
}

int foo(int x) {
    int tot = 0;
    for (int i = 1; i < x; i++) {
        tot += gcd(i, x - i);
    }
    return tot;
}

const int N = 1e5 + 5;
int lp[N + 1];
vector<int> pr;
ll phi[N + 1], gcdsum[N + 1], diagall[N + 1], diaggood[N + 1];
vector<int> divs[N + 1];

void sieve() {
    phi[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            phi[i] = i - 1;
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (lp[i] != pr[j])phi[i * pr[j]] = phi[i] * (pr[j] - 1);
            else phi[i * pr[j]] = phi[i] * pr[j];
        }
    }
    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i)divs[j].push_back(i);
    }
}

void calcsums() {
    for (int d = 1; d <= N; d++) {
        for (int n = d; n <= N; n += d) {
            gcdsum[n] += mult(phi[d], n / d + 1);
        }
    }
    gcdsum[1] = 0;
    for (int n = 2; n <= N; n++) {
        isubt(gcdsum[n], 2 * n);
    }
}

void prec() {
    sieve();
    calcsums();
}

ll diag(ll n) {
    ll tmpsum = 0;
    for (int z = 1; z < n; z++) {
        iadd(tmpsum, mult(z, gcdsum[n - z]));
    }
    ll sumbad = 0;
    for (int y : divs[n]) {
        iadd(sumbad, mult(y, mult(y, diaggood[n / y])));
    }
    diagall[n] = tmpsum;
    diaggood[n] = subt(diagall[n], sumbad);
    return diaggood[n];
}

ll solve(ll n) {
    ll tot = 0;
    for (int k = n; k >= 1; k--) {
        if (n % k != 0)continue;
        ll tmpsum = 0;
        iadd(tmpsum, diag(n / k));
        iadd(tot, mult(k,tmpsum));
    }
    return tot;
}

ll bf(ll n) {
    ll tot = 0;
    for (ll a = 1; a < n; a++) {
        for (ll b = 1; a + b < n; b++) {
            ll c = n - a - b; 
            iadd(tot, lcm(c, gcd(a, b)));
        }
    }
    return tot;
}

int main() {
    fast;
    prec();
    ll n;
    cin >> n;
    ll ans = solve(n);
    cout << ans;
    return 0;
}