#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

// x, x*(x-1)/2 - (< x)

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

int n, ans[MAXN];
ll a[MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    FT<ll> bit(n);
    for (int i = n-1; i >= 0; i--) {
        // largest thing such that it's valid
        int lo = 1, hi = n+1, mid = (lo + hi) / 2;
        while (lo < mid && mid < hi) {
            ll cur = (long long) mid * (mid - 1) / 2 - bit.qry(mid-1);
            if (cur <= a[i]) lo = mid;
            else hi = mid;
            mid = (lo + hi) / 2;
        }
        ans[i] = lo;
        bit.upd(lo, lo);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}