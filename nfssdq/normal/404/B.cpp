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



template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

pair < double, double > add(double x, double t, double a){
    if(x <= a) return mp(x, 0);
    x -= a;
    if(x <= a) return mp(a, x);
    x -= a;
    if(x <= a)return mp(a - x, a);
    x -= a;
    if(x <= a) return mp(0.0, a - x);
}

main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,e,f = 0,g,h = 0,x,y,z;
    double p, d;
    cin >> p >> d >> c;
    double sx = 0.0, sy = 0.0;
    for(int i = 1; i <= c; i++){
        sx += d;
        sy = floor(sx / (4.0 * p));
        sx -= sy * 4.0 * p;
        pair < double, double > pp = add(sx, d, p);
        printf("%.8lf %.8lf\n", pp.xx, pp.yy);
    }
}