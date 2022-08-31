#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = MOD;
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0, c = 0;
        for (int j = i; j < n && j < i+10; j++) {
            if (s[j] == 'a') a++;
            if (s[j] == 'b') b++;
            if (s[j] == 'c') c++;

            if (a > b && a > c && j - i + 1 >= 2) {
                ans = min(ans, j - i + 1);
            }
        }
    }
    if (ans == MOD) ans = -1;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}