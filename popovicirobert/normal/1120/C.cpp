#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const int MOD1 = (int) 1e9 + 7;
const int MOD2 = (int) 1e9 + 7;
const int MAXN = 5000;
const int B1 = 41;
const int B2 = 43;

char str[MAXN + 1];
ll dp[MAXN + 1];

short ind[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a, b;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> a >> b;
    cin >> str + 1;
    for(i = 1; i <= n; i++) {
        str[i] -= 'a' - 1;
    }
    int pw1 = 1, pw2 = 1;
    for(int len = 0; len < n; len++) {
        unordered_map <ll, int> mp;
        int cur1 = 0, cur2 = 0;
        for(i = 1; i <= n; i++) {
            cur1 = (1LL * cur1 * B1 + str[i]) % MOD1;
            cur2 = (1LL * cur2 * B2 + str[i]) % MOD2;
            if(i > len) {
                ll cur = 1LL * cur1 * MOD2 + cur2;
                if(mp[cur] == 0) {
                    mp[cur] = i;
                }
                ind[i - len][i] = mp[cur];
                cur1 -= (1LL * pw1 * str[i - len]) % MOD1;
                cur2 -= (1LL * pw2 * str[i - len]) % MOD2;
                if(cur1 < 0) {
                    cur1 += MOD1;
                }
                if(cur2 < 0) {
                    cur2 += MOD2;
                }
            }
        }
        pw1 = (1LL * pw1 * B1) % MOD1;
        pw2 = (1LL * pw2 * B2) % MOD2;
    }
    for(i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + a;
        for(int j = i - 1; j >= 1; j--) {
            if(ind[j + 1][i] <= j) {
                dp[i] = min(dp[i], dp[j] + b);
            }
        }
    }
    cout << dp[n];
    //cin.close();
    //cout.close();
    return 0;
}