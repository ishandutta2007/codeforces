#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        r[p[i]] = i;
    }
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        int x = i;
        int y = r[i];
        if (x != y) {
            if (abs(x - y) >= n / 2) {
                res.push_back({x, y});
            } else if (x < n / 2 && y < n / 2) {
                res.push_back({x, n - 1});
                res.push_back({y, n - 1});
                res.push_back({x, n - 1});
            } else if (x >= n / 2 && y >= n / 2) {
                res.push_back({x, 0});
                res.push_back({y, 0});
                res.push_back({x, 0});
            } else if (x < n / 2 && y >= n / 2) {
                res.push_back({x, n - 1});
                res.push_back({y, 0});
                res.push_back({0, n - 1});
                res.push_back({x, n - 1});
                res.push_back({y, 0});
            } else {
                res.push_back({y, n - 1});
                res.push_back({x, 0});
                res.push_back({0, n - 1});
                res.push_back({y, n - 1});
                res.push_back({x, 0});
            }
        }
        swap(p[x], p[y]);
        r[p[x]] = x;
        r[p[y]] = y;
    }
    cout << res.size() << "\n";
    for (auto p : res) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

    return 0;
}