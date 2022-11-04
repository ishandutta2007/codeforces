#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const int MOD = (ll) 1e9 + 7;

const int N = (int) 2e6 + 123;
const int K = 20;

int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    
    if (y & 1) {
        return power(x, y - 1) * 1LL * x % MOD;
    } else {
        int tmp = power(x, y / 2);
        return tmp * 1LL * tmp % MOD;
    }
}

int fact[N];
int rfact[N];
int minp[N];
int dp[N][K];

int cnk(int n, int k) {
    return fact[n] * 1LL * rfact[k] % MOD * 1LL * rfact[n - k] % MOD;
}

void run() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * 1LL * i % MOD;
    }
    for (int i = 0; i < N; i++) {
        rfact[i] = power(fact[i], MOD - 2);
    }
    
    fill(minp, minp + N, -1);
    for (int i = 2; i < N; i++) {
        if (minp[i] == -1) {
            minp[i] = i;
            
            for (int j = 2 * i; j < N; j += i) {
                if (minp[j] == -1) {
                    minp[j] = i;
                }
            }
        }
    }
    
    fill(dp[0], dp[0] + K, 2);
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j < K; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int r, n;
        cin >> r >> n;
        
        vector<int> cnt;
        
        while (n > 1) {
            int cur = minp[n];
            int c = 1;
            
            while (minp[n / cur] == cur) {
                n /= cur;
                c++;
            }
            
            n /= cur;
            cnt.push_back(c);
        }
        
        int ans = 1;
        for (int c : cnt) {
            ans = ans * 1LL * dp[r][c] % MOD;
        }
        
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}