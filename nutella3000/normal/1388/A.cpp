#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e9 + 7;
const int max_n = 1e6 + 4;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if (n < 31) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if (n == 36 || n == 40 || n == 44) cout << 6 << " " << 10 << " " << 15 << " " << n - 31 << endl;
        else cout << 6 << " " << 10 << " " << 14 << " " << n - 30 << endl;
    }   
}