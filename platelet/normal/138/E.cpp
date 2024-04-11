#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

int n, K, L, R, w[100005], cnt;
long long ans;
char s[100005];

struct {
    char c; int l, r;
    int pl = 1, pr = 1, cL, cR;
    void read() { scanf("%s%d%d", &c, &l, &r); }
    void mov(int i) {
        if(s[i] == c) cL++, cR++;
        auto upd = [&](int j, int v) {
            cnt -= L <= w[j] && w[j] <= R, w[j] += v;
            cnt += L <= w[j] && w[j] <= R;
        };
        while(pl <= i && cL > r) cL -= s[pl] == c, upd(pl++, -1);
        while(pr <= i && cR >= l) cR -= s[pr] == c, upd(pr++, 1);
    }
} a[505];

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    cin >> K >> L >> R;
    rep(i, 1, K) a[i].read();
    rep(i, 1, n) {
        cnt += !L;
        rep(j, 1, K) a[j].mov(i);
        ans += cnt;
    }
    cout << ans;
}