#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3.5e4+10, MOD = 1e9+7;
const int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

string fix(string a) {
    reverse(a.begin(), a.end());
    while (sz(a) > 1 && a.back() == '0') a.pop_back();
    reverse(a.begin(), a.end());
    return a;
}
string cmp(string a, string b) {
    a = fix(a), b = fix(b);
    return sz(a) >= sz(b) ? a : b;
}
string rem(string s, vector<int> er) {
    int cnt[3]={};
    for (auto c : er) cnt[c]++;

    reverse(s.begin(), s.end());
    string t="";
    for (char c : s) {
        int x = (c-'0')%3;
        if (cnt[x]) cnt[x]--;
        else t += c;
    }
    reverse(t.begin(), t.end());
    if (*max_element(cnt, cnt+3)) return "";
    return t;
}
void pr(string s) {
    s = fix(s);
    if (!sz(s)) cout << -1 << '\n';
    else cout << s << '\n';
    exit(0);
}
void solve(){
    string s; cin >> s; 
    int n = sz(s), sm = 0;
    //1 -> 1, 2+2, 
    //2 -> 1+1, 2
    for (char c : s) sm = (sm+c-'0')%3;
    if (sm == 0) pr(s);
    if (sm == 1) pr(cmp(rem(s, {1}), rem(s, {2, 2})));
    if (sm == 2) pr(cmp(rem(s, {2}), rem(s, {1, 1})));
    assert(false);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}