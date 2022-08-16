#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

string gen(string s, string ord) {
    string ans = "";
    int i = 0;
    while (sz(s)) {
        ans += s;
        s.erase(remove(s.begin(), s.end(), ord[i++]), s.end());
    }
    return ans;
}
void solve(){
    string t; cin >> t;
    int cnt[26]={};
    for (char c : t) cnt[c-'a']++;

    int last[26]; memset(last, -1, sizeof(last));
    for (int i = 0; i < sz(t); i++) last[t[i]-'a'] = i;

    vector<int> ord;
    for (int i = 0; i < 26; i++) if (last[i] != -1) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int a, int b){ return last[a] < last[b]; });

    string rem="";

    int tot_len = 0;
    for (int i = 0; i < sz(ord); i++) {
        int cnt_part = cnt[ord[i]];
        if (cnt_part%(i+1)) {
            cout << -1 << '\n';
            return;
        }
        cnt_part /= (i+1);

        tot_len += cnt_part;
        rem += char('a'+ord[i]);
    }
    string s = string(t.begin(), t.begin()+tot_len);
    if (gen(s, rem) == t) cout << s << ' ' << rem << '\n';
    else cout << -1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}