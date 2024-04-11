#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int a[N][N];
int res[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    long long foo = 1ll * a[2][3] * a[1][2] / a[1][3];
    res[2] = sqrt(foo);
    while (1ll * res[2] * res[2] < foo) res[2]++;
    while (1ll * res[2] * res[2] > foo) res[2]--;
    res[1] = a[1][2] / res[2];
    for (int i = 3; i <= n; i++) {
        res[i] = a[1][i] / res[1];
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}