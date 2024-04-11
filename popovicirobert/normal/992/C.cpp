#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;

inline int lgput(int a, ll b) {
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
    int i;
    ll x, k;
    ios::sync_with_stdio(false);
    cin >> x >> k;
    if(x == 0) {
        cout << 0;
        return 0;
    }
    x %= MOD;
    int ans;
    if(k == 0) {
        ans = (2LL * x) % MOD;
    }
    else if(k == 1) {
        ans = (4LL * x - 1 + MOD) % MOD;
    }
    else {
        ans = (1LL * lgput(2, k + 1) * x) % MOD;
        ans -= (lgput(2, k) - 1);
        ans += MOD;
        ans %= MOD;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}