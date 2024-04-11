#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 998244353;

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

int n, m;
int a[MAXN], b[MAXN];

ll get(int x) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < x) b[i] = 1;
        else b[i] = -1;
    }
    FT<int> bit(2*n+1);
    int sum = 0;
    bit.upd(sum + n, +1);
    for (int i = 0; i < n; i++) {
        sum += b[i];
        ans += bit.qry(-n + n, sum + n);
        bit.upd(sum + n, +1);
    }
    return ans;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll one = get(m + 1);
    ll two = get(m);
    cout << one - two << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}