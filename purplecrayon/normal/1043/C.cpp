#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve(){
    string s; cin >> s;
    vector<int> ans;
    for (auto c : s) {
        if (c == 'a') {
            if (sz(ans)) ans.back()^=1; ans.push_back(1);
        }
        else ans.push_back(0);
    }
    for (auto c : ans) cout << c << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}