#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];
int a[MAXN + 1], ans;
unordered_map <int, int> dp[MAXN + 1];

void dfs(int nod, int par) {
    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod);
        }
    }
    int d = 2;
    while(d * d <= a[nod]) {
        int e = 0;
        while(a[nod] % d == 0) {
            a[nod] /= d;
            e++;
        }
        if(e > 0) {
            for(auto it : g[nod]) {
                if(it == par) {
                    continue;
                }
                ans = max(ans, dp[it][d] + 1);
                ans = max(ans, dp[nod][d] + dp[it][d]);
                dp[nod][d] = max(dp[nod][d], dp[it][d] + 1);
            }
            dp[nod][d] = max(dp[nod][d], 1);
            ans = max(ans, 1);
        }
        d++;
    }
    if(a[nod] > 1) {
        for(auto it : g[nod]) {
            if(it == par) {
                continue;
            }
            ans = max(ans, dp[it][a[nod]] + 1);
            ans = max(ans, dp[nod][a[nod]] + dp[it][a[nod]]);
            dp[nod][a[nod]] = max(dp[nod][a[nod]], dp[it][a[nod]] + 1);
        }
        dp[nod][a[nod]] = max(dp[nod][a[nod]], 1);
        ans = max(ans, 1);
    }
    //cerr << ans << "\n";
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}