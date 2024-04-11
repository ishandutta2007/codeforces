#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define SZ(x) int((x).size())
#define fi first
#define se second

using namespace std;
using ll = long long;

const int N = 5e5 + 5;

int n, m, f[1 << 15], g[1 << 15];
ll X, Y;
set<ll> s;
vector<ll> w;

namespace PR {
    ll mul(ll a, ll b, ll p) {
        return (a * b - ll((long double)a / p * b + 0.5) * p + p) % p;
    }
    ll Pow(ll a, ll n, ll p, ll r = 1) {
        for(; n; n /= 2, a = mul(a, a, p))
        if(n & 1) r = mul(r, a, p);
        return r;
    }
    bool mr(ll p, ll n) {
        if(Pow(p, n - 1, n) != 1) return 0;
        ll d = n - 1, t;
        while(~d & 1) d /= 2;
        if((t = Pow(p, d, n)) == 1) return 1;
        while(t != 1 && t != n - 1) t = mul(t, t, n), d *= 2;
        return t == n - 1;
    }
    bool chk(ll n) {
        for(int p : {2, 3, 7, 61, 24251}) {
            if(n == p) return 1;
            if(!mr(p, n)) return 0;
        }
        return 1;
    }
    ll f(ll x, ll c, ll p) { return (mul(x, x, p) + c) % p; }
    ll PR(ll n) {
        ll a = 0, b = 0, c = rand() % (n - 1) + 1, v = 1, g;
        for(int k = 1; ; k <<= 1, a = b, v = 1) {
            rep(i, 1, k) {
                b = f(b, c, n), v = mul(v, abs(a - b), n);
                if(!(i & 127) || i == k) {
                    g = __gcd(v, n);
                    if(g > 1) return g;
                }
            }
        }
    }
    void solve(ll n) {
        if(chk(n)) return void(s.insert(n));
        ll d; do d = PR(n); while(d == n);
        solve(d), solve(n / d);
    }
}

int main() {
    cin >> n >> X >> Y;
    if(Y % X) puts("0"), exit(0);
    if(X < Y) PR::solve(Y / X);
    for(ll x : s) w.pb(x);
    ll x;
    while(n--) {
        scanf("%lld", &x);
        if(x % X == 0) {
            int S = 0;
            For(i, 0, SZ(w)) S |= (x / X % w[i] == 0) << i;
            f[S]++;
        }
        if(Y % x == 0) {
            int S = 0;
            For(i, 0, SZ(w)) S |= (Y / x % w[i] == 0) << i;
            g[S]++;
        }
    }
    ll ans = 0;
    For(S, 0, 1 << SZ(w)) for(int T = S;; --T &= S) {
        ans += (ll)f[(1 << SZ(w)) - 1 ^ S] * g[T];
        if(!T) break;
    }
    cout << ans;
}