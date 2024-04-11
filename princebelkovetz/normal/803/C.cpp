#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <unordered_map>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, N = 200;

int n, k;

bool able(int x) {
    int sum = k * (k + 1) / 2 * x;
    return sum <= n and (n - sum) % x == 0;
}



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    cin >> n >> k;

    if (k > 1000000) {
        cout << "-1\n";
        return 0;
    }

    int ans = -1;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (able(n / i)) {
                ans = n / i;
                break;
            }
            else if (able(i)) ans = i;
        }
    }

    if (ans == -1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i < k; ++i) {
        cout << i * ans << ' ';
        n -= i * ans;
    }
    cout << n << '\n';

    return 0;
}