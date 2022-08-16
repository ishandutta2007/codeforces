#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;
 
// bits don't really interact
// you need the number of on bits to be divisible by k

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    int g = 0;
    for (int b = 0; b < 30; b++) {
        int cnt = 0;
        for (auto& c : a) {
            if ((c >> b) & 1) cnt++;
        }
        g = std::gcd(g, cnt);
    }
    for (int i = 1; i <= n; i++) {
        if (g % i == 0) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}