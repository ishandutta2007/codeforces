#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

void solve() {
    int n, r, b; cin >> n >> r >> b;
    vector<int> cnt(b + 1);
    for (int i = 0; i < r; i++) cnt[i % (b + 1)]++;
    for (int i = 0; i <= b; i++) {
        while (cnt[i]--) cout << 'R';
        if (i < b) cout << 'B';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}