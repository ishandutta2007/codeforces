#include <bits/stdc++.h>
#include <intrin.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using uint = uint32_t;
using ull = uint64_t;

int n, m, a[10005], b;
ull P, im;
vector<int> v, d;

uint mul(uint a, uint b) {
    ull c = (ull)a * b, z;
    _umul128(c, im, &z);
    uint x = (uint)c - (uint)z * P;
    return x < P ? x : x + P;
}
uint Pow(uint a, int n, uint r = 1) {
    for(; n; n >>= 1, a = mul(a, a))
    if(n & 1) r = mul(r, a);
    return r;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> P, im = ~0ULL / P + 1;
    int t = P - 1;
    for(int i = 2; i * i <= t; i++) if(t % i == 0) {
        v.pb(i);
        while(t % i == 0) t /= i;
    }
    if(t > 1) v.pb(t);
    for(int i = 1; i * i < P; i++) if((P - 1) % i == 0)
        if(d.pb(i); i * i < P - 1) d.pb((P - 1) / i);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> t, b = gcd(b, t);
    rep(i, 1, n) {
        a[i] = Pow(a[i], b), t = P - 1;
        for(int p : v) while(t % p == 0 && Pow(a[i], t / p) == 1) t /= p;
        a[i] = t;
    }
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1;   
    int ans = 0;
    for(int x : d) if([&]() { rep(i, 1, n) if(a[i] % x == 0) return 1; return 0; }()) {
        int phi = x;
        for(int p : v) if(phi % p == 0) phi -= phi / p;
        ans += phi;
    }
    cout << ans;
}