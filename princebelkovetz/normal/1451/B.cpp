#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <queue>
#include <cassert>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 1e9 + 7;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(7);
    int tt; cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        string s; cin >> s;
        vector <int> pref(n + 1);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + (s[i] == '0');
        }
        while (q --> 0){
            int l, r; cin >> l >> r;
            l--, r--;
            if (s[l] == '0' and pref[l] > 0) cout << "YES";
            else if (s[l] == '1' and pref[l] < l) cout << "YES";
            else if (s[r] == '0' and pref[n] - pref[r + 1] > 0) cout << "YES";
            else if (s[r] == '1' and pref[n] - pref[r + 1] < n - r - 1) cout << "YES";
            else cout << "NO";
            cout << '\n';
        }
    }
    return 0;
}