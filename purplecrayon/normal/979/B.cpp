#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int get(string s, int x) {
    map<char, int> cnt;
    for (auto c : s) cnt[c]++;
    int mx = 0;
    for (auto c : cnt) mx = max(mx, c.second);
    int oth = sz(s)-mx;
    if (x <= oth) return sz(s)-(oth-x);
    return mx == sz(s) ? sz(s)-(x==1) : sz(s);
}
const string name[3]={"Kuro", "Shiro", "Katie"};
void solve(){
    int x; cin >> x;
    vector<string> s(3);
    for (auto& c : s) cin >> c;
    vector<pair<int, int>> a(3);
    for (int i = 0; i < 3; i++) a[i] = {get(s[i], x), i};
    sort(a.rbegin(), a.rend());
    if (a[0].first == a[1].first) cout << "Draw\n";
    else cout << name[a[0].second] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}