#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

string ts(int x) {
    string ans = to_string(x);
    while (sz(ans) < 2) ans = "0" + ans;
    return ans;
}
void solve() {
    string s; int x; cin >> s >> x;
    for (auto& c : s) c -= '0';
    int c = (s[0] * 10 + s[1]) * 60 + (s[3] * 10 + s[4]);
    set<int> st;
    while (!st.count(c)) {
        st.insert(c);
        c += x;
        c %= 1440;
    }
    int ans = 0;
    for (int a : st) {
        int one = a % 60;
        int two = (a - one) / 60;
        string x = ts(one), y = ts(two);
        reverse(y.begin(), y.end());

        if (x == y) ans++;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}