#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5;
vector<vector<int>> a(3, vector<int>());
vector<int> n(3, 0);

int calc() {
    int ans = 0, m1 = a[1][0], m2 = a[2][0], s1 = 0, s2 = 0;
    for (int i : a[0]) ans += i;
    for (int i = 1; i < n[1]; i++) s1 += a[1][i];
    for (int i = 1; i < n[2]; i++) s2 += a[2][i];

    ans += max({s2 - m1 + s1 - m2, m2 + s2 - m1 - s1, m1 + s1 - m2 - s2});
    return ans;
}

void solveTestCase() {
    cin >> n[0] >> n[1] >> n[2];
    a[0].resize(n[0]);
    a[1].resize(n[1]);
    a[2].resize(n[2]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n[i]; j++)
            cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
    }

    int ans = -1e18;
    ans = max(ans, calc());

    swap(a[0], a[1]), swap(n[0], n[1]);
    ans = max(ans, calc());

    swap(a[0], a[2]), swap(n[0], n[2]);
    ans = max(ans, calc());

    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
        solveTestCase();
}