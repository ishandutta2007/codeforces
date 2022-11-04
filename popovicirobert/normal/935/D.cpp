#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e5;

int a[MAXN + 1], b[MAXN + 1];

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

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, i;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int a0 = 0, b0 = 0;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        a0 += (a[i] == 0);
    }
    for(i = 1; i <= n; i++) {
        cin >> b[i];
        b0 += (b[i] == 0);
    }
    int p = 0, q = lgput(lgput(m, a0 + b0), MOD - 2);
    int cur = 1;
    for(i = 1; i <= n; i++) {
        a0 -= (a[i] == 0);
        b0 -= (b[i] == 0);
        if(a[i] > 0) {
            if(b[i] > 0) {
                if(a[i] > b[i]) {
                    p = (p + 1LL * lgput(m, a0 + b0) * cur) % MOD;
                    //mod(p);
                    cur = 0;
                }
                else if(a[i] < b[i]) {
                    cur = 0;
                }
            }
            else {
                p = (p + 1LL * lgput(m, a0 + b0) * ((1LL * (a[i] - 1) * cur) % MOD)) % MOD;
            }
        }
        else {
            if(b[i] > 0) {
                p = (p + 1LL * lgput(m, a0 + b0) * ((1LL * (m - b[i]) * cur) % MOD)) % MOD;
            }
            else {
                p = (p + 1LL * lgput(m, a0 + b0) * ((1LL * ((1LL * (m - 1) * m / 2) % MOD) * cur) % MOD)) % MOD;
                cur = (1LL * cur * m) % MOD;
            }
        }
    }
    cout << (1LL * p * q) % MOD;
    //cin.close();
    //cout.close();
    return 0;
}