#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

bool r[10005], f[10005];

int ask(int a, int b, int c) {
    printf("? %d %d %d\n", a, b, c), fflush(stdout);
    int res;
    scanf("%d", &res);
    if(res == -1) exit(0);
    return res;
}
int get(bool t, int x, int i) {
    int S = (ask(i, i + 1, x) ^ t) | (ask(i + 1, i + 2, x) ^ t) << 1;
    f[i] = f[i + 1] = f[i + 2] = !t;
    if(S == 1) f[i] = t;
    if(S == 2) f[i + 2] = t;
    if(S == 3) f[i + 1] = t;
    return S;
}
int main() {
    int T, n, p[2];
    for(cin >> T; T--;) {
        cin >> n;
        for(int i = 1; i <= n; i += 3)
            r[i] = ask(i, i + 1, i + 2), p[r[i]] = i;
        if(!get(0, p[1], p[0])) get(0, p[1] + 1, p[0]);
        p[0] = max_element(f + p[0], f + p[0] + 3) - f;
        get(1, p[0], p[1]);
        p[1] = min_element(f + p[1], f + p[1] + 3) - f;
        for(int i = 1; i <= n; i += 3) get(r[i], p[!r[i]], i);
        int cnt = 0;
        rep(i, 1, n) cnt += f[i];
        printf("! %d ", cnt);
        rep(i, 1, n) if(f[i]) printf("%d ", i);
        puts(""), fflush(stdout);
    }
}