#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 43

using namespace std;

string str;

const int MOD = (int) 1e9 + 7;
const int MAXN = 1000;

int bit[MAXN + 1];
int v[MAXN + 1];

int fact[MAXN + 1];

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

inline int comb(int n, int k) {
    return (1LL * fact[n] * lgput((1LL * fact[k] * fact[n - k]) % MOD, MOD - 2)) % MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, k;
    ios::sync_with_stdio(false);
    cin >> str >> k;
    int n = str.size();
    for(i = 2; i <= n; i++) {
        bit[i] = __builtin_popcount(i);
        v[i] = v[bit[i]] + 1;
    }
    fact[0] = 1;
    for(i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    int ans = 0;
    for(i = 1; i <= n; i++) {
        if(v[i] + 1 == k) {
            int cnt = i;
            for(int j = 0; j < n; j++) {
                if(str[j] == '1' && cnt <= n - j - 1 && cnt >= 0) {
                    ans += comb(n - j - 1, cnt);
                    if(ans >= MOD)
                        ans -= MOD;
                    cnt--;
                }
            }
        }
    }
    int cnt = 0;
    for(i = 0; i < n; i++) {
        cnt += str[i] - '0';
    }
    if(k == 1 && n > 1) {
        ans--;
        ans += MOD;
        if(ans >= MOD)
            ans -= MOD;
    }
    if(n > 1 && v[cnt] + 1 == k) {
        ans++;
        if(ans >= MOD)
            ans -= MOD;
    }
    if(k == 0)
        ans = 1;
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}