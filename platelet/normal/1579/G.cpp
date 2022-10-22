#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 10005;

int n, a[N], f[N][2005];

void solve() {
    cin >> n;
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(i, 0, 2000) f[0][i] = i;
    rep(i, 1, n) rep(j, 0, 2000) {
        f[i][j] = 1e9;
        if(j + a[i] <= 2000) f[i][j] = min(f[i][j], f[i - 1][j + a[i]]);
        if(j >= a[i]) f[i][j] = min(f[i][j], f[i - 1][j - a[i]]);
        f[i][j] = max(f[i][j], j);
    }
    cout << *min_element(f[n], f[n] + 2001) << '\n';
}
int main() {
    int T;
    for(cin >> T; T--; solve());
}