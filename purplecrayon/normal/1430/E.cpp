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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string t = s;
    reverse(t.begin(), t.end());

    vector<int> loc[26];
    for (int i = 0; i < n; i++) loc[t[i] - 'a'].push_back(i);

    vector<int> move(n);

    int cnt[26] = {};
    for (int i = 0; i < n; i++) {
        move[i] = loc[s[i] - 'a'][cnt[s[i] - 'a']++];
    }

    FT<int> bit(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += bit.qry(move[i], n-1);
        bit.upd(move[i], 1);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}