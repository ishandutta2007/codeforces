#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 4e3 + 5;

int n, a[N], dp[N][N];
map<int, int> conv;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    int ptr = 1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (conv.find(a[i]) == conv.end())
            conv[a[i]] = ptr++;
    }

    for (int i = 0; i < n; i++) {
        a[i] = conv[a[i]];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        vector<bool> v(n);
        for (int j = i - 1; j >= 0; j--) {
            if (!v[a[j]]) {
                dp[a[i]][a[j]] = max(dp[a[i]][a[j]], 1 + dp[a[j]][a[i]]);
                v[a[j]] = true;
            }
        }
    }

    int best = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            best = max(best, dp[i][j]);
        }
    }

    cout << best << "\n";
    return 0;
}