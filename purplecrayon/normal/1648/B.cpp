#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n); for (auto& x : a) cin >> x;

    vector<int> has(c + 1);
    for (int x : a) has[x]++;
    for (int i = 1; i <= c; i++) if (has[i] > 1 && !has[1]) {
        cout << "No\n";
        return;
    }

    vector<int> sum(c + 1);
    for (int i = 0; i <= c; i++) {
        sum[i] = has[i] + (i ? sum[i-1] : 0);
    }

    auto qry = [&](int L, int R) {
        bool ans = sum[R] - (L ? sum[L-1] : 0);
        return ans;
    };

    for (int i = 2; i <= c; i++) if (has[i]) {
        for (int j = i; j <= c; j += i) {
            int L = j, R = min(c, j + i - 1);
            int me = j / i;
            if (!has[me] && qry(L, R)) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}