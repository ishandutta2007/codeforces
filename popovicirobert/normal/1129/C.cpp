#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = 3005;
const int B = 37;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

unordered_map <ull, int> mp;

int arr[MAXN + 1];
int dp[MAXN + 1][MAXN + 1];
int sol[MAXN + 1];

bool ok[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }
    for(int len = 1; len < n; len++) {
        for(int l = 1; l + len <= n; l++) {
            int r = l + len;
            int conf = 0;
            for(i = l; i < r && i < l + 4; i++) {
                conf = conf * 2 + arr[i];
                if(i - l < 3 || (i - l == 3 && conf != 3 && conf != 5 && conf != 14 && conf != 15)) {
                    dp[l][r] += dp[i + 1][r];
                    mod(dp[l][r]);
                }
            }
            conf = conf * 2 + arr[r];
            if(len < 3 || (len == 3 && conf != 3 && conf != 5 && conf != 14 && conf != 15)) {
                dp[l][r]++;
                mod(dp[l][r]);
            }
        }
    }
    unordered_map <ull, int> mp;
    ull pw = 1;
    for(int len = 0; len < n; len++) {
        mp.clear();
        ull cur = 0;
        for(i = 1; i <= n; i++) {
            cur = cur * B + arr[i] + 1;
            if(i > len && mp[cur] == 0) {
                mp[cur] = 1;
                ok[i - len][i] = 1;
            }
            if(i > len) {
                cur -= pw * (arr[i - len] + 1);
            }
        }
        pw *= B;
    }
    for(i = 1; i <= n; i++) {
        ull cur = 0;
        for(int j = i; j >= 1; j--) {
            cur = cur * B + arr[j] + 1;
            if(ok[j][i]) {
                sol[i] += dp[j][i];
                mod(sol[i]);
            }
        }
    }

    for(i = 1; i <= n; i++) {
        sol[i] += sol[i - 1];
        mod(sol[i]);
        cout << sol[i] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}