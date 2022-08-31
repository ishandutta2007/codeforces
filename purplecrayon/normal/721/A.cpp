#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> ans;
    for (int i = 0; i < n; ) {
        if (s[i] == 'B') {
            int j = i;
            while (j < n && s[j] == 'B') j++;

            ans.push_back(j-i);
            i = j;
        } else i++;
    }
    cout << sz(ans) << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}