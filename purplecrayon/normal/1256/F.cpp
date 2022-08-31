#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

ar<int, 26> cnt(string s) {
    ar<int, 26> ans; ans.fill(0);
    for (auto c : s) ans[c-'a']++;
    return ans;
}
void solve(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if (cnt(s) != cnt(t)){ cout << "NO\n"; return; }
    for (int x : cnt(s)) if (x > 1){ cout << "YES\n"; return; }
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) {
        ans ^= s[i] > s[j];
        ans ^= t[i] > t[j];
    }
    if (!ans) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}