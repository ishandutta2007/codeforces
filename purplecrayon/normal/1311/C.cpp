#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> cnt(n);
    cnt[n-1] = 1;
    while (m--) {
        int p; cin >> p, --p;
        cnt[p]++;
    }
    for (int i = n-2; i >= 0; i--) cnt[i] += cnt[i+1];
    vector<int> ans(26);
    for (int i = 0; i < n; i++) ans[s[i] - 'a'] += cnt[i];
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}