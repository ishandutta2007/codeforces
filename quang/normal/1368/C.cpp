#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int x, y;
    x = y = 0;
    vector<pair<int, int>> res;
    for (int i = 1; i <= n; i++) {
        res.push_back({x, y});
        res.push_back({x + 1, y});
        res.push_back({x + 2, y});
        res.push_back({x, y + 1});
        res.push_back({x + 2, y + 1});
        res.push_back({x, y + 2});
        res.push_back({x + 1, y + 2});
        res.push_back({x + 2, y + 2});

        if (i < n) {
            res.push_back({x + 3, y});
            res.push_back({x + 4, y});
            res.push_back({x + 5, y});
            res.push_back({x + 6, y});
            res.push_back({x + 6, y + 1});
            res.push_back({x + 6, y + 2});
            res.push_back({x + 6, y + 3});
        }

        x += 4;
        y += 4;
    }   

    x -= 4;
    y -= 4;

    res.push_back({2, -1});
    res.push_back({x + 3, y});
    for (int xx = 2; xx <= x + 4; xx++) {
        res.push_back({xx, -2});
    }
    for (int yy = -1; yy <= y; yy++) {
        res.push_back({x + 4, yy});
    }
    cout << res.size() << '\n';
    for (auto u : res) {
        cout << u.first << ' ' << u.second << '\n';
    }
    return 0;
}