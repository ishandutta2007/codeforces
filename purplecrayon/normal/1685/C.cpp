#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

bool check(string s) {
    int bal = 0;
    for (char c : s) {
        bal += c == '(' ? +1 : -1;
        if (bal < 0) return 0;
    }
    return 1;
}
bool one(string s) {
    int n = sz(s);
    vector<int> me(n);
    int bal = 0;
    int L = sz(s);
    int R = -1;
    for (int i = 0; i < sz(s); i++) {
        bal += s[i] == '(' ? +1 : -1;
        me[i] = bal;
        if (bal < 0) {
            L = min(L, i);
            R = max(R, i);
        }
    }
    if (L == sz(s)) return 0; // already balanced
    int one = max_element(me.begin(), me.begin() + L) - me.begin();
    if (me[one] < 0) one = 0;
    else one++;
    int two = max_element(me.begin() + R, me.end()) - me.begin();
    reverse(s.begin() + one, s.begin() + two + 1);
    if (check(s)) {
        cout << 1 << '\n' << one+1 << ' ' << two+1 << '\n';
        return 1;
    }
    return 0;
}
void solve() {
    int n; cin >> n; n *= 2;
    string s; cin >> s;
    if (check(s)) {
        cout << 0 << '\n';
        return;
    }
    if (one(s)) return;
    vector<int> me(n);
    int bal = 0;
    for (int i = 0; i < sz(s); i++) {
        bal += s[i] == '(' ? +1 : -1;
        me[i] = bal;
    }
    cout << 2 << '\n';
    int loc = max_element(me.begin(), me.end()) - me.begin();
    cout << 1 << ' ' << loc+1 << '\n' << loc+2 << ' ' << n << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}