#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e4;

vector <int> qry[MAXN + 2];
ll dp[MAXN + 1];

inline void add(int val, int n) {
    for(int i = n; i >= val; i--) {
        dp[i] += dp[i - val];
        dp[i] %= MOD;
    }
}

inline void sub(int val, int n) {
    for(int i = val; i <= n; i++) {
        dp[i] = (dp[i] - dp[i - val] + MOD) % MOD;
    }
}

bool ok[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q, l, r, x;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for(i = 1; i <= q; i++) {
        cin >> l >> r >> x;
        qry[l].push_back(x);
        qry[r + 1].push_back(-x);
    }
    int cnt = 0;
    dp[0] = 1;
    for(i = 1; i <= n; i++) {
        for(auto it : qry[i]) {
            if(it > 0) {
                add(it, n);
            }
            else {
                sub(-it, n);
            }
        }
        for(int j = 1; j <= n; j++) {
            if(dp[j] != 0) {
                if(ok[j] == 0) {
                    cnt++;
                }
                ok[j] = 1;
            }
        }
    }
    cout << cnt << "\n";
    for(i = 1; i <= n; i++) {
        if(ok[i])
            cout << i << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}