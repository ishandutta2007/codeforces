#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if (a + b > n - 2 || abs(a - b) > 1) {
        cout << -1 << '\n';
        return;
    }
    int N = a + b + 2;
    for (int i = 1; i <= n - N; i++) {
        cout << (a >= b ? i : n - i + 1) << ' ';
    }
    int L = n - N + 1, R = n;
    for (int i = 0; i < N; i++) {
        int x = -1;
        if (i & 1) x = (R--);
        else x = (L++);
        cout << (a >= b ? x : n - x + 1) << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}