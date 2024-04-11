#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        if (a[0] == 1) {
            cout << n + 1 << ' ';
            for (int i = 1; i <= n; ++i) 
                cout << i << ' ';
        }
        else if (a.back() == 0) {
            for (int i = 1; i <= n + 1; ++i) 
                cout << i << ' ';
        }
        else {
            int id = -1;
            for (int i = 0; i < n - 1; ++i)
                if (a[i] == 0 and a[i + 1] == 1) id = i + 1;
            if (id == -1) cout << -1;
            else {
                for (int i = 1; i <= n; ++i) {
                    cout << i << ' ';
                    if (i == id) cout << n + 1 << ' ';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}