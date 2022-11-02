#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int MOD = 998244353;
const int N = 30, MASK = (1 << 10) + 10;
int k, n;
int dp[N][2][MASK], ans[N][2][MASK];
string s;
vector<int> num(18);

int binpow(int a, int n){
    if (n == 0) return 1;
    if (n % 2 == 0){
        int g = binpow(a, n / 2);
        return ((g * g) % MOD);
    }
    else{
        return ((binpow(a, n - 1) * a) % MOD);
    }
}

int solve(int i, int f, int msk, bool non_zero){
    if (dp[i][f][msk] != -1){
        return dp[i][f][msk];
    }
    dp[i][f][msk] = 0;
    if (!f){
        for (int j = 0; j < 10; j++){
            if (msk & (1 << j)){
                ans[i][0][msk] = (ans[i][0][msk] + (solve(i + 1, 0, msk, 0) * ((j * binpow(10, n - i - 1)) % MOD) % MOD) + (solve(i + 1, 0, (msk ^ (1 << j)), 0) * ((j * binpow(10, n - i - 1)) % MOD)) % MOD + ans[i + 1][0][msk] + ans[i + 1][0][msk ^ (1 << j)]) % MOD;
                dp[i][0][msk] = (dp[i][0][msk] + solve(i + 1, 0, msk, 0) + solve(i + 1, 0, (msk ^ (1 << j)), 0)) % MOD;
            }
        }
    }
    else{
        for (int j = 0; j < s[i] - '0'; j++){
            if (non_zero && j == 0) continue;
            if (msk & (1 << j)){
                ans[i][1][msk] = (ans[i][1][msk] + (solve(i + 1, 0, msk, 0) * ((j * binpow(10, n - i - 1)) % MOD) % MOD) + (solve(i + 1, 0, (msk ^ (1 << j)), 0) * ((j * binpow(10, n - i - 1)) % MOD)) % MOD + ans[i + 1][0][msk] + ans[i + 1][0][msk ^ (1 << j)]) % MOD;
                dp[i][1][msk] = (dp[i][1][msk] + solve(i + 1, 0, msk, 0) + solve(i + 1, 0, (msk ^ (1 << j)), 0)) % MOD;
            }
        }
        int j = s[i] - '0';
        if (msk & (1 << j)){
            ans[i][1][msk] = (ans[i][1][msk] + (solve(i + 1, 1, msk, 0) * ((j * binpow(10, n - i - 1)) % MOD) % MOD) + (solve(i + 1, 1, (msk ^ (1 << j)), 0) * ((j * binpow(10, n - i - 1)) % MOD)) % MOD + ans[i + 1][1][msk] + ans[i + 1][1][msk ^ (1 << j)]) % MOD;
            dp[i][1][msk] = (dp[i][1][msk] + solve(i + 1, 1, msk, 0) + solve(i + 1, 1, (msk ^ (1 << j)), 0)) % MOD;
        }
    }
    return dp[i][f][msk];
}

int gett(int v){
    s = to_string(v);
    n = s.size();
    int anss = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < MASK; k++){
                dp[i][j][k] = -1;
                ans[i][j][k] = 0;
            }
        }
    }
    for (int k = 0; k < MASK; k++){
        dp[n][0][k] = dp[n][1][k] = 0;
    }
    dp[n][0][0] = dp[n][1][0] = 1;
    for (int f = 0; f < MASK; f++){
        solve(0, 1, f, 1);
    }
    for (int f = 0; f < MASK; f++){
        if (__builtin_popcountll(f) <= k){
            anss = (anss + ans[0][1][f]) % MOD;
        }
    }
    return anss;
}

int get(int v){
    if (v == 0){
        return 0;
    }
    int anss = 0;
    for (int i = 1; i < to_string(v).size(); i++){
        anss = (anss + gett(num[i - 1])) % MOD;
    }
    s = to_string(v);
    n = s.size();
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < MASK; k++){
                dp[i][j][k] = -1;
                ans[i][j][k] = 0;
            }
        }
    }
    for (int k = 0; k < MASK; k++){
        dp[n][0][k] = dp[n][1][k] = 0;
    }
    dp[n][0][0] = dp[n][1][0] = 1;
    for (int f = 0; f < MASK; f++){
        solve(0, 1, f, 1);
    }
    for (int f = 0; f < MASK; f++){
        if (__builtin_popcountll(f) <= k){
            anss = (anss + ans[0][1][f]) % MOD;
        }
    }
    return anss;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    num[0] = 9;
    for (int i = 1; i < 17; i++){
        num[i] = num[i - 1] * 10 + 9;
    }
    int l, r;
    cin >> l >> r >> k;
    cout << ((get(r) - get(l - 1) + MOD) % MOD) << endl;
    return 0;
}