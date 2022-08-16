#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e3+10, MOD = 1e9+7;

string norm(string s) {
    reverse(s.begin(), s.end());
    while (sz(s) > 1 && s.back() == '0') s.pop_back();
    reverse(s.begin(), s.end());
    return s;
}
bool eq(string a, string b) {
    return norm(a) == norm(b);
}
string inc(string s) {
    s = norm(s);
    string ans = "0" + s;
    for (int i = sz(ans) - 1; i >= 0; i--) {
        if (ans[i] == '0') {
            ans[i] = '1';
            break;
        } 
        ans[i] = '0';
    }
    return norm(ans);
}
string dec(string s) {
    s = norm(s);
    assert(s != "0");
    string ans = s;
    for (int i = sz(ans) - 1; i >= 0; i--) {
        if (ans[i] == '1') {
            ans[i] = '0';
            break;
        }
        ans[i] = '1';
    }
    return norm(ans);
}
void solve() {
    int n; cin >> n;
    string l, r; cin >> l >> r;
    if (l[0] != r[0]) {
        cout << string(n, '1') << '\n';
        return;
    }
    if (r[n-1] == '1') {
        cout << r << '\n';
        return;
    }
    if (l == r || eq(l, dec(r))) {
        cout << r << '\n';
    } else {
        cout << inc(r) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}