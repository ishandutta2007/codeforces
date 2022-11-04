#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = 65;

ll dp[MAXN + 1][10][1 << 10];

inline ll solve(ll x, int b) {
    if(x == 0) {
        return 0;
    }
    vector <int> conf;
    while(x > 0) {
        conf.push_back(x % b);
        x /= b;
    }
    reverse(conf.begin(), conf.end());
    int sz = conf.size();
    ll ans = 0;
    for(int i = 1; i < sz; i++) {
        ans += dp[i][b][0] - dp[i - 1][b][1];
    }
    int mask = 0;
    for(int i = 0; i < sz; i++) {
        for(int dig = (i == 0); dig < conf[i]; dig++) {
            mask ^= (1 << dig);
            ans += dp[sz - i - 1][b][mask];
            mask ^= (1 << dig);
        }
        mask ^= (1 << conf[i]);
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int q;
    ios::sync_with_stdio(false);
    for(int b = 2; b <= 10; b++) {
        dp[0][b][0] = 1;
        for(int len = 1; len <= MAXN; len++) {
            for(int conf = 0; conf < (1 << b); conf++) {
                for(int dig = 0; dig < b; dig++) {
                    dp[len][b][conf] += dp[len - 1][b][conf ^ (1 << dig)];
                }
            }
        }
    }
    cin >> q;
    while(q > 0) {
        q--;
        ll l, r;
        int b;
        cin >> b >> l >> r;
        cout << solve(r + 1, b) - solve(l, b) << "\n";
        //printf("\n");
    }
    //cin.close();
    //cout.close();
    return 0;
}