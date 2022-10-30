#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
const int inf = 1e15 + 7;
const int max_n = 1e5 + 1;
 
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++) cin >> a[i];
 
        int res = 0;
        for(int bit = 31;bit >= 0;bit--) {
            int cnt1 = 0;
            for(int i = 0;i < n;i++) {
                if ((a[i] & (1 << bit))) cnt1++;
                //if (bit == 0) cout << a[i] << endl;
            }
            int cnt2 = n - cnt1;
 
            //if (bit == 0)
            //cout << cnt1 << endl;
            if (cnt1 % 4 == 1) res = 1;
            else if (cnt1 % 4 == 3) {
                res = 2;
                if (cnt2 % 2 == 1) res = 1; 
            }

            if (res != 0) break;
        }
        if (res == 0) cout << "DRAW" << endl;
        else if (res == 1) cout << "WIN" << endl;
        else cout << "LOSE" << endl;
    }
}