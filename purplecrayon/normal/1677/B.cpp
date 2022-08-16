#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e6+10, MOD = 1e9+7;

template<class T>
struct FT {
    vector<T> bit;
    FT(int n) : bit(n) {}
    FT(){}
    void upd(int i, T x) {
        for (; i < sz(bit); i |= i+1) bit[i] += x;
    }
    T qry(int r) {
        T ans = T();
        for (++r; r > 0; r &= r-1) ans += bit[r-1];
        return ans;
    }
    T qry(int l, int r) {
        return qry(r)-qry(l-1);
    }
};
void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    vector<int> sum(n * m);
    FT<int> sum_mod(m);
    auto add = [&](int l, int r) {
        sum[l]++;
        if (r < n * m - 1) sum[r + 1]--;
    };

    auto _add_mod = [&](int l, int r, int d) {
        if (l > r) return;
        sum_mod.upd(l, +d);
        if (r < m - 1) sum_mod.upd(r + 1, -d);
    };
    auto add_mod = [&](int l, int r) {
        if (l <= r) _add_mod(l, r, +1);
        else _add_mod(0, m-1, +1), _add_mod(r+1, l-1, -1);
    };

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) { // cols
            // i * m + j
            if (s[i * m + j] == '1') {
                add(i * m + j, n * m - 1);
                break;
            }
        }
    }

    int last = -1;
    int carry = 0;
    for (int i = 0; i < n * m; i++) {
        if (i) sum[i] += sum[i-1];
        int ans = sum[i];
        if (s[i] == '1') {
            if (last == -1 || i - last >= m) { // always in a different row, I'm always +1
                carry++;
            } else {
                // last == m - 1 % m
                // last - m + 1 % m
                // i == m - 1 % m
                // i - m + 1 % m
                int d = i - last;
                int over = m - d;
                add_mod((i + over) % m, (i + over + d - 1 + m) % m);
            }
            last = i;
        }
        ans += carry;
        ans += sum_mod.qry(i % m);
        cout << ans << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}