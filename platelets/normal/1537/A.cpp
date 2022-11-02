#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

int T, n;

void solve() {
    scanf("%d", &n);
    int x, su = 0;
    while(n--) scanf("%d", &x), su += x - 1;
    if(!su) puts("0");
    else if(su < 0) puts("1");
    else printf("%d\n", su);
}
int main() {
#ifdef local
    freopen(".in", "r", stdin);
#endif
    int T; for(cin >> T; T--;)
    solve();
}