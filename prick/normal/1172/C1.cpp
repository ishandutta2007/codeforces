#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

const int mod = 998244353;

int binpow(int x, int p) {
    if (p == 0) return 1;
    if (p & 1) return x * binpow(x, p - 1) % mod;
    return binpow(x * x % mod, p >> 1);
}

int inv(int x) {
    return binpow(x, mod - 2);
}

const int maxn = 55;

int dp[maxn][maxn][maxn];

int solve(int m, int sum, int sumliked, int w, int is_liked) {
    int direction = (is_liked) ? 1: -1;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int steps = 0; steps < m; ++steps) {
        for (int cnt_liked = 0; cnt_liked <= steps; ++cnt_liked) {
            for (int cnt_me = 0; cnt_me <= steps; ++cnt_me) {
                int cursum = sum + cnt_liked - (steps - cnt_liked);
                int curliked = sumliked + cnt_liked;
                int cur_unliked = cursum - curliked;
                int curw = w + direction * cnt_me;
                if (cursum < curliked || curw < 0) continue;
                if (!dp[steps][cnt_liked][cnt_me]) continue;
                if (is_liked) {
                    curliked -= curw;
                } else {
                    cur_unliked -= curw;
                }
                
                {
                    dp[steps + 1][cnt_liked + is_liked][cnt_me + 1] +=
                        dp[steps][cnt_liked][cnt_me] * curw % mod * inv(cursum);
                    dp[steps + 1][cnt_liked + is_liked][cnt_me + 1] %= mod;
                }
                {
                    dp[steps + 1][cnt_liked + 1][cnt_me] += 
                        dp[steps][cnt_liked][cnt_me] * curliked % mod * inv(cursum);
                    dp[steps + 1][cnt_liked + 1][cnt_me] %= mod;
                }
                {
                    dp[steps + 1][cnt_liked][cnt_me] +=
                        dp[steps][cnt_liked][cnt_me] * cur_unliked % mod * inv(cursum);
                    dp[steps + 1][cnt_liked][cnt_me] %= mod;
                }
            }
        }
    }
    int ans = 0;
    for (int cnt_liked = 0; cnt_liked <= m; ++cnt_liked) {
        for (int cnt_me = 0; cnt_me <= m; ++cnt_me) {
            ans += dp[m][cnt_liked][cnt_me] * (w + direction * cnt_me);
            ans %= mod;
        }
    }
    if (ans < 0) ans += mod;
    return ans;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> w(n);
    int sum = 0;
    int sumliked = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (a[i]) {
            sumliked += w[i];
        }
        sum += w[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cout << solve(m, sum, sumliked, w[i], a[i]) << '\n';
    }
}