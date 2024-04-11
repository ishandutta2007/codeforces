#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb emplace_back

const int inf = 2e9 + 2;
const int max_n = 1e3 + 3;

int n, m;
int a[max_n], b[max_n];
int dp[max_n][max_n], id[max_n][max_n];
int prefid[max_n][max_n];

void run() {
    cin >> n;
    a[0] = -1;
    ++n;
    for (int i = 1; i < n; ++i)
        cin >> a[i];

    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    for (int i = 1; i < n; ++i) {
        for (int j = 0;j < m; ++j) {
            if (a[i] != b[j]) {
                dp[i][j] = dp[i - 1][j];
                id[i][j] = j;
            }else {
                dp[i][j] = 1, id[i][j] = -1;
                for (int k = 0; k < j; ++k) {
                    if (b[k] < b[j] && dp[i][j] < dp[i - 1][k] + 1) {
                        dp[i][j] = dp[i - 1][k] + 1;
                        id[i][j] = k;
                    }
                }
            }
        }
    }
    int v1 = 0, v2 = 0;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            if (dp[i][j] > dp[v1][v2]) v1 = i, v2 = j;

    vector<int> res;
    while (dp[v1][v2]) {
        if (id[v1][v2] != v2) res.emplace_back(b[v2]);
        v2 = id[v1][v2];
        --v1;
    }
    reverse(all(res));
    cout << size(res) << endl;

    for (int i : res)
        cout << i << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    
    run();
}