#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first 
#define se second
#define all(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())
#define mid ((l + r) / 2)
#define lc o * 2
#define rc o * 2 + 1
#define lch l, mid, lc
#define rch mid + 1, r, rc
#define cmi(a, b) (a = min(a, b))
#define cma(a, b) (a = max(a, b))
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define pop __builtin_popcount
#define llpop __builtin_popcountll
#define ctz __builtin_ctz
#define llctz __builtin_ctzll
#define clz __builtin_clz
#define llclz __builtin_clzll
#define par __builtin_parity
#define llpar __builtin_parityll

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned ll;
using lf = double;
// using P = pair<int, int>;
using V = vector<int>;
// using cmp = complex<lf>;

const int N = 4e6 + 5;

int n, P, f[N], g[N];

void solve() {
    cin >> n >> P;
    f[1] = 1;
    rep(i, 1, n) {
        (f[i] += f[i - 1]) %= P, (g[i] += g[i - 1]) %= P, (f[i] += g[i]) %= P;
        rep(j, 2, n / i) (g[i * j] += f[i]) %= P, (g[min(i * j + j, n + 1)] -= f[i]) %= P;
        if(i < n) (f[i] += f[i - 1]) %= P;
    }
    cout << (f[n] + P) % P;
}
int main() {
#ifdef local
    // freopen(".in", "r", stdin);
#endif
    // int T;
    // for(cin >> T; T--; solve());
    solve();
}