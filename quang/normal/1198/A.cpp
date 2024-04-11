#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, t;
int a[N];
pair<int, int> b[N];

int get(int k) {
    return ceil(log2(k));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    t *= 8;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }   
    sort(a + 1, a + n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (m == 0 || a[i] != a[i - 1]) {
            b[++m] = {a[i], 1};
        } else {
            b[m].second++;
        }
    }
    for (int i = 1; i <= m; i++) {
        b[i].second += b[i - 1].second;
    }
    int res = n + 1;
    int cur = 1;
    for (int i = 1; i <= m; i++) {
        while (cur <= m && n * get(cur - i + 1) <= t) cur++;
        res = min(res, b[i - 1].second + b[m].second - b[cur - 1].second);
    }
    cout << res << endl;
    return 0;
}