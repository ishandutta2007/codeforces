#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e6+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    int n = sz(s);

    int a = 0;
    for (char c : s) a += c - 'a' + 1;
    if (n % 2 == 0) cout << "Alice " << a << '\n';
    else {
        int b = min(s[0], s[n-1]) - 'a' + 1;
        a -= b;
        if (a > b) cout << "Alice " << a - b << '\n';
        else cout << "Bob " << b - a << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}