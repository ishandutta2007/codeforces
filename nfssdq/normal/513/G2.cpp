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


double dp[202][33][33];
int ar[33];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, K; cin >> n >> K;
    FOR(i, 1, n + 1) cin >> ar[i];
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++) dp[0][i][j] = 1;
    }
    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= n; j++){
            for(int k = j+1; k <= n; k++){
                if(j == k) continue;
                for(int l = 1; l <= n; l++){
                    for(int m = l; m <= n; m++){
                        if(l <= j && m >= k){
                            dp[i][j][k] += 1.0 - dp[i - 1][m - k + l][m - j + l];
                        } else if(l <= j && m < k && m >= j){
                            dp[i][j][k] += dp[i - 1][m - j + l][k];
                        } else if(l > j && m >= k && l <= k){
                            dp[i][j][k] += dp[i - 1][j][m - k + l];
                        } else dp[i][j][k] += dp[i - 1][j][k];
                    }
                }
                dp[i][j][k] /= (double)(n*(n+1)/2);
            }
        }
    }
    double res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++) {
            if(ar[i] > ar[j]) res += dp[K][i][j];
            else res += 1.0 - dp[K][i][j];
        }
    }
    cout << fixed << setprecision(12) << res << endl;
}