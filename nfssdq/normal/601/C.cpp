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

int ar[101];
long double dp[101][100001], sum[101][100001];
long double ncr[1001][1001];
long double pp[2][100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    REP(i, 1001){
        ncr[i][0] = 1;
        FOR(j, 1, i+1) ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
    }
    int n, m; cin >> n >> m;
    int ss = 0;
    FOR(i, 1, n+1) {
        cin >> ar[i];
        ss += ar[i];
    }

    dp[0][0] = sum[0][0] = 1.0;
    for(int i = 1; i <= 100000; i++) sum[0][i] = 1.0;

    for(int i = 1; i <= n; i++){
        dp[i][0] = 0.0;
        for(int j = i; j <= i*m; j++){
            int l = max(j-m, 0), r = j-1;
            dp[i][j] = sum[i-1][r];
            if(l > 0) dp[i][j] -= sum[i-1][l-1];
            if(j-ar[i] >= 0) {
                dp[i][j] -= dp[i-1][j-ar[i]];
            }
            dp[i][j] /= (long double)(m-1);

            sum[i][j] = sum[i][j-1] + dp[i][j];
        }
        for(int j = i*m+1; j <= 100000; j++) sum[i][j] = sum[i][j-1];
    }

    long double res = 0.0;
    long double P = sum[n][ss-1];
    pp[0][0] = pp[1][0] = 1.0;
    FOR(i, 1, m+1){
        pp[0][i] = (pp[0][i-1] * P);
        pp[1][i] = (pp[1][i-1] * (1.0 - P));
    }
    for(int i = 1; i <= m; i++){
        res += pp[0][i-1] * pp[1][m-i] * ncr[m-1][i-1] * (long double)i;
    }

    cout << fixed << setprecision(12) << res << endl;
}