#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>

mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e18 + 7;
const int N = 2e5 + 3;

void run() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d(n+1), a(n+1);
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    d[n] = l;

    vector<vector<int>> dp(n+1, vector<int>(n+1, inf));
    for (int i = 0; i <= n; ++i)
        dp[0][i] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int del = 0; del <= n; ++del) {
            for (int j = i-1; j >= 0; --j) {
                if (i - j - 1 > del) break;
                chkmin(dp[i][del], (d[i] - d[j]) * a[j] + dp[j][del-(i-j-1)]);
            }
        }
    }
    cout << dp[n][k] << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}