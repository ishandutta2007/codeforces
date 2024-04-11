#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;

void run() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vector<vector<bool>> dp1(n, vector<bool>(m)), dp2(n, vector<bool>(m));

    dp1[0][0] = s[0] == t[0];
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dp1[i][j] = dp1[i-1][j] || (s[i] == t[j] && (!j || dp1[i-1][j-1]));

    dp2[n-1][m-1] = s[n-1] == t[m-1];
    for (int i = n-2; i >= 0; --i)
        for (int j = m-1; j >= 0; --j)
            dp2[i][j] = dp2[i+1][j] || (s[i] == t[j] && (j == m-1 || dp2[i+1][j+1]));

    int res = inf;
    vector<int> lens(m+1, 0);

    for (int l = n-1; l >= 0; --l) {
        for (int i = 0; i < m; ++i)
            lens[i] = (s[l] == t[i] ? lens[i+1] + 1 : 0);

        if (!l) continue;
        for (int k = m-2; k >= 0; --k) {
            if ((!k || dp1[l-1][k-1]) && dp2[l][k]) {
                chmin(res, n+1 - lens[k] + (l - k));
            }
        }
    }
    if (dp1[n-1][m-1]) chmin(res, n-lens[0]);

    cout << (res == inf ? -1 : res) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}