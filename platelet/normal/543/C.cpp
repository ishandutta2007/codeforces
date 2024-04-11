#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define upd(a, b) (a = min(a, b))

using namespace std;

char s[20][25];

int n, m, mi[20], ma[20][26], su[20][26];
int st[20][26], f[1 << 20];

int main() {
#ifdef local
    freopen(".in", "r", stdin);
#endif
    mem(mi, 63), mem(f, 63);
    cin >> n >> m;
    For(i, 0, n) scanf("%s", s[i]);
    For(i, 0, n) For(j, 0, m) {
        int c = s[i][j] - 97, t;
        scanf("%d", &t);
        upd(mi[i], t), st[j][c] |= 1 << i;
        su[j][c] += t, ma[j][c] = max(ma[j][c], t);
    }
    mem(f, 63), f[0] = 0;
    For(S, 0, 1 << n) {
        For(i, 0, n) if(~S >> i & 1) upd(f[S | 1 << i], f[S] + mi[i]);
        For(i, 0, m) For(j, 0, 26) upd(f[S | st[i][j]], f[S] + su[i][j] - ma[i][j]);
    }
    cout << f[(1 << n) - 1];
    return 0;
}