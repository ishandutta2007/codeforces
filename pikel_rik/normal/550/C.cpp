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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();
    vi a(n);

    for (int i = 0; i < n; i++) a[i] = (int)(s[i] - '0');

    bool dp[n+1][8];
    int prev[n+1][8];

    memset(dp, false, sizeof(dp));

    for (int i = 0; i < n; i++) dp[i][a[i] % 8] = true;
    memset(prev, -1, sizeof(prev));

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            if (dp[i-1][j]) {
                dp[i][(j * 10 + a[i]) % 8] = true;
                prev[i][(j * 10 + a[i]) % 8] = j;

                dp[i][j] = true;
                prev[i][j] = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dp[i][0]) {
            string ans;

            int idx = i, j = 0;

            while (true) {
                if (prev[idx][j] == -1 or prev[idx][j] != j)
                    ans.push_back(s[idx]);

                if (prev[idx][j] == -1) break;

                j = prev[idx][j];
                idx -= 1;
            }

            reverse(all(ans));
            cout << "YES\n" << ans << "\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}