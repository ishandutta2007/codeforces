//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

int solve() {
    int n;
    cin >> n;
    int a[2][n];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    LL rsum = 0;
    LL lsum = 0;
    for (int j = 0; j < n; j++)
        rsum += a[0][j];
    LL ans = 2e9;
    for (int j = 0; j < n; j++) {
        rsum -= a[0][j];
        if (j) lsum += a[1][j - 1];
        LL val = max(lsum, rsum);
        if (val < ans)
            ans = val;
    }
    cout << ans << '\n';
    return 0;
    ans = -ans;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            ans += a[i][j];
    return 0;
}