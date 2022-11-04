#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 9;
const ll BIG = 1LL * MOD * MOD;
const int MAXN = (int) 1e5;

char str[MAXN + 1];

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

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, a, b, k, i;
    ios::sync_with_stdio(false);
    cin >> n >> a >> b >> k;
    cin >> str;
    int sum = 0, pwb = 1, pwa = lgput(a, n);
    int inva = lgput(a, MOD - 2);
    for(i = 0; i < k; i++) {
        char sign;
        if(str[i] == '-')
            sign = -1;
        else
            sign = 1;
        sum = (sum + 1LL * sign * pwa * pwb + BIG) % MOD;
        pwb = (1LL * pwb * b) % MOD;
        pwa = (1LL * pwa * inva) % MOD;
    }
    int q = lgput((1LL * b * lgput(a, MOD - 2)) % MOD, k);
    int ans;
    if(q == 1)
        ans = (1LL * sum * (n + 1) / k) % MOD;
    else
        ans = (1LL * sum * ((1LL * (lgput(q, (n + 1) / k) - 1 + MOD) * lgput(q - 1, MOD - 2)) % MOD)) % MOD;
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}