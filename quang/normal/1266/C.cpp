#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        for (int i = 2; i <= m + 1; i++) {
            cout << i << ' ';
        }
        cout << endl;
        return 0;
    }
    if (m == 1) {
        for (int i = 2; i <= n + 1; i++) {
            cout << i << '\n';
        }
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt++;
        a[i] = cnt;
    }
    for (int i = 1; i <= m; i++) {
        cnt++;
        b[i] = cnt;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i] * b[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}