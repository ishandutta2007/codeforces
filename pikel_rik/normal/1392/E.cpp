#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 25 + 5;

int n;
ll a[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % 2 == 0)
                a[i][j] = (1ll << (i + j - 2));
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout.flush();

    int q;
    cin >> q;

    while (q--) {
        ll k;
        cin >> k;

        int x = 1, y = 1;
        cout << x << " " << y << "\n";

        for (int i = 0; i < 2*n - 2; i++) {
            if (x % 2 == 0) {
                if (y + 1 <= n and k & a[x][y + 1])
                    y++;
                else x++;
            } else {
                if (x + 1 <= n and k & a[x + 1][y])
                    x++;
                else y++;
            }
            cout << x << " " << y << "\n";
        }
        cout.flush();
    }
    return 0;
}