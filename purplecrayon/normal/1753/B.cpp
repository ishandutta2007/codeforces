#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> cnt(x + 1);
    while (n--) {
        int y; cin >> y;
        cnt[y]++;
    }
    for (int i = 1; i < x; i++) {
        if (cnt[i] % (i + 1)) {
            cout << "No\n";
            return;
        }

        cnt[i + 1] += cnt[i] / (i + 1);
    }
    cout << "Yes\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}