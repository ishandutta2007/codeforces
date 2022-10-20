#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int p[N];
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < N; i++) {
        if (!p[i]) {
            for (int j = i + i; j < N; j += i) {
                p[j] = 1;
            }
        }
    }
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt += a[i] == 1;
    }
    if (cnt >= 3) {
        for (int i = 1; i <= 3; i++) cout << 1 << ' ';
        for (int i = 1; i <= n - cnt; i++) cout << 2 << ' ';
        for (int i = 1; i <= cnt - 3; i++) cout << 1 << ' ';
        cout << endl;
    } else if (cnt == 0) {
        for (int i = 1; i <= n; i++) cout << 2 << ' ';
            cout << endl;
    } else {
        if (cnt < n) cout << 2 << ' ';
        cout << 1 << ' ';
        for (int i = 1; i <= n - cnt - 1; i++) cout << 2 << ' ';
        for (int i = 1; i <= cnt - 1; i++) cout << 1 << ' ';
            cout << endl;
    }
    return 0;
}