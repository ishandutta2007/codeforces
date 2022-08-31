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
const int N = 1e3 + 1;

int n, k, a[5][N], pos[5][N];
bool ok[N][N];

int dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < k; i++) for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        pos[i][a[i][j]] = j + 1;
    }

    memset(ok, true, sizeof(ok));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            for (int p = 1; p < k; p++) {
                if (pos[p][i] < pos[p][j] and pos[0][i] > pos[0][j]) {
                    ok[i][j] = false;
                    break;
                }
                else if (pos[p][i] > pos[p][j] and pos[0][i] < pos[0][j]) {
                    ok[i][j] = false;
                    break;
                }
            }
        }
    }

    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (ok[a[0][j]][a[0][i]])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << *max_element(dp, dp + n) << "\n";
    return 0;
}