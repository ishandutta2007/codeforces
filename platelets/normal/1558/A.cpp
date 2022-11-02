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
using ll = long long;
using lf = double;
// using P = pair<int, int>;
using V = vector<int>;
// using cmp = complex<lf>;

const int N = 2e5 + 5;
int a, b, ok[N];
void calc() {
    rep(a1, 0, a) {
        int a2 = a - a1, b2 = (a + b >> 1) - a2, b1 = b - b2;
        if(a2 >= 0 && b2 >= 0 && b1 >= 0) ok[a2 + b1] = 1;
    }
}
void solve() {
    scanf("%d%d", &a, &b);
    rep(i, 0, a + b) ok[i] = 0;
    calc(), swap(a, b), calc();
    int as = 0;
    rep(i, 0, a + b) as += ok[i];
    printf("%d\n", as);
    rep(i, 0, a + b) if(ok[i]) printf("%d ", i);
    puts("");
}
int main() {
#ifdef local
    // freopen(".in", "r", stdin);
#endif
    int T;
    for(cin >> T; T--; solve());
}