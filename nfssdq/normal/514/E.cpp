/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

#define MX 102

LL mul_res[MX][MX];
void multiply(LL a[][MX], LL b[][MX]){
    set0(mul_res);
    for(int i = 0; i < MX; i++){
        for(int j = 0; j < MX; j++){
            for(int k = 0; k < MX; k++)
                mul_res[i][j] = (mul_res[i][j] + a[i][k] * b[k][j]) % mod;
        }
    }
}

LL big_res[MX][MX];
LL init[MX][MX];
void matrix_expo(LL n){
    if(n == 0){
        set0(big_res);
        REP(i, MX)big_res[i][i] = 1;
        return;
    }
    if(n % 2 == 0){
        matrix_expo(n / 2);
        multiply(big_res, big_res);
        REP(i, MX){
            REP(j, MX)big_res[i][j] = mul_res[i][j];
        }
    }
    else {
        matrix_expo(n - 1);
        multiply(big_res, init);
        REP(i, MX){
            REP(j, MX)big_res[i][j] = mul_res[i][j];
        }
    }
}


LL dp[101], ar[101];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n, x;
    cin >> n >> x;
    REP(i, n){
        LL d; cin >> d;
        ar[d]++;
    }
    dp[0] = 1;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= i; j++) dp[i] = (dp[i] + ar[j]*dp[i - j]) % mod;
    }
    for(int i = 100; i >= 1; i--){
        init[1][i] = init[0][i] = ar[i];
    }
    init[0][0] = 1;
    for(int i = 2; i <= 100; i++){
        init[i][i - 1] = 1;
    }
    LL sum = 0;
    if(x <= 100){
        for(int i = 0; i <= x; i++) sum = (sum + dp[i]) % mod;
        cout << sum << endl;
    } else {
        matrix_expo(x - 100);
        for(int i = 0; i <= 100; i++) sum = (sum + dp[i]) % mod;
        sum = (sum * big_res[0][0]) % mod;
        for(int i = 0; i <= 100; i++){
            sum = (sum + dp[100 - i]*big_res[0][i+1]) % mod;
        }
        cout << sum << endl;
    }
}
/*
266079
*/