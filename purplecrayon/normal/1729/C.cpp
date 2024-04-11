#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    int n = sz(s);
    int d = (s[0] < s[n-1] ? +1 : -1);

    vector<int> ans;
    for (char c = s[0]; c != s[n-1] + d; c += d) {
        for (int i = 0; i < n; i++) if (s[i] == c) 
            ans.push_back(i);
    }
    cout << abs(s[0] - s[n-1]) << ' ' << sz(ans) << '\n';
    for (int x : ans) cout << x+1 << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}