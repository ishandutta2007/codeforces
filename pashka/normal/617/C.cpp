#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>

// @author: pashka

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    long long x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<long long> x(n);
    vector<long long> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<pair<long long, int>> p(n);
    for (int i = 0; i < n; i++) {
        long long dx = x[i] - x1;
        long long dy = y[i] - y1;
        p[i] = make_pair(dx * dx + dy * dy, i);
    }

    sort(p.begin(), p.end());

    long long r1 = p[n - 1].first;
    long long r2 = 0;
    long long res = r1 + r2;
    for (int i = n - 1; i >= 0; i--) {
        r1 = i == 0 ? 0 : p[i - 1].first;
        long long dx = x[p[i].second] - x2;
        long long dy = y[p[i].second] - y2;
        r2 = max(r2, dx * dx + dy * dy);
        res = min(res, r1 + r2);
    }

    cout << res;
    return 0;
}