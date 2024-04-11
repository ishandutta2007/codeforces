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

LL dp[3001][3001];
char pp[3001][3001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b;
    REP(i, a) cin >> pp[i];
    LL res[2][2];
    set0(dp);
    for(int i = 1; i < b; i++){
        if(pp[0][i] == '#')break;
        dp[0][i] = 1;
    }
    for(int i = 1; i < a; i++){
        for(int j = 1; j < b; j++){
            if(pp[i][j] == '#') continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    res[0][0] = dp[a - 2][b - 1], res[0][1] = dp[a - 1][b - 2];
    set0(dp);
    for(int i = 0; i < b; i++){
        if(pp[1][i] == '#')break;
        dp[1][i] = 1;
    }
    for(int i = 2; i < a; i++){
        for(int j = 0; j < b; j++){
            if(pp[i][j] == '#') continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    res[1][0] = dp[a - 2][b - 1], res[1][1] = dp[a - 1][b - 2];
    c = (res[0][0] * res[1][1] - res[0][1] * res[1][0]) % mod;
    c = (c + mod) % mod;
    cout << c << endl;
}