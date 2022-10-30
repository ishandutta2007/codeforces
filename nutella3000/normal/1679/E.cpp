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
 
 
const int inf = 1e15 + 7;
const int N = (1 << 17), alp = 18, M = 1003;
const int mod = 998244353;

int dp[N][alp];
int pows[alp][M];

void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
int sum(int a, int b) {
    int r = a + b;
    if (r >= mod) r -= mod;
    return r;
}

void run() {
    int n, q; string s;
    cin >> n >> s >> q;

    int cnt_que = 0;
    for (int i = 0; i < n; ++i)
        cnt_que += s[i] == '?';

    for (int i = 1; i < alp; ++i) {
        pows[i][0] = 1;
        for (int j = 1; j < M; ++j)
            pows[i][j] = pows[i][j-1] * i % mod;
    }

    for (int d = 0; d < 2; ++d) {
        for (int mid = 0; mid < n; ++mid) {
            int mask = 0, cnt_del = 0; 
            for (int i = 0; mid-i-d >= 0 && mid+i < n; ++i) {
                int l = mid-i-d, r = mid+i;
                if (s[l] == s[r] && s[l] == '?') {
                    if (l != r) ++cnt_del;
                }else if (s[l] == '?' || s[r] == '?') {
                    ++cnt_del;
                    mask |= 1 << (s[l] == '?' ? s[r] - 'a' : s[l] - 'a');
                } else if (s[l] != s[r]) break;

                for (int i = 1; i < alp; ++i)
                    add(dp[mask][i], pows[i][cnt_que - cnt_del]);
            }
        }
    }
    for (int i = 0; i < alp-1; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j >> i & 1) {
                for (int q = 1; q < alp; ++q)
                    dp[j][q] += dp[j ^ (1<<i)][q];
            }
        }
    }
    for (int it = 0; it < q; ++it) {
        string t; cin >> t;
        int mask = 0;
        for (auto i : t)
            mask |= (1 << i-'a');
        cout << dp[mask][siz(t)] % mod << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}