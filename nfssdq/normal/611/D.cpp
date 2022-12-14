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



int dp1[5001][5001];
int dp[5001][5001], sum[5001][5001];
int on[5001][5001];
string s;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n >> s;

    for(int i = n-1; i >= 0; i--){
        for(int j = i+1; j <= n; j++){
            if(j == n){
                dp1[i][j] = -n;
            } else if(s[j] == s[i]){
                dp1[i][j] = dp1[i+1][j+1];
            } else if(s[j] > s[i]){
                dp1[i][j] = j;
            } else dp1[i][j] = -j;
        }
    }

    REP(i, n){
        for(int j = i; j < n; j++){
            int len = j+(j-i+1);
            if(len >= n) break;
            if(dp1[i][j+1] >= 0 && dp1[i][j+1] <= len) on[i][j] = 1;
        }
    }


    for(int i = n-1; i >= 0; i--){
        if(s[i] == '0') continue;
        dp[i][n-1] = 1;
        for(int j = n-2; j >= i; j--){
            int len = j+j-i+1;
            if(len >= n) continue;
            if(on[i][j]) {
                dp[i][j] = (dp[i][j] + dp[j+1][len]) % mod;
            }
            if(s[j+1] == '0') continue;
            dp[i][j] = (dp[i][j] + sum[j+1][len+1]) % mod;
        }

        for(int j = n-1; j >= i; j--){
            sum[i][j] = (dp[i][j] + sum[i][j+1]) % mod;
        }
    }

    cout << sum[0][0] << endl;

}