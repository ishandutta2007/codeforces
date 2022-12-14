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
#define PI         2.0*acos(0.0)
#define linf       (1<<60)-1
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

LL dp[5][1011][1011], ar[1011][1011];


main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b;
    FOR(i, 1, a + 1){
        FOR(j, 1, b + 1) cin >> ar[i][j];
    }
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            dp[0][i][j] = ar[i][j] + max(dp[0][i - 1][j], dp[0][i][j - 1]);
        }
    }
    for(int i = 1; i <= a; i++){
        for(int j = b; j >= 1; j--){
            dp[1][i][j] = ar[i][j] + max(dp[1][i - 1][j], dp[1][i][j + 1]);
        }
    }
    for(int i = a; i >= 1; i--){
        for(int j = 1; j <= b; j++){
            dp[2][i][j] = ar[i][j] + max(dp[2][i + 1][j], dp[2][i][j - 1]);
        }
    }
    for(int i = a; i >= 1; i--){
        for(int j = b; j >= 1; j--){
            dp[3][i][j] = ar[i][j] + max(dp[3][i + 1][j], dp[3][i][j + 1]);
        }
    }
    for(int i = 2; i < a; i++){
        for(int j = 2; j < b; j++){
            e = max(e, dp[0][i][j - 1] + dp[3][i][j + 1] + dp[1][i - 1][j] + dp[2][i + 1][j]);
            e = max(e, dp[0][i - 1][j] + dp[3][i + 1][j] + dp[1][i][j + 1] + dp[2][i][j - 1]);
        }
    }
    cout << e << endl;
}