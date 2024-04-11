#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int max_n = 2e5 + 1;

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
        vector<int> a(n);
        for(int i = 0;i < n;i++) cin >> a[i];
        bool lower = true;

        int res = n - 1;
        for(int i = n - 2;i >= 0;i--) {
            if (lower) {
                if (a[i] < a[i + 1]) lower = false;
                res--;
            }else {
                if (a[i] > a[i + 1]) break;
                res--;
            }
        }

        cout << res << endl;
    }
}