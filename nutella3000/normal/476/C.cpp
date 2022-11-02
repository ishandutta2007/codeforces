#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e17 + 7;
const int mod = 1e9 + 7;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);


    int a, b;
    cin >> a >> b;
    int res = 0;

    for(int k = 1;k < b;k++) {
        res += k * (a + b * ((a * (a + 1) / 2) % mod) % mod) % mod;
    }

    cout << res % mod << endl;
}