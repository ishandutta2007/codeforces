#include<bits/stdc++.h>
using namespace std;
 
//#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int N = 259;

int dp[N][N][2*N];

void run() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i) {
        for (int x = 0; x <= m; ++x) {
            fill(dp[i][x], dp[i][x] + 2*N, inf);
            for (int val = -m; val <= m; ++val) {
                if (i == n-1 && val != 0) continue;

                int le = (a[i]+val-x);
                if (abs(le) <= m)
                dp[i][x][val+N] = (i ? dp[i-1][x][le + N] : (le == 0 ? 0 : inf)) + abs(le);
            }
        }
        for (int x = m-1; x >= 0; --x) {
            for (int val = 0; val < 2*N; ++val) {
                chmin(dp[i][x][val], dp[i][x+1][val]);
            }
        }
    }
    cout << dp[n-1][0][N] << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}