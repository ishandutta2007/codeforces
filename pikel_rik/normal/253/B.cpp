#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;

vi a, cnt;

int dp[5001][5001];

int recurse(int i, int j) {
    if (j <= 2 * i)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = min(cnt[i] + recurse(i + 1, j), cnt[j] + recurse(i, j - 1));
}

int main() {
    ios::sync_with_stdio(false);

    freopen ("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int m1 = *min_element(all(a)), m2 = *max_element(all(a));

    cnt.resize(m2 + 1);
    for (int i : a) cnt[i] += 1;

    memset(dp, -1, sizeof(dp));

    cout << recurse(m1, m2) << "\n";
    return 0;
}