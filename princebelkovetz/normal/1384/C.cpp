#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt-- > 0) {
        int n, ans = 0; cin >> n;
        string a, b; cin >> a >> b;
        bool c = true;
        for (int i = 0; i < n; ++i) 
            if (b[i] < a[i]) c = false;
        if (!c) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < 26; ++i) {
            char x = 'a' + i, m = 'z';
            bool c = false;
            for (int j = 0; j < n; ++j) {
                if (a[j] == x and a[j] != b[j]) {
                    m = min(m, b[j]);
                    c = true;
                }
            }
            for (int j = 0; c and j < n; ++j) {
                if (a[j] == x and a[j] != b[j])
                    a[j] = m;
            }
            if (c) ++ans;
        }
        cout << ans << "\n";
    }
    return 0;
}