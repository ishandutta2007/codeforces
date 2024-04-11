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
#define ALL(A)     A.begin(), A.end()
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



string S, P;
int dp[2001][2002], dp1[2001][2011], len[2001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> S >> P;
    a = S.size(), b = P.size();
    REP(i, b) dp1[a][i] = 1000000;
    for(int i = a - 1; i >= 0; i--){
        for(int j = 0; j < b; j++){
            if(S[i] == P[j]){
                dp1[i][j] = dp1[i + 1][j + 1];
            } else dp1[i][j] = 1 + dp1[i + 1][j];
        }
        len[i] = dp1[i][0];
    }
    for(int i = 1; i <= a; i++) dp[a][i] = -100000;
    for(int i = a - 1; i >= 0; i--){
        for(int j = 0; j <= a; j++){
            dp[i][j] = -100000;
            if(j > (a - i)) {
                continue;
            }
            dp[i][j] = max(dp[i][j], dp[i + 1][j]);
            if(j > 0) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1]);
            if(len[i] <= j && (i+len[i]+b) <= a) dp[i][j] = max(dp[i][j], 1 + dp[i + len[i] + b][j - len[i]]);
        }
    }
    for(int i = 0; i <= a; i++) cout << dp[0][i] << " " ;
    cout << endl;
}