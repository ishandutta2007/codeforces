#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

int c2(int x) {
    return x * (x - 1) / 2;
}
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
    }
    cout << c2(10 - n) * 6 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}