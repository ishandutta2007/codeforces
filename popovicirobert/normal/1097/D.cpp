#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e6;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

int inv[60];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int k, i, j;
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    vector < pair <ll, int> > divi;
    ll d = 2;
    while(d * d <= n) {
        int e = 0;
        while(n % d == 0) {
            e++;
            n /= d;
        }
        if(e > 0) {
            divi.push_back({d, e});
        }
        d++;
    }
    if(n > 1) {
        divi.push_back({n, 1});
    }
    for(i = 1; i < 60; i++) {
        inv[i] = lgput(i, MOD - 2);
    }
    int ans = 1;
    for(auto it : divi) {
        vector <int> dp(it.second + 1, 0);
        dp[it.second] = 1;
        for(i = 1; i <= k; i++) {
            vector <int> cur(it.second + 1, 0);
            for(j = 0; j <= it.second; j++) {
                int x = (1LL * dp[j] * inv[j + 1]) % MOD;
                if(x == 0) {
                    continue;
                }
                for(int p = 0; p <= j; p++) {
                    cur[p] += x;
                    mod(cur[p]);
                }
            }
            swap(dp, cur);
        }
        int pw = 1, cur = 0;
        for(i = 0; i <= it.second; i++) {
            cur = (cur + 1LL * pw * dp[i]) % MOD;
            pw = (1LL * pw * (it.first % MOD)) % MOD;
        }
        ans = (1LL * ans * cur) % MOD;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}