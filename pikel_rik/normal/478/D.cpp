#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 2e5 + 1;

int dp[2][N];
int r, g;
int h;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    cin >> r >> g;
    if (r > g) swap(r, g);

    int total = r + g;

    ll lo = 1, hi = r + g, mid;

    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        if (mid * (mid + 1) <= 2 * total) lo = mid;
        else hi = mid - 1;
    }

    h = lo;

    for (int j = 0; j <= r; j++) {
        ll lb = 1, rb = r + g, mb;

        while (lb < rb) {
            mb = lb + (rb - lb + 1) / 2;
            if (mb * (mb + 1) <= 2 * (g + r - j)) lb = mb;
            else rb = mb - 1;
        }

        if (lb == h)
            dp[0][j] = 1;
        else dp[0][j] = 0;
    }

    for (int cur = 1; cur <= h; cur++) {
        for (int j = 0; j <= r; j++) {
            dp[1][j] = dp[0][j];
            if (j >= cur)
                dp[1][j] = (dp[1][j] + dp[0][j - cur]) % mod;
        }
        memcpy(dp[0], dp[1], sizeof(dp[1]));
    }

    cout << dp[0][r];

    return 0;
}