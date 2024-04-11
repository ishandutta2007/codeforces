#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        k = min(k, m - 1);

        vector <int> a(n + 1);
        for(i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int len = n - m + 1;
        vector <int> b(n - len + 2);
        for(i = 1; i <= n - len + 1; i++) {
            b[i] = max(a[i], a[i + len - 1]);
        }

        int ans = 0;
        for(int x = 0; x <= k; x++) {
            int y = k - x, cur = 1e9;
            for(i = 1; i <= n - len + 1; i++) {
                if(i > x && n - (i + len - 1) >= y) {
                    cur = min(cur, b[i]);
                }
            }
            ans = max(ans, cur);
        }

        cout << ans << "\n";
    }

    return 0;
}