#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;
 
void solve() {
    string s; cin >> s;
    int c = min_element(s.begin(), s.end()) - s.begin();
    cout << s[c] << ' ';
    for (int i = 0; i < sz(s); i++) if (i != c) {
        cout << s[i];
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}