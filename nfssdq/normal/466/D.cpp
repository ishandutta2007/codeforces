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

LL dp[2001][2001], ar[2001], n, H;
LL go(int c, int p){
    if(c == n){
        if(p <= 1) return 1;
        return 0;
    }
    LL &ret = dp[c][p];
    if(ret != -1) return ret;
    ret = 0;
    if(ar[c]+p > H + 1) return ret;
    if(ar[c]+p == H+1 && p == 0) return ret;
    if(ar[c]+p == H+1 && p){
        return ret = (p*go(c + 1, p - 1)) % mod;
    }
    if(ar[c]+p == H){
        ret = go(c + 1, p);
        if(p > 0) ret = (ret + p*go(c + 1, p)) % mod;
        return ret;
    }
    if(ar[c]+p < H-1) return ret = 0;
    if(ar[c]+p == H-1) return ret = go(c + 1, p + 1);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> n >> H;
    REP(i, n) cin >> ar[i];
    memset(dp, -1, sizeof dp);
    cout << go(0, 0) << endl;
}