#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    int k1; cin >> k1;
    queue<int> a, b;
    for (int i = 0; i < k1; i++) {
        int x; cin >> x;
        a.push(x);
    }
    int k2; cin >> k2;
    for (int i = 0; i < k2; i++) {
        int x; cin >> x;
        b.push(x);
    }
    const int MAGIC = 2e3;

    int REP = 0;
    while (sz(a) && sz(b)) {
        REP++;
        if (REP > MAGIC) {
            cout << -1 << '\n';
            return;
        }
        int x = a.front(), y = b.front();
        a.pop(), b.pop();
        if (x > y) a.push(y), a.push(x);
        else b.push(x), b.push(y);
    }
    if (!sz(a)) cout << REP << ' ' << 2 << '\n';
    else cout << REP << ' ' << 1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}