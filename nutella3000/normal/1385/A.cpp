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
        vector<int> a(3);
        for(int i = 0;i < 3;i++) cin >> a[i];
        sort(a.begin(), a.end());
        if ((a[0] == a[1] && a[2] > a[1]) || (a[0] != a[1] && a[1] != a[2])) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            //if (a[2] != a[1]) cout << a[0] << " " << a[1] << " " << a[2] << endl;
            cout << a[0] << " " << a[1] << " " << 1 << endl;
        }
    }
}