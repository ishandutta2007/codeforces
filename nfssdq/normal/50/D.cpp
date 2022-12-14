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

double dp[101][101], dis[101];
pair < double, double > pp[101], P;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b >> c;
    double eta = (double)c / 1000.0;
    cin >> P.xx >> P.yy;
    FOR(i, 1, a + 1) cin >> pp[i].xx >> pp[i].yy;
    double lo = 0.0, hi = 10000;
    REP(k, 100){
        double mid = (lo + hi) / 2.0;
        FOR(i, 1, a + 1){
            dis[i] = hypot(pp[i].xx - P.xx, pp[i].yy - P.yy);
            if(dis[i] <= mid) dis[i] = 1.0;
            else dis[i] = exp(1.0 - ((dis[i]*dis[i])/(mid*mid)));
        }
        set0(dp); dp[0][0] = 1.0;
        double p = 0.0;
        for(int i = 1; i <= a; i++){
            dp[i][0] = (1.0 - dis[i]) * dp[i - 1][0];
            for(int j = 1; j <= a; j++){
                dp[i][j] = dis[i] * dp[i - 1][j - 1];
                dp[i][j] += (1.0 - dis[i]) * dp[i - 1][j];
            }
        }
        for(int i = b; i <= a; i++) p += dp[a][i];
        p = 1.0 - p;
        if(p > eta) lo = mid;
        else hi = mid;
    }
    cout << fixed << setprecision(8) << lo << endl;
}
/*
2
1 500
0 0
1 0
0 1
*/