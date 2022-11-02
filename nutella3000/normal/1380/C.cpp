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
        vector<int> a(n);
        for(int i = 0;i < n;i++) cin >> a[i];
        sort(a.begin(), a.end());
        int res = 0;
        int Min = inf;
        int cnt = 0;
        for(int i = n - 1;i >= 0;i--) {
            Min = min(Min, a[i]);
            cnt++;
            if (cnt * Min >= x) {
                res++;
                cnt = 0;
                Min = inf;
            }
        }
        cout << res << endl;
    }
}