#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
int a[N];
int l[N], r[N];
int dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            l[i] = n + 1;
            r[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            l[a[i]] = min(l[a[i]], i);
            r[a[i]] = max(r[a[i]], i);
        }
        int res = 0;
        int last = 0;
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            if (l[i] > r[i]) continue;
            tot++;
            dp[i] = 1;
            if (last && l[i] > r[last]) dp[i] = dp[last] + 1;
            res = max(res, dp[i]);
            last = i;
        }
        cout << tot -  res << '\n';
    }       
    return 0;
}