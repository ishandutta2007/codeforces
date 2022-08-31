#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

vector<ll> sum;
ll dp[5001][5001];
int n, m, k;

ll recurse(int l, int cap) {
    if (cap == 0 or l + m - 1 >= n)
        return 0;
    if (dp[l][cap] != -1)
        return dp[l][cap];
    return dp[l][cap] = max(sum[l] + recurse(l + m, cap - 1), recurse(l + 1, cap));
}

int main() {
    ios::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sum.resize(n);

    for (int i = 0; i < m; i++) {
        sum[0] += a[i];
    }

    for (int i = 1; i + m - 1 < n; i++) {
        sum[i] = sum[i-1] - a[i-1] + a[i + m - 1];
    }

    cout << recurse(0, k);
    return 0;
}