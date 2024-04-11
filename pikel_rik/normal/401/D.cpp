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
const int N = 1e6;

int m;

vi num;
ll dp[(1 << 18)][100];

ll recurse(int mask = 0, int rem = 0) {
    if (mask == (1 << num.size()) - 1) {
        if (rem == 0)
            return 1;
        return 0;
    }

    if (dp[mask][rem] != -1)
        return dp[mask][rem];

    ll ans = 0;
    for (int i = 0; i < num.size(); i++) {
        if (mask & (1 << i) or (mask == 0 and num[i] == 0)) continue;
        ans += recurse(mask ^ (1 << i), (rem * 10 + num[i]) % m);
    }
    return dp[mask][rem] = ans;
}

ll factorial (int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n >> m;

    while (n > 0) {
        num.push_back(n % 10);
        n /= 10;
    }
    reverse(all(num));

    memset(dp, -1, sizeof(dp));

    ll ans = recurse();

    vi cnt(10);
    for (int i = 0; i < num.size(); i++) {
        cnt[num[i]] += 1;
    }

    for (int i = 0; i < 10; i++) {
        if (cnt[i] > 1)
            ans /= factorial(cnt[i]);
    }

    cout << ans << "\n";
    return 0;
}