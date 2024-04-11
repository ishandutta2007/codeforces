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
        vector<int> a(n + 1);
        for(int i = 0;i < n;i++) {
            int v;
            cin >> v;
            a[v]++;
        }

        int res = 0;

        for(int s = 0;s <= 2 * n;s++) {
            int new_res = 0;
            for(int i = 0;i <= s / 2;i++) {
                if (s - i > n) 
                    continue;


                if (2 * i == s) new_res += a[i] / 2;
                else new_res += min(a[i], a[s - i]);
            }
            res = max(res, new_res);
        }

        cout << res << endl;
    }
}