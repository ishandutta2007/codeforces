#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

int n, m; ll k, f[205];
string F[16];

ll calc(string s) {
    mem(f, 0);
    rep(i, 0, 15) For(j, 0, F[i].size())
        f[i] += F[i].substr(j, s.size()) == s;
    rep(i, 16, n) f[i] = min(f[i - 2] + f[i - 1] + (i & 1 ? f[15] - f[13] - f[14] : f[14] - f[12] - f[13]), k);
    return f[n];
}
int main() {
    cin >> n >> k >> m;
    F[0] = "0", F[1] = "1";
    rep(i, 2, 15) F[i] = F[i - 2] + F[i - 1];
    string ans;
    while(m--) {
        if(ans.size() && F[min(n, 15)].ends_with(ans) && !--k) break;
        ll cnt = calc(ans + "0");
        if(cnt < k) k -= cnt, ans += '1';
        else ans += '0';
    }
    cout << ans;
}