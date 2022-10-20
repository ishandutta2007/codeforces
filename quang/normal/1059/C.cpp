#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int cur = 1;
    while (n > 3) {
        int cnt = (n + 1) / 2;
        for (int i = 1; i <= cnt; i++) {
            cout << cur << ' ';
        }
        n -= cnt;
        cur *= 2;
    }
    if (n == 3) {
        cout << cur << ' ' << cur << ' ' << cur * 3 << endl;
    } else if (n == 2) {
        cout << cur << ' ' << cur * 2 << endl;
    } else {
        cout << cur << endl;
    }
    return 0;
}