#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 2e6 + 5;

bool ciur[MAXN + 1], bad[MAXN + 1];
char ok[MAXN + 1];

ll sp[MAXN + 1];

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

int arr[MAXN + 1];

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
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    memset(ok, -1, sizeof(ok));
    for(i = 2; i <= k; i++) {
        if(ciur[i] == 0) {
            for(int j = i; j <= k; j += i) {
                ciur[j] = 1;
                ok[j] *= -1;
            }
            for(ll j = 1LL * i * i; j <= k; j += 1LL * i * i) {
                bad[j] = 1;
            }
        }
    }
    for(i = 1; i <= k; i++) {
        arr[i] = lgput(i, n);
    }
    for(int x = 2; x <= k; x++) {
        if(bad[x] == 0) {
            int nr = 0;
            for(int i = 0; i <= k; i += x) {
                sp[i] += arr[nr] * ok[x];
                sp[min(i + x, k + 1)] -= arr[nr] * ok[x];
                nr++;
            }
        }
    }
    int ans = 0;
    for(i = 1; i <= k; i++) {
        sp[i] += sp[i - 1];
        sp[i] += 1LL * MOD * MOD;
        sp[i] %= MOD;
        int val = arr[i] - sp[i] + MOD;
        mod(val);
        ans += (val ^ i);
        mod(ans);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}