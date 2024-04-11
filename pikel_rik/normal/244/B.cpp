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
const int N = 4e3 + 5;

vector<int> num;

int dp[10][1024][2][2];

int pop(int x) {
    int c = 0;
    for (int i = 0; i < 10; i++) {
        if (x & (1 << i))
            c += 1;
    }
    return c;
}

int recurse(int i = 0, int mask = 0, int f1 = 0, int f2 = 0) {
    if (i == num.size()) {
        if (pop(mask) <= 2)
            return 1;
        return 0;
    }

    if (dp[i][mask][f1][f2] != -1)
        return dp[i][mask][f1][f2];

    int limit;
    if (!f1) limit = num[i];
    else limit = 9;

    int ans = 0;
    for (int j = 0; j <= limit; j++) {
        if (f2 == 0 and j == 0)
            ans += recurse(i + 1, mask, 1, 0);
        else if (j < num[i])
            ans += recurse(i + 1, mask | (1 << j), 1, 1);
        else ans += recurse(i + 1, mask | (1 << j), f1, 1);
    }
    return dp[i][mask][f1][f2] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;

    if (n == 0) {
        cout << "0\n";
        return 0;
    }

    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }
    reverse(all(num));

    cout << recurse() - 1 << "\n";
    return 0;
}