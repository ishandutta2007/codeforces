#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <queue>
// made by @princebelkovetz //
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " equals " << x << '\n'; 
const int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(5);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        bool c = false;
        if (n > 3) {
            for (int i = 0; i < 5; ++i) {
                if (s.substr(0, i) + s.substr(s.size() - 4 + i, 4 - i) == "2020")
                    c = true;
            }
        }
        if (c) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}