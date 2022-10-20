#include <bits/stdc++.h>

using namespace std;

const int N = 1510;
const int INF = 1e9;

int n, s, m, k;
int a[N];
int val[N], cntVal;
pair<int, int> b[N];
int pref[N];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int sum[N];
int dp[N][N];

int getSum(int l, int r) {
    return sum[r] - sum[l - 1];
}

bool check(int u) {
    for (int i = 1; i <= n; i++) {
        sum[i] = (a[i] <= u);
    }
    for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
    for (int i = 0; i <= s; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= s; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= min(i, m); j++) {
            dp[i][j] = dp[i - 1][j];
            //pick i
            if (pref[i] != i) {
                dp[i][j] = max(dp[i][j], dp[pref[i]][j - 1] + getSum(b[pref[i]].second + 1, b[i].second));
            }
            dp[i][j] = max(dp[i][j], dp[pref[i] - 1][j - 1] + getSum(b[i].first, b[i].second));
        }
    }
    int mx = -INF;
    for (int i = 0; i <= min(s, m); i++) {
        mx = max(mx, dp[s][i]);
    }
    return mx >= k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val[i] = a[i];
    }
    for (int i = 1; i <= s; i++) {
        cin >> b[i].first >> b[i].second;
    }

    sort(val + 1, val + n + 1);
    sort(b + 1, b + s + 1, cmp);
    
    int cntS = 0;
    for (int i = 1; i <= s; i++) {
        if (cntS == 0 || b[i].second > b[cntS].second) {
            b[++cntS] = b[i];
        }
    }
    s = cntS;
    for (int i = 1; i <= s; i++) {
        int pos = pref[i - 1];
        while (b[pos].second < b[i].first) pos++;
        pref[i] = pos;
    }

    int low = 0, high = n + 1;
    while (high - low > 1) {
        int mid = low + high >> 1;
        if (check(val[mid])) {
            high = mid;
        } else {
            low = mid;
        }
    }
    if (high == n + 1) {
        cout << -1 << endl;
    } else {
        cout << val[high] << endl;
    }
    return 0;
}