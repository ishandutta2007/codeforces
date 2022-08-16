#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;
const ll INF = 1e12+10;

void solve() {
    string s; cin >> s;
    set<char> has;
    for (char c : s) {
        if ('a' <= c && c <= 'z') {
            has.insert(c - 'a' + 'A');
        } else {
            if (!has.count(c)) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}