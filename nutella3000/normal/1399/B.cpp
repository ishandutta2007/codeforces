#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const double inf = 1e17 + 7;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int Min1 = inf, Min2 = inf;

        for(int i = 0;i < n;i++) {
            cin >> a[i];
            Min1 = min(Min1, a[i]);
        }

        for(int i = 0;i < n;i++) {
            cin >> b[i];
            Min2 = min(Min2, b[i]);
        }

        int res = 0;

        for(int i = 0;i < n;i++) {
            int a1 = a[i] - Min1;
            int b1 = b[i] - Min2;

            res += max(a1, b1);
        }

        cout << res << endl;
    }
}