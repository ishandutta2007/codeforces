#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 1e6;
const int MOD = (int) 1e9 + 7;

ll v[MAXN + 1];
ll v1[MAXN + 1], v2[MAXN + 1];

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

int fact[MAXN + 1], invfact[MAXN + 1];

inline int comb(int n, int k) {
    return (1LL * fact[n] * ((1LL * invfact[k] * invfact[n - k]) % MOD)) % MOD;
}

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    if(n == 1) {
        cout << v[1];
        return 0;
    }
    if(n % 2 == 1) {
        for(i = 2; i <= n; i++)
           if(i % 2 == 0) {
              v[i - 1] = v[i] + v[i - 1];
              if(v[i - 1] >= MOD)
                 v[i - 1] -= MOD;
           }
           else {
              v[i - 1] = v[i - 1] - v[i];
              if(v[i - 1] < 0)
                 v[i - 1] += MOD;
           }
        n--;
    }
    int sz1 = 0, sz2 = 0;
    for(i = 1; i <= n; i += 2)
        v1[++sz1] = v[i];
    for(i = 2; i <= n; i += 2)
        v2[++sz2] = v[i];
    fact[0] = 1;
    invfact[0] = 1;
    for(i = 1; i <= sz1; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        invfact[i] = lgput(fact[i], MOD - 2);
    }
    int ans1 = 0, ans2 = 0;
    for(i = 1; i <= sz1; i++) {
        ans1 = (ans1 + 1LL * comb(sz1 - 1, i - 1) * v1[i]) % MOD;
        ans2 = (ans2 + 1LL * comb(sz2 - 1, i - 1) * v2[i]) % MOD;
    }
    int ans;
    if(n % 4 == 0)
        ans = ans1 - ans2;
    else
        ans = ans1 + ans2;
    if(ans < 0)
        ans += MOD;
    if(ans >= MOD)
        ans -= MOD;
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}