#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e8;
const int inf = 2e9 + 5;

int dp[101][101][11][11];
int n1, n2, k1, k2;

int recurse(int c1, int c2, int a, int b) {
    if (a > k1 or b > k2 or c1 > n1 or c2 > n2)
        return 0;
    if (c1 == n1 and c2 == n2)
        return 1;

    if (dp[c1][c2][a][b] != -1)
        return dp[c1][c2][a][b];

//    if (c1 == n1) {
//        if (a > 0)
//            return dp[c1][c2][a][b] = recurse(c1, c2 + 1, 0, 1) % mod;
//        return dp[c1][c2][a][b] = recurse(c1, c2, 0, b + 1) % mod;
//    }
//    if (c2 == n2) {
//        if (b > 0)
//            return dp[c1][c2][a][b] = recurse(c1 + 1, c2, 1, 0) % mod;
//        return dp[c1][c2][a][b] = recurse(c1 + 1, c2, a, 0) % mod;
//    }
    return dp[c1][c2][a][b] = (recurse(c1 + 1, c2, a + 1, 0) + recurse(c1, c2 + 1, 0, b + 1)) % mod;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));

    cout << recurse(0, 0, 0, 0) << "\n";
    return 0;
}