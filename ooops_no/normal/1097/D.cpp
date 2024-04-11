#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 100, MOD = 1e9 + 7;
int inv[N];
int n, k;

int pow(int a, int n){
    if (n == 0) return 1;
    if (n % 2 == 0){
        int g = pow(a, n / 2);
        return (g * g % MOD);
    }
    else{
        return (pow(a, n - 1) * a % MOD);
    }
}

int solve(int a, int b){
    vector<vector<int>> dp(k + 1, vector<int>(b + 1));
    vector<int> po(b + 1, 1);
    for (int i = 1; i <= b; i++) po[i] = (po[i - 1] * a) % MOD;
    dp[0][b] = 1;
    for (int i = 0; i < k; i++){
        for (int j = 0; j <= b; j++){
            for (int k = 0; k <= j; k++){
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j] * inv[j + 1]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= b; i++){
        ans = (ans + po[i] * dp[k][i]) % MOD;
    }
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++) inv[i] = pow(i, MOD - 2);
    int now = 2;
    cin >> n >> k;
    vector<pair<int,int>> a;
    for (int i = 2; i * i <= n; i++){
        if (n % now == 0){
            int cnt = 0;
            while(n % now == 0){
                n /= now;
                cnt++;
            }
            a.pb({now, cnt});
        }
        now++;
    }
    if (n > 1) a.pb({n, 1});
    int ans = 1;
    for (auto to : a){
        ans = (ans * solve(to.first, to.second)) % MOD;
    }
    cout << ans << endl;
    return 0;
}