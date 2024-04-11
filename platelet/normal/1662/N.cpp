#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)

using namespace std;
using ll = long long;

const int N = 1500 + 5;

int n, row[N], col[N];
short a[N * N][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int x;
    rep(i, 1, n) rep(j, 1, n) {
        cin >> x;
        a[x][0] = i, a[x][1] = j;
    }
    ll ans = 0;
    rep(i, 1, n * n) {
        int &x = row[a[i][0]], &y = col[a[i][1]];
        ans += x * (n - 1 - y) + y * (n - 1 - x), x++, y++;
    }
    cout << ans / 2;
}