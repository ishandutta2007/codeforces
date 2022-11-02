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
const int N = 1 << 20, mod = 1e9 + 7;

void run() {
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    int res = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < m; ++k) {
                cnt += abs(s[i][k] - s[j][k]);
            }
            chmin(res, cnt);
        }
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}