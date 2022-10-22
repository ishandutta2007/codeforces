#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define upd(a, b) (a = max(a, b))

using namespace std;
using ll = long long;

const int N = 5005;

int n, z[N][N], f[N];
char s[N];
void solve() {
    scanf("%d%s", &n, s + 1);
    per(i, n, 1) per(j, n, i) z[i][j] = s[i] == s[j] ? (j <= n ? z[i + 1][j + 1] + 1 : 1) : 0;
    int as = 0; mem(f, 0);
    rep(i, 1, n) For(j, 0, i) {
        int l = z[j][i];
        if(i + l <= n && s[i + l] > s[j + l]) upd(as, upd(f[i], f[j] + n - i - l + 1));
    }
    printf("%d\n", as);
}
int main() {
    int T;
    for(cin >> T; T--; solve());
}