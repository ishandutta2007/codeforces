#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;

struct Data {
    int x, y, id;
    bool operator < (const Data &u) const {
        if (y != u.y) return y < u.y;
        if (id != u.id) return id < u.id;
        return x < u.x;
    }
};

Data a[N * 2];
bool res[N];

set<pair<int, int>> ss;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        ss.insert({a[i].x, a[i].y});
        a[i].id = -1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i + n].x >> a[i + n].y;
        a[i + n].id = i;
    }
    set<int> s;
    pair<int, int> curPoint(-1, -1);
    a[0] = {0, 0, -1};
    sort(a, a + n + m + 1);
    // for (int i = 0; i <= n + m; i++) {
    //     cout << a[i].x << ' ' << a[i].y << ' ' << a[i].id << endl;
    // }
    for (int l = 0, r = 0; l <= n + m; l = r) {
        while (r <= n + m && a[r].y == a[l].y) r++;
        // cout << "# " << a[l].y << ' ' << l << ' ' << r << endl;
        // cout << curPoint.first << ' ' << curPoint.second << '\n';

        while (!s.empty() && *s.begin() <= curPoint.first) s.erase(s.begin());

        int expectedX = curPoint.first + a[l].y - curPoint.second;
        while (!s.empty() && *s.begin() <= expectedX) {
            // cout << "hit " << *s.begin() << endl;
            s.erase(s.begin());
            expectedX++;
        }
        
        int minVal = expectedX;
        for (int i = l; i < r; i++) {
            if (a[i].id == -1) {
                s.insert(a[i].x);
                minVal = min(minVal, a[i].x);
            }
        }
        // cout << minVal << endl;
        // cout << expectedX << endl;
        for (int i = l; i < r; i++) {
            if (a[i].id != -1) {
                res[a[i].id] = a[i].x != minVal;
                if (ss.count({a[i].x, a[i].y})) res[a[i].id] = 0;
            }
        }
        if (minVal == expectedX) {
            curPoint = {expectedX, a[l].y};
        } else {
            curPoint = {expectedX - 1, a[l].y};
        }
        // cout << curPoint.first << ' ' << curPoint.second << '\n';

    }
    for (int i = 1; i <= m; i++) {
        cout << (res[i] ? "WIN" : "LOSE") << '\n';
    }
    return 0;
}