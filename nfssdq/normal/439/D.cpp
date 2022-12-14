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

pair < LL, LL > A[100001], B[100001];
LL ar[220001], res[220001], res2[222222];
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b;
    REP(i, a) cin >> A[i].xx;
    REP(i, b) cin >> B[i].xx;
    REP(i, a) ar[d++] = A[i].xx;
    REP(i, b) ar[d++] = B[i].xx;

    sort(A, A + a);
    sort(B, B + b);
    sort(ar, ar + d);
    REP(i, a) A[i].yy = 1;
    REP(i, b) B[i].yy = 1;

    reverse(B, B + b);

    f = linf;

    x = 0;

    for(int i = d - 1; i >= 0; i--){
        res[i] += res[i + 1];
        while(x < b - 1 && B[x + 1].xx >= ar[i]){
            res[i] += (B[x].xx - B[x + 1].xx) * B[x].yy;
            B[x + 1].yy += B[x].yy;
            x++;
        }
        if(B[x].xx >= ar[i]){
            res[i] += (B[x].xx - ar[i]) * B[x].yy;
            B[x].xx = ar[i];
        }
    }

    x = 0;

    for(int i = 0; i < d; i++){
        if(i != 0) res2[i] += res2[i - 1];
        while(x < a - 1 && A[x + 1].xx <= ar[i]){
            res2[i] += (A[x + 1].xx - A[x].xx) * A[x].yy;
            A[x + 1].yy += A[x].yy;
            x++;
        }
        if(ar[i] >= A[x].xx){
            res2[i] += (ar[i] - A[x].xx) * A[x].yy;
            A[x].xx = ar[i];
        }
    }

    REP(i, d) f = min(f, res[i] + res2[i]);
    cout << f << endl;
}