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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0;i < n;i++) cin >> a[i];
        for(int i = 0;i < n;i++) cin >> b[i];

        int l = -1, r = min(a[0], b[0]) + 1;
        bool good = false;

        while(r - l > 1) {
            int mid = ((l + r) >> 1);
            int last = max(0ll, a[1] - (b[0] - mid));
            bool bad = false;
            for(int i = 1;i < n - 1;i++) {
                if (last > b[i]) bad = true;
                last = max(0ll, a[i + 1] - b[i] + last);
            }
            
            if (bad) r = mid;
            else if (b[n - 1] - last < a[0] - mid) l = mid;
            else {
                good = true;
                break;
            }
        }
        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}