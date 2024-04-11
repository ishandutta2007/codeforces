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

double dp[101][101][101][3];
int vis[101][101][101][3];
double go(int r, int s, int p, int f){
    if(r+s+p == 0) return 0;
    if(f == 0 && s+p == 0) return 1.0;
    if(f == 1 && r+p == 0) return 1.0;
    if(f == 2 && r+s == 0) return 1.0;
    if(r+s+p == 1) return 0.0;
    if(f == 0 && r == 0) return 0.0;
    if(f == 1 && s == 0) return 0.0;
    if(f == 2 && p == 0) return 0.0;
    if(vis[r][s][p][f]) return dp[r][s][p][f];
    vis[r][s][p][f] = 1;
    double &ret = dp[r][s][p][f];
    ret = 0;

    double down = (r+s+p) * (r+s+p-1) / 2;
    double v = (double)(r*(r-1) + s*(s-1) + p*(p-1)) / (2.0*down);// later

    if(r && s)ret += (double)(r*s) * go(r, s-1, p, f);
    if(r && p)ret += (double)(r*p) * go(r-1, s, p, f);
    if(s && p)ret += (double)(s*p) * go(r, s, p-1, f);
    ret /= down;

    ret /= (1.0 - v);

    return ret;

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r, s, p; cin >> r >> s >> p;
    cout << fixed << setprecision(11) << go(r,s,p,0) << " " << go(r,s,p,1) << " " << go(r,s,p,2) << endl;
}