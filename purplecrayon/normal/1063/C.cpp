#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e1+1, MOD = 998244353;

bool qry(int x, int y) {
    cout << x << ' ' << y << endl;
    string s; cin >> s;
    return s == "black";
}
void rec(int l, int r, int n, bool left) {
    if (!n) {
        if (l == 0) cout << l+1 << ' ' << 1 << ' ' << l+1 << ' ' << 2 << endl;
        else cout << l << ' ' << 1 << ' ' << l-1 << ' ' << 3 << endl;
        return;
    }
    int m = (l+r+1)/2;
    if (qry(m, 0) == left) rec(m, r, n-1, left);
    else rec(l, m, n-1, left);
}
void solve() {
    int n; cin >> n;
    rec(0, 1e9, n-1, qry(0, 0));
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}