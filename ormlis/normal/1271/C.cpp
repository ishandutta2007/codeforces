#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

void solve() {
    int n; cin >> n;
    int sx, sy; cin >> sx >> sy;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    range(i, n) {
        int x, y;
        cin >> x >> y;
        if (x < sx) {
            c1++;
        }
        if (x > sx) {
            c3 ++;
        }
        if (y > sy) {
            c2++;
        }
        if (y < sy) {
            c4 ++;
        }
    }
    int ans = max(max(c1, c2), max(c3, c4));
    cout << ans << '\n';
    if (c1 == ans) {
        cout << sx - 1 << ' ' << sy;
    } else if (c2 == ans) {
        cout << sx << ' ' << sy + 1;
    } else if (c3 == ans) {
        cout << sx + 1 << ' ' << sy;
    } else {
        cout << sx << ' ' << sy - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(i, tests) {
        solve();
    }
    return 0;
}