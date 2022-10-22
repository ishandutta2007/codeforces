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
        string s; cin >> s;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '?') continue;
            int j = i;
            while (j < n and s[j] == s[i]) j++;

            bool wb = false, wr = false;

            if (i) {
                int ok = (s[i - 1] == 'B');
                for (int k = i; k < j; ++k)
                    if ((k - i) & 1 ^ ok) s[k] = 'R';
                    else s[k] = 'B';
            }
            else {
                int ok = (j == n or s[j] == 'B');
                for (int k = i; k < j; ++k)
                    if ((j - k) & 1 ^ ok) s[k] = 'B';
                    else s[k] = 'R';
            }
            i = j - 1;
        }
        cout << s << '\n';
    }

    return 0;
}