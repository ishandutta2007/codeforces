#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 1e9 + 7;

int mul(int a, int b){
    return (a * b % MOD);
}

int binpow(int a, int n){
    if (n == 0) return 1;
    if (n % 2 == 0){
        int g = binpow(a, n / 2);
        return mul(g, g);
    }
    else{
        return mul(binpow(a, n - 1), a);
    }
}

int add(int a, int b){
    a += b;
    if (a > MOD) a -= MOD;
    return a;
}

int sub(int a, int b){
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int dv(int a, int b){
    return mul(a, binpow(b, MOD - 2));
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), f(1 << n);
    vector<vector<int>> b(1 << n, vector<int>(n));
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); i++){
        for (int j = 0; j < n; j++){
            if (!(i & (1 << j))){
                b[i][j] = 1;
                for (int k = 0; k < n; k++){
                    if (i & (1 << k)){
                        b[i][j] = mul(b[i][j], dv(a[j], a[j] + a[k]));
                    }
                }
            }
        }
    }
    for (int i = 1; i < (1 << n); i++){
        f[i] = 1;
        for (int j = i; j; j = (j - 1) & i){
            if (j == i) continue;
            vector<int> aa, bb;
            int now = 1;
            for (int k = 0; k < n; k++){
                if (i & (1 << k)){
                    if (!(j & (1 << k))){
                        now = mul(now, b[j][k]);
                    }
                }
            }
            f[i] = sub(f[i], mul(f[j], now));
        }
    }
    int ans = 0;
    for (int i = 1; i < (1 << n); i++){
        int now = 1;
        for (int j = 0; j < n; j++){
            if ((i & (1 << j))){
                now = mul(now, b[i ^ ((1 << n) - 1)][j]);
            }
        }
        ans = add(ans, mul(__builtin_popcount(i), mul(f[i], now)));
    }
    cout << ans << endl;
    return 0;
}