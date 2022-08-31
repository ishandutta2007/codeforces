#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e3+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    if (n == 1) {
        cout << -1 << '\n';
    } else {
        cout << 5;
        for (int i = 0; i < n-1; i++) cout << 3;
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}