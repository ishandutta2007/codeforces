#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (k > n) {
        cout << s;
        char c = *min_element(s.begin(), s.end());
        for (int rep = 0; rep < k - n; rep++) cout << c;
        cout << '\n';
        return;
    }
    set<char> st;
    for (char c : s) st.insert(c);
    for (int i = k-1; i >= 0; i--) if (s[i] != *st.rbegin()) {
        string ans = s.substr(0, k);
        ans[i] = *st.upper_bound(s[i]);
        for (int j = i+1; j < k; j++) ans[j] = *st.begin();
        cout << ans << '\n';
        break;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}