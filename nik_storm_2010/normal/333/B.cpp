#include<iostream>

using namespace std;
const int maxN = 1000 + 10;

int main() {
    int a[maxN][maxN];
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        a[x][y] = 1;
    }
    int ans = 0;
    for (int i = 2; i < n; i++) {
        bool flag1 = true, flag2 = true;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) flag1 = false;
            if (a[j][i] == 1) flag2 = false;
        }
        if (n % 2 == 1 && i == n - i + 1 && flag1 && flag2) ans--;
        if (flag1) ans++;
        if (flag2) ans++;
    }
    cout << ans;
    return 0;
}