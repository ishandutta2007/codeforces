#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")
#include <bits/stdc++.h>
#define row first
#define col second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
const ll MOD = 1e9 + 7;
ll R, C, N;
ii black[2005];
ll fact[200005], inv[200005];
ll memo[2005];
// ll way[2005][2005];

ll xpow(ll n, ll x) {
    if (x == 0) return 1;
    if (x == 1) return n % MOD;
    ll a = xpow(n, x / 2);
    a %= MOD;
    a = (a * a) % MOD;
    if (x&1) a *= n;
    a %= MOD;
    return a;
}
inline ll combin(ll n, ll r) {
    ll atas = fact[n] % MOD;
    atas *= inv[n - r];
    atas %= MOD;
    atas *= inv[r];
    // atas *= (xpow((fact[n - r] * (fact[r] % MOD)) % MOD, MOD - 2)) % MOD;
    // atas %= MOD;
    // atas *= (xpow(fact[r], MOD - 2)) % MOD;
    atas %= MOD;
    return atas;
}
inline void init() {
    fact[0] = 1;
    inv[0] = xpow(fact[0], MOD - 2);
    for (int i = 1; i <= 200003; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
        inv[i] = xpow(fact[i], MOD - 2) % MOD;
    }
}
inline ll ways(ll r1, ll c1, ll r2, ll c2) {
    if (r1 > r2 || c1 > c2) return 0;
    ll res = combin(r2 - r1 + c2 - c1, r2 - r1);
    res %= MOD;
    return res;
}
inline ll ways2(ll id1, ll id2) {
    if (black[id1].row > black[id2].row || black[id1].col > black[id2].col) return 0;
    ll res = combin(black[id2].row - black[id1].row + black[id2].col - black[id1].col, black[id2].row - black[id1].row);
    res %= MOD;
    return res;
}
ll solve(ll loc) {
    if (memo[loc] != -1) return memo[loc];
    ll res = ways2(0, loc);
    for (ll i = 1; i <= N; i++) {
        if (i == loc) continue;
        if (black[i].col > black[loc].col) break;
        if (black[i].row > black[loc].row) continue;
        // res += ways(black[i].row, black[i].col, black[loc].row, black[loc].col) * solve(i);
        res -= solve(i) * ways2(i, loc);
        res %= MOD;
    }
    res += MOD;
    res %= MOD;
    memo[loc] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init(); memset(memo, -1, sizeof(memo));
    // memset(way, -1, sizeof(way));
    cin >> R >> C >> N;
    for (int i = 1; i <= N; i++) {
        cin >> black[i].row >> black[i].col;
    }
    sort(black + 1, black + N + 1, [](ii &a, ii &b) {
        return a.col < b.col || (a.col == b.col && a.row < b.row);
    });
    black[0] = {1, 1};
    black[N + 1] = {R, C};
    ll ans = 0;
    ans = solve(N + 1);
    cout << ans << "\n";
}