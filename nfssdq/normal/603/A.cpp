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

string s;
int dp[100001][3][2];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n >> s;
    REP(i, n){
        REP(j, 3){
            REP(k, 2){
                dp[i+1][j][k] = 0;
                int v = (s[i]-'0') == k;
                if(j == 0){
                    if(v == 0) {
                        dp[i+1][j][k] = max(dp[i+1][j][k], 1 + dp[i][j][k^1]);
                        dp[i+1][j][k] = max(dp[i+1][j][k], 1 + dp[i][j+1][k^1]);
                    }
                    else {
                        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j+1][k]);
                    }
                } else if(j == 1){
                    if(v) {
                        dp[i+1][j][k] = max(dp[i+1][j][k], 1 + dp[i][j][k^1]);
                        dp[i+1][j][k] = max(dp[i+1][j][k], 1 + dp[i][j+1][k^1]);
                    }
                    else {
                        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j+1][k]);
                    }
                }else {
                    if(v == 0) {
                        dp[i+1][j][k] = max(dp[i+1][j][k], 1 + dp[i][j][k^1]);
                    }
                    else {
                        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                    }
                }
            }
        }
    }

    cout << max(dp[n][0][0], dp[n][0][1]) << endl;
}