#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7, mod = 1e9 + 7;
 
 
 
 
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
        vector<int> a(2 * n);
        for(int i = 0;i < 2 * n;i++) cin >> a[i];
        vector<pii> res;
        int id1 = -1, id2 = -1;
        for(int i = 0;i < 2 * n;i++) {
            if (a[i] % 2 == 0) {
                if (id2 == -1) id2 = i + 1;
                else {
                    res.emplace_back(i + 1, id2);
                    id2 = -1;
                }
            }else {
                if (id1 == -1) id1 = i + 1;
                else {
                    res.emplace_back(i + 1, id1);
                    id1 = -1;
                }
            }
        }
        for(int i = 0;i < n - 1;i++) {
            cout << res[i].first << " " << res[i].second << endl;
        }
    }   
}