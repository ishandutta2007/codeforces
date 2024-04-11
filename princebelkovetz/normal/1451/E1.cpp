#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
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
    int n; cin >> n;
    int get = 0;
    vector <int> ans(n);
    vector <int> q(5);
    cout << "AND 1 2" << endl;
    cin >> q[0];
    cout << "AND 2 3" << endl;
    cin >> q[1];
    cout << "AND 1 3" << endl;
    cin >> q[2];
    cout << "OR 1 2" << endl;
    cin >> q[3];
    cout << "OR 2 3" << endl;
    cin >> q[4];
    for (int j = 0; j < 18; ++j) {
        int x = (q[0] >> j), y = (q[1] >> j), z = (q[2] >> j);
        x &= 1; y &= 1; z &= 1;
        int c = q[3] >> j, d = q[4] >> j;
        c &= 1; d &= 1;
        if (x and y and z) {
            ans[0] += (1 << j);
            ans[1] += (1 << j);
            ans[2] += (1 << j);
        }
        else if (x and !y and !z) {
            ans[0] += (1 << j);
            ans[1] += (1 << j);
        }
        else if (!x and y and !z) {
            ans[1] += (1 << j);
            ans[2] += (1 << j);
        }
        else if (!x and !y and z) {
            ans[0] += (1 << j);
            ans[2] += (1 << j);
        }
        else if (!x and !y and !z) {
            if (!c and !d) {
                // nice try
            }
            else if (c and !d) {
                ans[0] += (1 << j);
            }
            else if (!c and d) {
                ans[2] += (1 << j);
            }
            else {
                ans[1] += (1 << j);
            }
        }
        else assert(0);
    }
    for (int i = 3; i < n; ++i) {
        cout << "XOR " << 1 << ' ' << i + 1 << endl;
        cin >> get;
        ans[i] = ans[0] ^ get;
    }
    cout << "! ";
    for (auto x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}