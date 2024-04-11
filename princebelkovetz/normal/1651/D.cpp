#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#pragma GCC optimize("O3")
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 2e6 + 2, M = 11, add = 1e6;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    vector <vector <int>> ps(n, vector <int>(2));
    vector <vector <int>> d1(N), d2(N);
    for (int i = 0; i < n; ++i) {
        cin >> ps[i][0] >> ps[i][1];
        d1[ps[i][0] + ps[i][1] + add].push_back(ps[i][0]);
        d2[ps[i][1] - ps[i][0] + add].push_back(ps[i][0]);
        
    }

    for (auto& x : d1) sort(x.begin(), x.end());
    for (auto& x : d2) sort(x.begin(), x.end());
    for (auto& x : d1) x.push_back(mod);
    for (auto& x : d2) x.push_back(mod);

    auto check = [&](int x, int y, int d) {
        int ty = y + d;
        int c1 = ty + x + add, c2 = ty - x + add;
        int lx = x, rx = x + d;
        if (upper_bound(d1[c1].begin(), d1[c1].end(), rx)
            - lower_bound(d1[c1].begin(), d1[c1].end(), lx) < d + 1) return 1;
        lx = x - d, rx = x;
        if (upper_bound(d2[c2].begin(), d2[c2].end(), rx)
            - lower_bound(d2[c2].begin(), d2[c2].end(), lx) < d + 1) return 2;
        ty = y - d;
        c1 = ty + x + add, c2 = ty - x + add;
        lx = x - d, rx = x;
        if (upper_bound(d1[c1].begin(), d1[c1].end(), rx)
            - lower_bound(d1[c1].begin(), d1[c1].end(), lx) < d + 1) return 3;
        lx = x, rx = x + d;
        if (upper_bound(d2[c2].begin(), d2[c2].end(), rx)
            - lower_bound(d2[c2].begin(), d2[c2].end(), lx) < d + 1) return 4;
        return 0;
    };
    map <pair <int, int>, int> was;
    for (auto& p : ps) {
        int cur = 1, x = p[0], y = p[1];
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (was.find({ nx, ny }) != was.end())
                cur = max(cur, was[{nx, ny}] - 1);
        }
        while (!check(x, y, cur)) cur++;
        was[{x, y}] = cur;
        int res = check(x, y, cur);
        if (res == 1) {
            int cx = x, cy = y + cur;
            int c = cx + cy + add;
            int id = lower_bound(d1[c].begin(), d1[c].end(), cx) - d1[c].begin();
            while (true) {
                if (d1[c][id] != cx) break;
                cx++, cy--, id++;
            }
            cout << cx << ' ' << cy;
        }
        else if (res == 2) {
            int cx = x, cy = y + cur;
            int c = cy - cx + add;
            int id = lower_bound(d2[c].begin(), d2[c].end(), cx) - d2[c].begin();
            while (true) {
                if (d2[c][id] != cx) break;
                cx--, cy--, id--;
            }
            cout << cx << ' ' << cy;
        }
        else if (res == 3) {
            int cx = x, cy = y - cur;
            int c = cx + cy + add;
            int id = lower_bound(d1[c].begin(), d1[c].end(), cx) - d1[c].begin();
            while (true) {
                if (d1[c][id] != cx) break;
                cx--, cy++, id--;
            }
            cout << cx << ' ' << cy;
        }
        else if (res == 4) {
            int cx = x, cy = y - cur;
            int c = cy - cx + add;
            int id = lower_bound(d2[c].begin(), d2[c].end(), cx) - d2[c].begin();
            while (true) {
                if (d2[c][id] != cx) break;
                cx++, cy++, id++;
            }
            cout << cx << ' ' << cy;
        }
        cout << '\n';
    }


    return 0;
}