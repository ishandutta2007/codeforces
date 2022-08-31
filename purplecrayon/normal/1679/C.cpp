#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;
const ll INF = 2e18;

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
    int n, q; cin >> n >> q;
    FT<int> row(n), col(n);
    vector<int> cnt_row(n), cnt_col(n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y, --x, --y;
            row.upd(x, cnt_row[x] ? -1 : 0);
            cnt_row[x]++;
            row.upd(x, cnt_row[x] ? +1 : 0);

            col.upd(y, cnt_col[y] ? -1 : 0);
            cnt_col[y]++;
            col.upd(y, cnt_col[y] ? +1 : 0);
        } else if (t == 2) {
            int x, y; cin >> x >> y, --x, --y;
            row.upd(x, cnt_row[x] ? -1 : 0);
            cnt_row[x]--;
            row.upd(x, cnt_row[x] ? +1 : 0);

            col.upd(y, cnt_col[y] ? -1 : 0);
            cnt_col[y]--;
            col.upd(y, cnt_col[y] ? +1 : 0);
        } else {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2, --x1, --y1, --x2, --y2;
            bool ans = row.qry(x1, x2) == x2 - x1 + 1 || col.qry(y1, y2) == y2 - y1 + 1;
            cout << (ans ? "Yes\n" : "No\n");
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}