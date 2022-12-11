#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = (int)1e9 + 7;
int powr(int n, int p){
    if(p == 0) return 1;
    int f = powr(n, p / 2);
    f = (f * 1ll * f) % MOD;
    if(p % 2 == 1) f = (f * 1ll * n) % MOD;
    return f;
}
ll n;
int k;

const int N = 55;
const int M = (int)1e4 + 10;

int dp[N][M];


int solve(int d, int pw){
    for(int i = 0 ; i < N; i ++ ){
        for(int j = 0 ; j <= k ; j ++ ){
            dp[i][j] = 0;
        }
    }
    dp[pw][0] = 1;
    int inv = 0;
    for(int iter = 0; iter < k; iter ++ ){
        inv = 0;
        for(int i = pw; i >= 0 ; i -- ){
            inv = (inv + (powr(i + 1, MOD - 2) * 1ll * dp[i][iter]) % MOD) % MOD;
            dp[i][iter + 1] = inv;
        }
    }
    int f = 0;
    int ff = 1;
    for(int i = 0 ; i <= pw; i ++ ){
        f = (f + (dp[i][k] * 1ll * ff) % MOD) % MOD;
        ff = (ff * 1ll * d) % MOD;
    }
    return f;
}

int outp = 1;

void fac(){
    int pi;
    for(ll x = 2; x * x <= n; x ++ ){
        if(n % x == 0){
            pi = 0;
            while(n % x == 0){
                n /= x;
                pi ++ ;
            }
            outp = (outp * 1ll * solve(x, pi)) % MOD;
        }
    }
    if(n != 1){
        outp = (outp * 1ll * solve(n % MOD, 1)) % MOD;
    }
}


int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    cin >> n >> k;
    fac();
    cout << outp << "\n";
    return 0;
}