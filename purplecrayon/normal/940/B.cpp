#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;
const ll INF = 9e18+10;

int n, k, a, b;

ll rec(int c) {
    if (c <= 1) return 0;
    return min((long long) a * (c - 1), k > 1 ? (long long) a * (c % k) + b + rec(c / k) : INF);
}
void solve() {
    cin >> n >> k >> a >> b;
    cout << rec(n) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}