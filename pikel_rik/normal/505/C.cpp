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

vi gems(30001);
int n, d;

int max_dist = INT_MIN;
int dp[30001][491];

int recurse(int i, int l) {
    if (i > max_dist)
        return 0;
    if (dp[i][l - d + 245] != -1)
        return dp[i][l - d + 245];
    if (l == 1)
        return dp[i][l - d + 245] = gems[i] + max(recurse(i + l, l), recurse(i + l + 1, l + 1));
    return dp[i][l - d + 245] = gems[i] + max({recurse(i + l, l), recurse(i + l - 1, l - 1), recurse(i + l + 1, l + 1)});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        max_dist = max(max_dist, a);
        gems[a] += 1;
    }

    memset(dp, -1, sizeof(dp));

    cout << gems[0] + recurse(d, d);
    return 0;
}