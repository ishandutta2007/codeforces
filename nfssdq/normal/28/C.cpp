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

double ncr[55][55], dp[55][55][55], dp2[55][55][55];
int vis[55][55][55], n, ar[55];
double go(int c, int s, int q){
    if(c == n){
        if(s > 0) return 0.0;
        dp2[c][s][q] = 1;
        dp[c][s][q] = q;
        return q;
    }
    if(vis[c][s][q]) return dp[c][s][q];
    vis[c][s][q] = 1;
    for(int i = 0; i <= s; i++){
        int nq = max(q, (i + ar[c] - 1)/ar[c]);
        if(c == n - 1 && i != s) continue;
        dp[c][s][q] += ncr[s][i] * go(c + 1, s - i, nq);
        dp2[c][s][q] += ncr[s][i] * dp2[c+1][s-i][nq];
    }
    return dp[c][s][q];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    ncr[0][0] = 1;
    FOR(i, 1, 55){
        ncr[i][0] = 1;
        FOR(j, 1, i + 1) ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
    }
    cin >> a >> n;
    REP(i, n) cin >> ar[i];
    go(0, a, 0);
    cout << fixed << setprecision(13) << dp[0][a][0]/dp2[0][a][0] << endl;
}