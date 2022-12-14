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


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long double a,b,c,d; cin >> a >> b >> d >> c;
    long double lo = 0.0, hi = 1e10;
    REP(i, 5000){
        long double mid = (lo + hi) / 2.0;
//        long double mid = 0.2;
        long double lx = min((a - mid)*(c-mid), min((a-mid)*(c+mid), min((a+mid)*(c-mid), (a+mid)*(c+mid))));
        long double ly = max((a - mid)*(c-mid), max((a-mid)*(c+mid), max((a+mid)*(c-mid), (a+mid)*(c+mid))));
        long double rx = min((b - mid)*(d-mid), min((b-mid)*(d+mid), min((b+mid)*(d-mid), (b+mid)*(d+mid))));
        long double ry = max((b - mid)*(d-mid), max((b-mid)*(d+mid), max((b+mid)*(d-mid), (b+mid)*(d+mid))));
        int fl = 0;
//        cout << lx << " " << ly << " " << rx << " " << ry << endl;
        if(ly < rx - 1e-20) fl = 1;
        if(lx > ry + 1e-20) fl = 1;
        if(fl == 0) hi = mid;
        else lo = mid;
    }
    cout << fixed << setprecision(14) << lo << endl;


}