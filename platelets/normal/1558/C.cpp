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

const int N = 2030;

int n, a[N];

void rev(int n) {
    reverse(a + 1, a + n + 1), printf("%d\n", n);
}
void solve() {
    cin >> n;
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(i, 1, n) if(a[i] % 2 != i % 2) return void(puts("-1"));
    cout << n / 2 * 5 << endl;
    for(int i = n; i > 1; i -= 2) {
        #define X find(a + 1, a + n + 1, i) - a
        #define Y find(a + 1, a + n + 1, i - 1) - a
        rev(X), rev(Y - 1), rev(Y + 1), rev(3), rev(i);
    }
}
int main() {
#ifdef local
    // freopen(".in", "r", stdin);
#endif
    int T;
    for(cin >> T; T--; solve());
}