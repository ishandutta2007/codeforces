#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

//disjoint -> greedily taking the first occurrence should be fine
//abababababa
//^--------^
//
//dp on suffix, eitehr make this the next occurence, or just skip it
//

int n, m;
string s;
int ps[MAXN], qs[MAXN];
ar<int, 2> dp[MAXN];

void solve(){
    cin >> n >> s >> m;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') ps[i] += i&1;
        else if (s[i] == 'b') ps[i] += i&1^1;
        else qs[i]++;

        if (i) ps[i] += ps[i-1], qs[i] += qs[i-1];
    }
    auto get = [&](int l, int r) -> int { //-1 if no match, num replacements if yes
        if (r-l+1 != m) return -1;

        int sm = ps[r]-(l?ps[l-1]:0), q = qs[r]-(l?qs[l-1]:0);
        int num_closed = r-l+1-q;
        if ((l&1) && sm != num_closed) return -1;
        if ((l&1^1) && sm != 0) return -1;
        return q;
    };
    auto mn = [&](ar<int, 2> a, ar<int, 2> b) {
        if (a[0] != b[0]) return max(a, b);
        else return min(a, b);
    };
    fill(dp, dp+n+1, ar<int, 2>{0, 0});

    for (int i = n-m; i >= 0; i--) {
        int cost = get(i, i+m-1);

        if (cost != -1) {
            ar<int, 2> nxt = dp[i+m];
            dp[i] = mn(dp[i], {nxt[0]+1, cost+nxt[1]});
        }
        dp[i] = mn(dp[i], dp[i+1]);
    }
    cout << dp[0][1] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}