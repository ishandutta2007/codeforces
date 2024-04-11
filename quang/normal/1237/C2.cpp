#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

struct Point {
    int x, y, z, id;
    bool operator < (const Point &u) const {
        if (x != u.x) return x < u.x;
        if (y != u.y) return y < u.y;
        if (z != u.z) return z < u.z;
        return 0;
    }
} p[N];

int n;
vector<pair<int, int>> res;

vector<int> remove1(int lower, int upper) {
    for (int i = lower; i + 1 <= upper; i += 2) {
        res.push_back({p[i].id, p[i + 1].id});
    }
    vector<int> res;
    if ((upper - lower + 1) % 2 == 1) {
        res.push_back(p[upper].id);
    }
    return res;
}

vector<int> remove2(int lower, int upper) {
    vector<int> leftOverId;
    for (int l = lower, r = lower; l <= upper; l = r) {
        while (r <= upper && p[r].y == p[l].y) r++;
        vector<int> foo = remove1(l, r - 1);
        for (int u : foo) leftOverId.push_back(u);
    }
    while (leftOverId.size() >= 2) {
        int u = leftOverId.back();
        leftOverId.pop_back();
        int v = leftOverId.back();
        leftOverId.pop_back();
        res.push_back({u, v});
    }
    return leftOverId;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].id = i;
    }
    sort(p + 1, p + n + 1);
    vector<int> leftOverId;
    for (int l = 1, r = 1; l <= n; l = r) {
        while (r <= n && p[r].x == p[l].x) r++;
        vector<int> foo = remove2(l, r - 1);
        for (int u : foo) leftOverId.push_back(u);
    }
    for (int i = 0; i < leftOverId.size(); i += 2) {
        res.push_back({leftOverId[i], leftOverId[i + 1]});
    }
    for (auto u : res) cout << u.first << ' ' << u.second << '\n';
    return 0;
}