#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 998244353;

int n;
vector<pair<int, int>> ans;

void rec(int l, int r) {
    int len = r-l+1;
    assert(__builtin_popcount(len) == 1);
    if (len == 1) return;

    int m = (l+r)/2;
    rec(l, m), rec(m+1, r);

    for (int i = 0; i < (len / 2); i++) {
        ans.emplace_back(l+i, m+1+i);
    }
}
void solve() {
    cin >> n;
    int L = 1;
    while (L <= n) L *= 2;
    L /= 2;

    if (L == n) rec(0, n-1);
    else rec(0, L-1), rec(n-L, n-1);

    cout << sz(ans) << '\n';
    for (auto [a, b] : ans) cout << a+1 << ' ' << b+1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}