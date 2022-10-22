#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 5e3 + 5, P = 998244353;
int n, m, k;
ll S[N][N];

ll Pow(ll a, int n, ll r = 1) {
    for(; n; n >>= 1, a = a * a % P)
    if(n & 1) r = r * a % P;
    return r;
}
int main() {
    cin >> n >> m >> k;
    S[0][0] = 1;
    rep(i, 1, k) rep(j, 1, i) S[i][j] = (S[i - 1][j - 1] + j * S[i - 1][j]) % P;
    m = Pow(m, P - 2);
    ll p = 1, ans = 0;
    rep(i, 1, k) p = p * (n - i + 1) % P * m % P, (ans += S[k][i] * p) %= P;
    cout << ans;
}