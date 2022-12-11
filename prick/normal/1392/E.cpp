#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

int n;
vector<vector<int>> a;

void prepare() {
    a = vector<vector<int>>(n, vector<int>(n));
    for (int d = 0; d <= 50; ++d) {
        for (int c = 0; c < n; ++c) {
            int r = d - c;
            if (r < 0 || r >= n) continue;
            if (c & 1) {
                a[r][c] = 1ll << d;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

void out(int x, int y) {
    cout << x + 1 << ' ' << y + 1 << endl;
}

void ask() {
    int x;
    cin >> x;
    int r = 0, c = 0;
    int d = 0;
    out(r, c);
    while (r < n - 1 || c < n - 1) {
        if (r == n - 1) {
            ++c;
        } else if (c == n - 1) {
            ++r;
        } else if (a[r][c + 1] == (x & (1ll << (d + 1)))) {
            ++c;
        } else {
            ++r;
        }
        ++d;
        out(r, c);
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    prepare();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ask();
    }
}