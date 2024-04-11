#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "a\n";
        return;
    }
    if (n%2 == 0) cout << (string(n/2, 'a') + "b" + string(n/2-1, 'a')) << '\n';
    else cout << string(n/2, 'a') + "bc" + string(n/2-1, 'a') << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}