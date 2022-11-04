#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e5;

int dp[2][1 << 19];

bool ciur[101];
vector <int> primes;

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

int fact[MAXN + 1];

inline int comb(int n, int k) {
    return (1LL * fact[n] * lgput((1LL * fact[n - k] * fact[k]) % MOD, MOD - 2)) % MOD;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

int fr[100];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, j, conf;
    ios::sync_with_stdio(false);
    for(i = 2; i * i <= 100; i++) {
        if(ciur[i] == 0)
           for(j = i * i; j <= 100; j += i)
               ciur[j] = 1;
    }
    for(i = 2; i <= 70; i++) {
        if(ciur[i] == 0)
           primes.push_back(i);
    }
    fact[0] = 1;
    for(i = 1; i <= MAXN; i++)
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x;
        fr[x]++;
    }
    dp[0][0] = 1;
    for(i = 1; i <= 70; i++) {
        int cnf = 0;
        int nr = i;
        for(j = 0; j < primes.size(); j++) {
            int cnt = 0;
            while(nr % primes[j] == 0) {
                nr /= primes[j];
                cnt++;
            }
            cnf += (1 << j) * (cnt & 1);
        }
        int nr0, nr1;
        nr0 = nr1 = 0;
        for(j = 0; j <= fr[i]; j++) {
            if(j % 2 == 0)
                nr0 += comb(fr[i], j);
            else
                nr1 += comb(fr[i], j);
            mod(nr0);
            mod(nr1);
        }
        for(conf = 0; conf < (1 << primes.size()); conf++) {
            dp[i & 1][conf] = (1LL * nr0 * dp[1 - i & 1][conf]) % MOD;
            int aux = 0;
            aux = (conf ^ cnf);
            dp[i & 1][conf] = (dp[i & 1][conf] + 1LL * dp[1 - i & 1][aux] * nr1) % MOD;
        }
    }
    cout << (dp[0][0] - 1 + MOD) % MOD;
    //cin.close();
    //cout.close();
    return 0;
}