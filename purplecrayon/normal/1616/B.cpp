#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (s[0] == s[1]) {
        cout << s[0] << s[1] << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (i == n-1 || s[i] < s[i+1]) {
            for (int j = 0; j <= i; j++) {
                cout << s[j];
            }
            for (int j = i; j >= 0; j--) cout << s[j];
            cout << '\n';
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}