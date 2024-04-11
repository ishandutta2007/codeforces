#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 1e9+7;

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
    vector<int> a(n); for (auto& c : a) cin >> c;

    map<int, int> mp;
    for (auto& c : a) mp[c]++;
    int cc = 0;
    for (auto& c : mp) c.second = cc++;

    FT<int> bit(cc);
    ll ans = 0;
    for (auto c : a) {
        int less = bit.qry(0, mp[c]-1);
        int more = bit.qry(mp[c]+1, cc-1);
        bit.upd(mp[c], 1);
        ans += min(less, more);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}