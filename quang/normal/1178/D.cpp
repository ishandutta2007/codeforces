#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int p[N * N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p[1] = 1;
    for (int i = 2; i < N * N; i++) {
        if (!p[i]) {
            for (int j = i + i; j < N * N; j += i) {
                p[j] = 1;
            }
        }
    }
    int n;
    cin >> n;
    int sum = 0;
    vector<pair<int, int>> res;
    for (int i = 1; i <= n; i++) {
        sum++;
        int nxt = (i + 1 <= n) ? i + 1 : 1;
        res.push_back({i, nxt});
    }
    int cur = 1;
    while (p[sum]) {
        sum++;
        res.push_back({cur, cur + n / 2});
        cur++;
    }
    cout << res.size() << endl;
    for (auto u : res) {
        cout << u.first << ' ' << u.second << endl;
    }
    return 0;
}