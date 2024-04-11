#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e3+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    sort(s.rbegin(), s.rend());
    if (s.back() != '0') {
        cout << "cyan\n";
        return;
    }
    s.pop_back();
    int sum = 0;
    bool e = 0;
    for (char c : s) {
        if ((c - '0') % 2 == 0) e = true;
        sum += c - '0';
    }
    if (sum % 3 == 0 && e) {
        cout << "red\n";
    } else {
        cout << "cyan\n";
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}