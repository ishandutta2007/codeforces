#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;


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
        int n, x;
        cin >> n >> x;
        vector<int> pref(n);
        int id = -1;
        int res = -1;
        for(int i = 0;i < n;i++) {
            int v;
            cin >> v;
            pref[i] = v;
            if (i != 0) pref[i] += pref[i - 1];
            if (pref[i] % x != 0) {
                res = i + 1;
                if (id == -1) id = i;
            }
            else {
                if (id != -1) res = max(res, i - id);
            }
        }

        cout << res << endl;
    }
}