#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define SZ(x) int((x).size())

using namespace std;
using ll = long long;

const int N = 1 << 19, P = 998244353;

int n, K, q, c[N], b[9], Q[N], ans[N];
int lim, rev[N];
ll w[N];
 
ll Pow(ll a, int n, ll r = 1) {
    for(; n; n >>= 1, a = a * a % P)
    if(n & 1) r = r * a % P;
    return r;
}
void NTT(vector<ll>& a, int t) {
    For(i, 0, lim) if(rev[i] < i) swap(a[i], a[rev[i]]);
    for(int i = 1; i < lim; i <<= 1)
    for(int j = 0; j < lim; j += i << 1) For(k, 0, i) {
        ll &x = a[j + k], y = a[j + k + i] * w[i + k] % P;
        a[j + k + i] = x >= y ? x - y : x - y + P;
        x = x + y < P ? x + y : x + y - P;
    }
    if(!t) return;
    reverse(a.begin() + 1, a.end());
    ll inv = Pow(lim, P - 2);
    For(i, 0, lim) (a[i] *= inv) %= P;
}
vector<ll> solve(int l, int r) {
	if(l > r) return vector<ll>(1, 1);
    if(l == r) {
        vector<ll> res(min(c[l] + 1, 3));
        res[0] = 1;
        if(c[l]) res[1] = 2;
        if(c[l] > 1) res[2] = 1;
        return res;
    }
    int mid = l + r >> 1;
    auto &&L = solve(l, mid), &&R = solve(mid + 1, r);
    int need = SZ(L) + SZ(R) - 1;
    for(lim = 1; lim < need; lim <<= 1);
    For(i, 0, lim) rev[i] = rev[i >> 1] >> 1 | (i & 1 ? lim >> 1 : 0);
    for(int i = 1; i < lim; i <<= 1) {
        ll wn = Pow(3, P / 2 / i);
        For(j, 0, i) w[i + j] = j ? w[i + j - 1] * wn % P : 1;
    }
    L.resize(lim), R.resize(lim);
    NTT(L, 0), NTT(R, 0);
    For(i, 0, lim) (L[i] *= R[i]) %= P;
    NTT(L, 1), L.resize(need);
    return L;
}
int main() {
    cin >> n >> K;
    int x;
    while(n--) scanf("%d", &x), c[x]++;
    rep(i, 1, K) scanf("%d", &b[i]);
    cin >> q;
    rep(i, 1, q) scanf("%d", &Q[i]);
    rep(i, 1, K) {
        auto&& res = solve(1, b[i] - 1);
        rep(j, 1, q) {
            int t = Q[j] / 2 - b[i] - 1;
            if(t >= 0 && t < SZ(res)) (ans[j] += res[t]) %= P;
        }
    }
    rep(i, 1, q) printf("%d\n", ans[i] % P);
}