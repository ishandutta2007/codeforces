#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 500, MOD = 1e9 + 7;
int dp[N][N];
int inv[N];
int c[N][N];

int mul(int a, int b){
    return (a * b) % MOD;
}

int sum(int a, int b){
    return (a + b + MOD) % MOD;
}

int pow(int a, int n){
    if (n == 0) return 1;
    if (n % 2 == 1){
        return (pow(a, n - 1) * a % MOD);
    }
    else{
        int g = pow(a, n / 2);
        return (g * g % MOD);
    }
}

int cnk(int n, int k){
    int ans = 1;
    for (int i = n - k + 1; i <= n; i++){
        ans = mul(ans, i);
    }
    for (int i = 1; i <= k; i++){
        ans = mul(ans, inv[i]);
    }
    return ans;
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++){
        inv[i] = pow(i, MOD - 2);
    }
    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    c[0][0] = 1;
    for (int i = 1; i < N; i++){
        for (int j = 0; j < N; j++){
            dp[i][j] = dp[i - 1][j];
            if (j > 0) dp[i][j] = sum(dp[i][j], mul(dp[i - 1][j - 1], (i - 1)));
            c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    vector<int> cnt(2);
    cnt[0] = 1, cnt[1] = 0;
    for (int j = 1; j <= k; ++j){
        for (int i = 1; i <= min(n, 2 * j); ++i){
            int ans = 0;
            for (int f = 0; f <= i; ++f){
                if (f % 2 == 1){
                    ans = sum(-1 * mul(c[i][f], dp[i - f][j]), ans);
                }
                else{
                    ans = sum(mul(c[i][f], dp[i - f][j]), ans);
                }
            }
            cnt[j % 2] = sum(cnt[j % 2], cnk(n, i) * ans);
        }
        cout << cnt[j % 2] << ' ';
    }
    cout << endl;
    return 0;
}