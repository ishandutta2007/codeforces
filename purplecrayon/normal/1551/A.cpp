#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    if (n%3 == 0) cout << n/3 << ' ' << n/3 << '\n';
    if (n%3 == 1) cout << n/3+1 << ' ' << n/3 << '\n';
    if (n%3 == 2) cout << n/3 << ' ' << n/3+1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}