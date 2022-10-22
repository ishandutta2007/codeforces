#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define fi first
#define se second

using namespace std;
using P = pair<int, int>;

map<int, pair<int, int>, greater<int>> p;

void cmax(int& a, int b) { if(a < b) a = b; }

int main() {
    int n, x, ans = 0, u, v;
    P d;
    cin >> n;
    rep(i, 1, n) scanf("%d", &x), p[x].se = i;
    while(p.begin()->first) {
        tie(x, d) = *p.begin(), p.erase(p.begin());
        for(int i = 1;; i <<= 1) if(i >= x) { x = i - x; break; }
        if(int t = p[x].fi + ++d.fi; p[x].se && t > ans) ans = t, u = p[x].se, v = d.se;
        p[x] = max(p[x], d);
    }
    printf("%d %d %d\n", u, v, ans);
}