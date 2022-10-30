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
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int N = 500;

void run() {
    string s; cin >> s;
    int n = siz(s);
    vector<vector<int>> pre(n+1, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        pre[i+1][0] = pre[i][0];
        pre[i+1][1] = pre[i][1];
        ++pre[i+1][s[i]-'0'];
    }
    int res = inf;
    int c0 = pre[n][0], c1 = 0;
    for (int str = n; str >= 0; --str) {
        if (str != n) {
            if (s[str] == '0') --c0;
            else ++c1;
        }
        int l = -1, r = str;

        while (r - l > 1) {
            int m = (l + r) / 2;
            int nc0 = c0 - pre[m+1][0];
            int nc1 = c1 + pre[m+1][1];
            if (nc1 >= nc0) r = m;
            else l = m;
        }
        int val = min(max(c0 - pre[l+1][0], c1 + pre[l+1][1]), max(c0 - pre[r+1][0], c1 + pre[r+1][1]));
        chmin(res, val);
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}