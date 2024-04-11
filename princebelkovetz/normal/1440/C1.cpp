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
struct elem {
    int a, b, c, d, e, f;
};
char sw(char x) {
    if (x == '1') return '0';
    return '1';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(7);
    int tt; cin >> tt;
    while (tt --> 0) {
        int n, m; cin >> n >> m;
        vector <string> a(n);
        for (auto& x : a) 
            cin >> x;
        vector <elem> ans;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] != '0') {
                    ans.push_back({ i, j, i + 1, j, i + 1, j == m - 1 ? j - 1 : j + 1 });
                    a[i][j] = sw(a[i][j]);
                    a[i + 1][j] = sw(a[i + 1][j]);
                    a[i + 1][j == m - 1 ? j - 1 : j + 1] = sw(a[i + 1][j == m - 1 ? j - 1 : j + 1]);
                }
            }
        }
        int i = n - 1;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '0') continue;
            if (a[i][j] == '1') {
                ans.push_back({ i, j, i - 1, j, i - 1, j == m - 1 ? j - 1 : j + 1 });
                ans.push_back({ i, j, i - 1, j, i, j == m - 1 ? j - 1 : j + 1 });
                ans.push_back({ i, j, i - 1, j == m - 1 ? j - 1 : j + 1, i, j == m - 1 ? j - 1 : j + 1 });
                a[i][j] = sw(a[i][j]);
            }
        }
        cout << ans.size() << '\n';
        for (auto x : ans) cout << x.a + 1 << ' ' << x.b + 1 << ' ' << x.c + 1 << ' ' << x.d + 1 << ' ' << x.e + 1 << ' ' << x.f + 1 << '\n';
    }
	return 0;
}