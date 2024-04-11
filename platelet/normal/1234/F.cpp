#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define upd(a, b) (a = max(a, b))

using namespace std;

const int N = 1 << 20;

int n, f[N];
char s[N];

int main() {
#ifdef local
    freopen("in", "r", stdin);
#endif
    scanf("%s", s + 1), n = strlen(s + 1);
    rep(i, 1, n) {
        int S = 0;
        per(j, i, 1) {
            if(S >> s[j] - 97 & 1) break;
            S |= 1 << s[j] - 97, f[S] = __builtin_popcount(S);
        }
    }
    rep(i, 0, 19) For(S, 0, N) if(S >> i & 1) upd(f[S], f[S ^ 1 << i]);
    int as = 0;
    For(S, 0, N) upd(as, f[S] + f[N - 1 ^ S]);
    cout << as;
}