#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
    int n, ans = -1, cur = 0; cin >> n;
    vector <int> a(n);
    for (auto& x : a) cin >> x;
    if (n <= 2) {
        cout << "0\n";
        return 0;
    }
    for (int d1 = -1; d1 <= 1; ++d1) {
        for (int d2 = -1; d2 <= 1; ++d2) {
            a[0] += d1, a[1] += d2;
            cur = -1;
            for (int i = 2; i < n; ++i) {
                int need = a[0] + (a[1] - a[0]) * i;
                if (abs(need - a[i]) > 1) {
                    cur = -1;
                    break;
                }
                if (cur == -1) cur = abs(need - a[i]);
                else cur += abs(need - a[i]);
            }
            a[0] -= d1; a[1] -= d2;
            if (cur != -1 and (ans == -1 or cur + abs(d1) + abs(d2) < ans))
                ans = cur + abs(d1) + abs(d2);
        }
    }
    cout << ans << "\n";
    return 0;
}