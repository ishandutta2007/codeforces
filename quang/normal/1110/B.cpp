#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m, k;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (i > 1) a[i - 1] = b[i] - b[i - 1] - 1;
    }
    int res = b[n] - b[1] + 1;
    sort(a + 1, a + n, greater<int>());
    for (int i = 1; i < k; i++) {
        res -= a[i];
    }
    cout << res << endl;
    return 0;
}