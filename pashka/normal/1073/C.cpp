#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;

    vector<int> dx(n);
    vector<int> dy(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') dy[i] = 1;
        if (s[i] == 'D') dy[i] = -1;
        if (s[i] == 'L') dx[i] = -1;
        if (s[i] == 'R') dx[i] = 1;
    }

    int xx = 0;
    int yy = 0;
    for (int i = 0; i < n; i++) {
        xx += dx[i];
        yy += dy[i];
    }

    if ((x + y + n) % 2 != 0 || abs(x) + abs(y) > n) {
        cout << -1 << "\n";
        return 0;
    }
    if (xx == x && yy == y) {
        cout << 0 << "\n";
        return 0;
    }

    int l = 0;
    int res = n;
    for (int r = 0; r < n; r++) {
        xx -= dx[r];
        yy -= dy[r];
        while (abs(xx - x) + abs(yy - y) <= r - l + 1) {
            xx += dx[l];
            yy += dy[l];
            l++;
        }
        if (l > 0) {
            res = min(res, r - l + 2);
        }
    }
    cout << res << "\n";




}