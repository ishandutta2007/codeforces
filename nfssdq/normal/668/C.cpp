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


long double mx[100001], mn[100001], A[100001], B[100001];

int main() {
//    freopen("hack.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    FOR(i, 1, n+1) cin >> mx[i];
    FOR(i, 1, n+1) cin >> mn[i];
    long double p1 = 0, p2 = 0;
    FOR(i, 1, n+1){
        long double v = (p1 - p2 - mx[i] - mn[i]);
        v *= v;
        v -= 4.0 * (mx[i] - p1*mx[i] - p1*mn[i]);
//        cout << v << endl;
        if(v < 0) v = 0.0;
        v = sqrt(v);

        long double t = -(p1 - p2 - mx[i] - mn[i]);

//        if(p1 > p2)v = t + v;
//        else v = t - v;
        v = t + v;

        v /= 2.0;


        B[i] = v;
        A[i] = mx[i] + mn[i] - v;
        p2 += A[i];
        p1 += B[i];

    }

    FOR(i, 1, n+1) cout << fixed << setprecision(10) << A[i] << " ";
    cout << endl;
    FOR(i, 1, n+1) cout << fixed << setprecision(10) << B[i] << " ";
    cout << endl;
}
/*
a*p1 + b*p2 + ab = x
a*(1-p1) + b*(1-p2) - ab = y
a + b = x+y

a = x+y-b
(x+y-b)*p1 + b*p2 + (x+y-b)*b = x
b*b + b*(p1-p2-x-y) - p1x-p1y+x = 0;

*/