#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;



int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        int n; cin >> n;
        int mx = -2e9, dif = 0;
        for(i = 1; i <= n; i++) {
            int x; cin >> x;
            if(mx > x) {
                dif = max(dif, mx - x);
            }
            mx = max(mx, x);
        }
        int ans = 0;
        while((1LL << ans) <= dif) {
            ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}