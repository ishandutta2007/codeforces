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
    while (tt--) {
        int n, k, l; cin >> n >> k >> l;
        vector <int> d(n), able(1, -1);
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
            if (d[i] + k <= l) able.push_back(i);
        }
        able.push_back(n);
        bool iff = true;
        for (int i = 0; i < able.size() - 1 and iff; ++i) {
            int cur = k;
            bool up = false;
            for (int j = able[i] + 1; j < able[i + 1] and iff; ++j) {
                if (up) {
                    ++cur;
                    if (d[j] + cur > l) iff = false;
                }
                else --cur;
                if (d[j] + cur > l) cur = l - d[j];
                if (cur < 0) iff = false;
                else if (!cur) up = true;
            }
        }
        if (iff) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}