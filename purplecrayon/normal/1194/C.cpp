#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

void solve(){
    auto get_cnt = [&](string s) {
        ar<int, 26> ans; ans.fill(0);
        for (char c : s) ans[c-'a']++;
        return ans;
    };
    auto is_subseq = [&](string s, string t) {
        int c = 0;
        for (int i = 0; i < sz(s); i++) {
            while (c < sz(t) && t[c] != s[i]) c++;
            if (c >= sz(t)) return false;

            c++;
        }
        return true;
    };

    string s, t, p; cin >> s >> t >> p;
    auto a = get_cnt(s), b = get_cnt(t), c = get_cnt(p);
    if (!is_subseq(s, t)) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] > b[i]) {
            cout << "NO\n";
            return;
        }
        if (b[i]-a[i] > c[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}