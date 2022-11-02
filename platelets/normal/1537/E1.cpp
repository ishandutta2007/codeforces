#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 5005;

string s, as;
int n, m;
int main() {
#ifdef local
    freopen(".in", "r", stdin);
#endif
    cin >> n >> m >> s;
    as = s;
    rep(i, 1, n) {
        string t = s.substr(0, i);
        if(t + as < as + t) as = t;
    }
    For(i, 0, m) putchar(as[i % as.size()]);
    return 0;
}