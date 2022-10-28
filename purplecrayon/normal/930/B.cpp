#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+1, MOD = 998244353;

using ld = long double;

void solve() {
    string s; cin >> s;
    int n = sz(s);
    vector<int> loc[26];
    for (int i = 0; i < n; i++) loc[s[i]-'a'].push_back(i);

    int ans = 0;
    for (int k = 0; k < 26; k++) {
        int mx = 0;
        for (int i = 1; i < n; i++) {
            int cnt[26]={};
            for (int c : loc[k]) cnt[s[(i+c)%n]-'a']++;
            int cur = 0;
            for (auto c : cnt) if (c == 1) cur++;
            mx = max(mx, cur);
        }
        ans += mx;
    }
    cout << fixed << setprecision(10) << ld(ans)/ld(n) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}