#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    for (char c : s) cnt += (c == '1');

    int good = 0;
    for (int i = n-1; i >= n-cnt; i--) {
        good += s[i] == '1';
    }
    int bad = cnt - good;
    if (!bad) {
        cout << 0 << '\n';
        return;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (i < n - cnt) {
            if (s[i] == '1') ans.push_back(i);
        } else {
            if (s[i] == '0') ans.push_back(i);
        }
    }
    cout << 1 << '\n';
    cout << sz(ans) << ' ';
    for (auto c : ans) cout << c+1 << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}