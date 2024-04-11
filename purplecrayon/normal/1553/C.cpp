#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;


int get(string s) {
    int cnt[2]={};
    for (int i = 0; i < sz(s); i++) {
        cnt[i&1] += s[i]-'0';

        int left[2]={};
        for (int j = i+1; j < sz(s); j++) left[j&1]++;

        if (cnt[0]+left[0] < cnt[1] || cnt[1]+left[1] < cnt[0]) return i+1;
    }
    return sz(s);
}
void solve(){
    string s; cin >> s;
    int ans = MOD;
    for (char c : {0, 1}) {
        string t = s;
        for (int i = 0; i < sz(t); i++) if (t[i] == '?') {
            if ((i&1) == c) t[i] = '0';
            else t[i] = '1';
        }
        ans = min(ans, get(t));
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}