#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 305;

int n, a[4];
bool dp[N][N];

void calc() {
    dp[0][0] = false;
    for (int i = 1; i <= 300; i++)
        dp[0][i] = dp[i][0] = true;

    for (int i = 1; i <= 300; i++) {
        for (int j = 1; j <= 300; j++) {
            dp[i][j] = false;
            for (int k = 1; k <= i; k++)
                dp[i][j] |= !dp[i - k][j];
            for (int k = 1; k <= j; k++)
                dp[i][j] |= !dp[i][j - k];

            for (int k = 1; k <= min(i, j); k++)
                dp[i][j] |= !dp[i - k][j - k];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        if (a[0])
            cout << "BitLGM\n";
        else cout << "BitAryo\n";
    }
    else if (n == 2) {
        calc();
        if (dp[a[0]][a[1]])
            cout << "BitLGM\n";
        else cout << "BitAryo\n";
    }
    else {
        if ((a[0] ^ a[1] ^ a[2]) != 0)
            cout << "BitLGM\n";
        else cout << "BitAryo\n";
    }
    return 0;
}