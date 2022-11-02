
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
typedef long double ld;
 
const int inf = 1e15;
const int max_n = 81;
 
int n;
int a[max_n];
int dp[max_n][max_n][max_n * max_n];
 
void solve() {
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
 
    int cnt_all = 0;
    int last = -1;
    for(int i = 0;i < n;i++) {
        if (a[i] == 0) {
            cnt_all++;
            continue;
        }
 
        for(int j = 0;j < n;j++) {
            for(int k = 0;k < n * n;k++) {
                dp[i][j][k] = -inf;
                if (k < abs(i - j)) continue;
                if (j < i - cnt_all) continue;
 
                if (last == -1) {
                    dp[i][j][k] = 0;
                    continue;
                }
 
                for(int r = i - cnt_all - 1;r < j;r++) {
                    int add = j - i;
                    int bl = j - r - 1;
                    int other = cnt_all + add - bl;
 
                    dp[i][j][k] = max(dp[i][j][k], dp[last][r][k - abs(i - j)] + bl * other);
                }
            }
        }
        last = i;
    }
 
    /*for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            for(int k = 0;k < n * n;k++)
                cout << i + 1 << " " << j + 1 << " " << k << " " << dp[i][j][k] << endl;
        }
    }*/
 
    for(int k = 0;k <= n * (n - 1) / 2;k++) {
        int res = 0;
        if (last != -1) {
            for(int j = 0;j < n;j++) {
                res = max(res, dp[last][j][k] + (n - j - 1) * (cnt_all - (n - j - 1)));
            } 
        }
        cout << res << " ";
    }    
}
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    solve();
}