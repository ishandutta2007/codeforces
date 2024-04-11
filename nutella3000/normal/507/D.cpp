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
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> pows1(n), pows2(n);
    pows1[0] = pows2[0] = 1;
    for (int i = 1; i < n; ++i) {
        pows1[i] = pows1[i-1] * 10 % k;
        pows2[i] = pows2[i-1] * 10 % m;
    }

    vector<vector<int>> cnt(n+1, vector<int>(k+1));

    for (int i = 1; i < 10; ++i) {
        ++cnt[1][i % k];
    }

    for (int i = 1; i < n; ++i) {
        for (int num = 0; num < 10; ++num) {
            for (int j = 1; j < k; ++j) {
                if (i == n-1 && num == 0) continue;
                cnt[i+1][(num * pows1[i] + j) % k] += cnt[i][j];
            }
            if (num != 0) ++cnt[i+1][num * pows1[i] % k];
        }
        for (int j = 0; j < k; ++j) {
            cnt[i+1][j] %= m;
        }
    }
    int res = cnt[n][0];
    for (int i = 1; i < n; ++i) {
        res += cnt[i][0] * 9 * pows2[n-i-1] % m;
    }
    cout << res % m << endl;
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}