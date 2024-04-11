#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 998244353;

int n;
ar<int, 2> a[MAXN];

int par(ar<int, 2> c) {
    return (c[0]+c[1])&1;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    while (1) {
        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += par(a[i]);
        if (0 < cnt && cnt < n) {
            cout << cnt << '\n';
            for (int i = 0; i < n; i++) if (par(a[i])) cout << i+1 << ' ';
            cout << '\n';
            return;
        }
        for (int i = 0; i < n; i++) {
            int sum = a[i][0] + a[i][1];
            int diff = a[i][0] - a[i][1];
            a[i][0] = diff >> 1;
            a[i][1] = sum >> 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}