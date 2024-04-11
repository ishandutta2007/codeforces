#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int oo = 2e9;

int f[20][1 << 20], kind[200], a[200], b[200], m;

int solve(int x, int mask) {
    if (x == m) return 0;
    if (f[x][mask] != oo) return f[x][mask];
    int res;
    (abs(kind[x]) == 1) ? res = -oo : res = +oo;
    for (int i = 0; i < m; i++) {
        if (((1 << i) & mask) != 0) continue;
        if (kind[x] == +1) res = max(res, solve(x + 1, mask | (1 << i)) + b[i]);
        if (kind[x] == +2) res = min(res, solve(x + 1, mask | (1 << i)) - b[i]);
        if (kind[x] == -1) res = max(res, solve(x + 1, mask | (1 << i)));
        if (kind[x] == -2) res = min(res, solve(x + 1, mask | (1 << i)));
    }
    f[x][mask] = res;
    return res;
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        char c;
        cin >> c >> x;
        if (c == 'b') x = -x;
        kind[i] = x;
    }
    sort(a, a + n);
    for (int i = 0; i < m; i++) b[i] = a[n - i - 1];
    for (int i = 0; i < m; i++) for (int j = 0; j < (1 << m); j++) f[i][j] = oo;
    cout << solve(0, 0) << endl;
    return 0;
}