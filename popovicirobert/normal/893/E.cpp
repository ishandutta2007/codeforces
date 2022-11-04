#include <bits/stdc++.h>
#define lsb(x)
#define ll long long

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e6;

int ciur[MAXN + 1];
int p2[MAXN + 1];

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

int fact[MAXN + 100];

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

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, x, y, q;
    ios::sync_with_stdio(false);
    cin >> q;
    for(i = 2; i <= MAXN; i++) {
        if(ciur[i] == 0)
           for(j = i; j <= MAXN; j += i)
               ciur[j] = i;
    }
    p2[1] = 1;
    for(i = 2; i <= MAXN; i++) {
        p2[i] = (p2[i - 1] << 1);
        mod(p2[i]);
    }
    fact[0] = 1;
    for(i = 1; i <= MAXN + 100; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    while(q > 0) {
        q--;
        cin >> x >> y;
        int ans = 1;
        while(x > 1) {
            int cnt = 0, val = ciur[x];
            while(ciur[x] == val) {
                x /= val;
                cnt++;
            }
            ans = (1LL * ans * comb(y + cnt - 1, y - 1)) % MOD;
        }
        ans = (1LL * ans * p2[y]) % MOD;
        cout << ans << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}