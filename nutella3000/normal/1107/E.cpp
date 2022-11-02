#include <bits/stdc++.h>
 
using namespace std;
 
#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;
const int max_n = 103;

int n;
string s;

int a[max_n], dp[max_n][max_n][2][max_n], res[max_n][max_n];

void solve() {
    cin >> n >> s;

    for(int i = 1;i <= n;i++)
        cin >> a[i];

    for(int l = 0;l < n;l++) {
        for(int r = l;r < n;r++) {
            for(int num = 0;num < 2;num++) {
                for(int len = 0;len <= n;len++) {
                    dp[l][r][num][len] = -inf;
                }
            }
        }
    }

    for(int len = 1;len <= n;len++) {
        for(int l = 0;l <= n - len;l++) {
            int r = l + len - 1;
            for(int num = 0;num < 2;num++) {
                for(int cnt = 1;cnt <= n;cnt++) {
                    for(int mid = l;mid <= r;mid++) {
                        if (s[mid] != '0' + num) continue;
                        chkmax(dp[l][r][num][cnt], (mid == l ? 0 : res[l][mid - 1]) + 
                            (mid == r ? (cnt == 1 ? 0 : -inf) : dp[mid + 1][r][num][cnt - 1]));
                    }
                    //cout << l << " " << r << " " << num << " " << cnt << endl;
                    chkmax(res[l][r], dp[l][r][num][cnt] + a[cnt]);
                }
            }
        }
    }

    cout << res[0][n - 1];
}



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}