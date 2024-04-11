#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
const int INF = 1e9;

int x[4], y[4], a[4], b[4], rx[4], ry[4], ans;

void solve(int num, int sum) {
    if (num == 4) {
        vector <long long> d(6);
        int cnt = 0;
        for (int i = 0; i < 4; i++) for (int j = i + 1; j < 4; j++) d[cnt++] = 1LL * (rx[i] - rx[j]) * (rx[i] - rx[j]) + 1LL * (ry[i] - ry[j]) * (ry[i] - ry[j]);
        sort(d.begin(), d.end());
        if (d[0] != 0 && d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5]) ans = min(ans, sum);
        return;
    }
    rx[num] = x[num], ry[num] = y[num];
    for (int i = 0; i < 4; i++) {
        solve(num + 1, sum + i);
        int nx = a[num] + b[num] - ry[num], ny = b[num] - a[num] + rx[num];
        rx[num] = nx;
        ry[num] = ny;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        for (int i = 0; i < 4; i++) cin >> x[i] >> y[i] >> a[i] >> b[i];
        ans = INF;
        solve(0, 0);
        if (ans == INF) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}