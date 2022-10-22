#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define upd(a, b) (a = max(a, b))

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, a[N];

ll gen(ll x) {
    const ll k = 0x9ddfea08eb382d69ull;
    rep(i, 1, 3) x *= k, x ^= x >> 47;
    return x * k;
}
int rnd() {
    static ll s = 2;
    return ((s += gen(s)) & INT_MAX) % n + 1;
}
map<pair<int, int>, ll> p;
ll qry(int x, int y) {
    if(x > y) swap(x, y);
    pair<int, int> t(x, y);
    if(p.count(t)) return p[t];
    printf("? %d %d\n", x, y), fflush(stdout);
    ll z; scanf("%lld", &z); return p[t] = z;
}
void solve() {
    scanf("%d", &n), p.clear();
    rep(i, 1, n) a[i] = 0;
    if(n == 3) {
        vector<int> v{1, 2, 3};
        do {
            ll q0 = qry(v[0], v[1]), q1 = qry(v[1], v[2]), x = sqrt(q1);
            if(x * (x - 1) == q0 && x * (x + 1) == q1) {
                a[v[0]] = x - 1, a[v[1]] = x, a[v[2]] = x + 1;
                break;
            }
        } while(next_permutation(v.begin(), v.end()));
    } else if(n <= 100) {
        int x;
        rep(i, 1, n) rep(j, i + 1, n) if(qry(i, j) & 1) x = i;
        vector<int> o{x}, e;
        rep(i, 1, n) if(i ^ x) qry(x, i) & 1 ? o.pb(i) : e.pb(i);
        vector<tuple<ll, int, int>> v;
        for(int i : o) for(int j : e) v.eb(qry(i, j), i, j);
        sort(v.rbegin(), v.rend());
        int f = n & 1;
        for(auto [z, x, y] : v) {
            if(a[x] || a[y]) continue;
            z = sqrt(z) + 1;
            if(f) z & 1 ? a[x] = z : a[y] = z, f = 0;
            else if(z & 1) a[x] = z, a[y] = z - 1;
            else a[y] = z, a[x] = z - 1;
        }
    } else if(n <= 5000) {
        auto calc = [](ll n) {
            int re = 0;
            for(int i = 2; (ll)i * i <= n; i++) while(n % i == 0) upd(re, i), n /= i;
            return max(re, (int)n);
        };
        int p, ma = 0;
        rep(i, 2, n) {
            int t = calc(qry(i, i - 1));
            if(t > ma) ma = t, p = i;
        }
        if(p == 2 && calc(qry(2, 3)) < ma) p--;
        a[p] = ma;
        rep(i, 1, n) if(!a[i]) a[i] = qry(i, p) / ma;
    } else {
        auto calc = [](ll n) {
            vector<int> v;
            for(int i = 2; (ll)i * i <= n; i++) while(n % i == 0) v.pb(i), n /= i;
            if(n > 1) v.pb(n);
            return v.size() == 2 && v[0] > 450 && v[1] > 450 && v[0] ^ v[1] ? v[0] : 0;
        };
        auto chk = [](int n) {
            for(int i = 2; i * i <= n; i++) if(n % i == 0) return 0;
            return 1;
        };
        int x, y;
        while(1) {
            do x = rnd(), y = rnd(); while(x == y);
            if(calc(qry(x, y))) break;
        }
        int p = calc(qry(x, y));
        while(1) {
            int z; do z = rnd(); while(z == x || z == y);
            if(qry(z, x) % p) { x = y; break; }
            if(qry(z, y) % p) break;
        }
        a[x] = p;
        rep(i, 1, n) if(!a[i] && qry(i, x) > 200000) {
            a[i] = qry(i, x) / p;
            if(chk(a[i]) && a[i] > p) x = i, p = a[i];
        }
        rep(i, 1, n) if(!a[i]) a[i] = qry(i, x) / p;
    }
    printf("! ");
    rep(i, 1, n) printf("%d ", a[i]);
    puts(""), fflush(stdout);
}
int main() {
    int T;
    for(cin >> T; T--; solve());
}