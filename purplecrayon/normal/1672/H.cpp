#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

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

int n, q;
string s;

void solve() {
    cin >> n >> q >> s;
    FT<int> z(n), o(n);
    for (int i = 1; i < n; i++) if (s[i] == s[i-1]) {
        if (s[i] == '0') z.upd(i, +1);
        else o.upd(i, +1);
    }
    while (q--) {
        int l, r; cin >> l >> r, --l, --r;
        cout << max(z.qry(l+1, r), o.qry(l+1, r))+1 << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}