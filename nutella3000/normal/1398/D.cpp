#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;




signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n[3];
    cin >> n[0] >> n[1] >> n[2];
    vector<int> a[3];
    for(int i = 0;i < 3;i++) {
        a[i].resize(n[i]);
        for(int j = 0;j < n[i];j++) 
            cin >> a[i][j];
        a[i].emplace_back(0);
        sort(all(a[i]));
    }

    vector<int> dp[n[0] + 1][n[1] + 1];

    for(int i = 0;i <= n[0];i++) {
        for(int j = 0;j <= n[1];j++) {
            dp[i][j].resize(n[2] + 1, 0);
            for(int k = 0;k <= n[2];k++) {
                for(int num1 = 0;num1 < 3;num1++) {
                    for(int num2 = num1 + 1;num2 < 3;num2++) {
                        int r[]{i, j, k};
                        if (r[num1] == 0 || r[num2] == 0) continue;
                        int num = a[num1][r[num1]] * a[num2][r[num2]];
                        r[num1]--;
                        r[num2]--;
                        dp[i][j][k] = max(dp[i][j][k], num + dp[r[0]][r[1]][r[2]]);
                    }
                }
            }
        }
    }

    cout << dp[n[0]][n[1]][n[2]];
}