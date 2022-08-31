#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, dx, dy;
    cin >> n >> m >> dx >> dy;

    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;

    if (n == 1) {
        return cout << 0 << ' ' << 0 << '\n', 0;
    }

    vector<int> jump(n);
    for (int cx = dx, cy = dy; cx != 0; cx = (cx + dx) % n, cy = (cy + dy) % n) {
        jump[cx] = cy;
    }

    vector<int> cnt(n);
    for (int i = 0; i < m; i++) {
        int j = a[i].first ? n - a[i].first : 0;
        a[i].first = 0;
        a[i].second = (a[i].second + jump[j]) % n;
        cnt[a[i].second] += 1;
    }

    int mx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    cout << 0 << ' ' << mx << '\n';
    return 0;
}