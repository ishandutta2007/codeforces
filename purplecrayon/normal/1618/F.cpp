#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

string bin_str(ll x) {
    string ans;
    while (x) {
        ans += char('0' + x % 2);
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
bool contains(string one, string two) { // one contains two
    for (int i = 0; i + sz(two) <= sz(one); i++) {
        if (one.substr(i, sz(two)) == two) {
            return 1;
        }
    }
    return 0;
}
bool test(string one, string two) {
    for (int rep = 0; rep < 2; rep++) {
        for (int i = 0; i + sz(one) <= sz(two); i++) {
            bool bad = 0;
            for (int j = 0; j < i; j++) if (two[j] == '0') {
                bad = 1;
            }
            for (int j = i + sz(one); j < sz(two); j++) if (two[j] == '0') {
                bad = 1;
            }
            if (two.substr(i, sz(one)) != one)
                bad = 1;

            if (!bad) return 1;
        }
        reverse(one.begin(), one.end());
    }
    return 0;
}
void solve() {
    ll x, y; cin >> x >> y;
    if (x == y) {
        cout << "YES\n";
        return;
    }
    if (y % 2 == 0) {
        cout << "NO\n";
        return;
    }
    string one = bin_str(x), two = bin_str(y);
    string copy_one = one;
    while (copy_one.back() == '0') copy_one.pop_back();
    if (test(copy_one, two)) {
        cout << "YES\n";
        return;
    }
    string copy_two = one; copy_two += "1";
    reverse(copy_two.begin(), copy_two.end());
    if (test(copy_two, two)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}