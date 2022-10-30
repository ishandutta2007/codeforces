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


string f(int num) {
    string s = "";
    for(int i = 0;i < num;i++)
        s += '*';

    return s;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n, l, k;
    cin >> n >> l >> k;
    n++;
    vector<int> p(n), a(n);
    for(int i = 1;i < n;i++) 
        cin >> p[i];
    for(int i = 1;i < n;i++)
        cin >> a[i];

    int max_c = 201;
    vector<vector<vector<double>>> dp(n, vector<vector<double>> (n + 1, vector<double>(2 * max_c + 1, 0.0)));

    dp[0][0][k + max_c] = 1;

    for(int i = 1;i < n;i++) {
        for(int j = 0;j <= n;j++) {
            for(int w = 0;w <= 2 * max_c;w++) {
                double c = (double)p[i] / 100;
                if (j != 0 && w - a[i] >= 0 && w - a[i] <= 2 * max_c) dp[i][j][w] += c * dp[i - 1][j - 1][w - a[i]];
                dp[i][j][w] += (1.0 - c) * dp[i - 1][j][w];

                //if (i == 1 && j == 2 && w == 6) cout << dp[i][j][w] << endl;

                if (w == 2 * max_c && j != 0) {
                    for(int p_w = 2 * max_c - a[i] + 1;p_w <= 2 * max_c;p_w++) {
                        dp[i][j][w] += c * (dp[i - 1][j - 1][p_w]);
                        //if (i == 1 && j == 2) cout << dp[i][j][w] << endl;
                    }
                }

                //cout << i << " " << j << " " << w - max_c << " " << dp[i][j][w] << endl;
            }
        }
    }

    double res = 0;
    for(int i = l;i <= n;i++) 
        for(int j = max_c;j <= 2 * max_c;j++) 
            res += dp[n - 1][i][j];

    cout << res << endl;
}