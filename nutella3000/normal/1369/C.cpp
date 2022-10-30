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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), w(k);
        for(int i = 0;i < n;i++) cin >> a[i];
        for(int i = 0;i < k;i++) cin >> w[i];

        sort(a.begin(), a.end());
        sort(w.begin(), w.end(), [](int v1, int v2) {return v1 > v2;});

        int res = 0;
        int id1 = 0, id2 = n - 1;
        for(int i = 0;i < k;i++) {
            if (w[i] == 1) {
                res += a[id2--] * 2;
            }
        }
        
        for(int num : w) {
            if (num == 1) break;
            res += a[id2--];
            if (num == 1) res += a[id2 + 1];
            else {
                res += a[id1];
                id1 += num - 1;
            }
        }
        cout << res << endl;
    }
}