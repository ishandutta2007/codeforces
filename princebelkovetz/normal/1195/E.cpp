#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <stack>
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
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int n, m, a, b; cin >> n >> m >> a >> b;
    int g, x, y, z; cin >> g >> x >> y >> z;
    vector <int> gg(n * m);
    gg[0] = g;
    for (int i = 1; i < n * m; ++i)
        gg[i] = (gg[i - 1] * x + y) % z;
    vector <vector <int>> h(n, vector <int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            h[i][j] = gg[i * m + j];
        }
    }
    vector <vector <int>> mins(n);
    for (int i = 0; i < n; ++i) {
        deque <int> ok;
        for (int j = 0; j < b - 1; ++j) {
            while (!ok.empty() and ok.back() > h[i][j])
                ok.pop_back();
            ok.push_back(h[i][j]);
        }
        for (int j = b - 1; j < m; ++j) {
            while (!ok.empty() and ok.back() > h[i][j])
                ok.pop_back();
            ok.push_back(h[i][j]);
            mins[i].push_back(ok.front());
            if (h[i][j - b + 1] == ok.front()) ok.pop_front();
        }
    }
    int ans = 0;
    for (int j = 0; j < m - b + 1; ++j) {
        deque <int> ok;
        for (int i = 0; i < a - 1; ++i) {
            while (!ok.empty() and ok.back() > mins[i][j])
                ok.pop_back();
            ok.push_back(mins[i][j]);
        }
        for (int i = a - 1; i < n; ++i) {
            while (!ok.empty() and ok.back() > mins[i][j])
                ok.pop_back();
            ok.push_back(mins[i][j]);
            ans += ok.front();
            if (mins[i - a + 1][j] == ok.front()) ok.pop_front();
        }
    }
    cout << ans << "\n";
    return 0;
}