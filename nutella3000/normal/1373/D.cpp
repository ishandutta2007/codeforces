#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int mod = 998244353;

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), pref(n);
        int Min[2]{inf, 0};

        int res = 0;
        for(int i = 0;i < n;i++) {
            cin >> a[i];
            if (i % 2 == 0) pref[i] = -a[i];
            else pref[i] = a[i];
            if (i != 0) pref[i] += pref[i - 1];

            res = max(res, pref[i] - Min[i % 2]);

            Min[i % 2] = min(Min[i % 2], pref[i]);
        }

        //cout << "before: " << res << " ";
        for(int i = 0;i < n;i += 2) res += a[i];

        cout << res << endl;
    }
}