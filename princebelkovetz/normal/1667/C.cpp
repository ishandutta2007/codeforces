#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <cassert>
#include <numeric>
#include <climits>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 5e5 + 2, L = 30;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    for (int i = n - 1; i >= 0; --i) {
        int diags = 2 * i - 1;
        if (n - i >= diags) {
            vector <pair <int, int>> ok;
            cout << n - i << '\n';
            int lst = 1, lft = n - i;
            for (int j = 0; j < i; ++j) {
                cout << i - j << ' ' << j + 1 << '\n';
                lft--, lst++;
                ok.push_back({ i - j, j + 1 });
            }
            for (int j = 0; j < i - 1; ++j) {
                cout << i + i - 1 - j << ' ' << i + j + 1 << '\n';
                lft--, lst++;
                ok.push_back({ i + i - 1 - j, i + j + 1 });
            }
            while (lft--) {
                cout << lst << ' ' << lst << '\n';
                ok.push_back({ lst, lst });
                lst++;
            }
            return 0;
        }
    }
    return 0;
}