#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    string a, b; cin >> a >> b;
    int one = 0;
    for (char c : b) one += c - '0';

    int n = sz(a);
    vector<int> two(n);
    for (int i = 0; i < sz(two); i++) {
        two[i] = a[i] - '0';
        if (i) two[i] += two[i-1];
    }

    int ans = 0;
    for (int i = 0; i + sz(b) <= sz(a); i++) {
        int me = two[i + sz(b) - 1] - (i ? two[i-1] : 0);
        if ((me + one) % 2 == 0) ans++;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}