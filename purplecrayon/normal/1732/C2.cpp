#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<ll> sum(n), pre_xor(n);
    for (int i = 0; i < n; i++) {
        pre_xor[i] = sum[i] = a[i];
        if (i) pre_xor[i] ^= pre_xor[i-1], sum[i] += sum[i-1];
    }
    auto f = [&](int L, int R) {
        return (sum[R] - (L ? sum[L-1] : 0)) - (pre_xor[R] ^ (L ? pre_xor[L-1] : 0));
    };
    vector<int> non_z;
    for (int i = 0; i < n; i++) if (a[i]) non_z.push_back(i);

    while (q--) {
        int l, r; cin >> l >> r, --l, --r;
        ar<ll, 4> ans{0, -1, l, l};

        vector<int> one{l};
        int start_one = upper_bound(non_z.begin(), non_z.end(), l) - non_z.begin();
        for (int i = start_one; i < min(start_one + 32, sz(non_z)); i++) {
            if (non_z[i] > r) break;
            one.push_back(non_z[i]);
        }

        vector<int> two{r};
        int start_two = lower_bound(non_z.begin(), non_z.end(), r) - non_z.begin() - 1;
        for (int i = start_two; i >= max(start_two - 32, 0); i--) {
            if (non_z[i] < l) break;
            two.push_back(non_z[i]);
        }

        for (int L : one) {
            for (int R : two) if (L <= R) {
                ans = max(ans, {f(L, R), -(R - L + 1), L, R});
            }
        }
        cout << ans[2]+1 << ' ' << ans[3]+1 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}