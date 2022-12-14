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
LL ar1[100001], ar2[100001];
unsigned LL sum1[100001], sum2[100001];
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,g,h = 0,x,y,z;
    cin >> a >> b;
    FOR(i, 1, a + 1) cin >> ar1[i];
    FOR(i, 1, b + 1) cin >> ar2[i];
    sort(ar1 + 1, ar1 + a + 1);
    sort(ar2 + 1, ar2 + b + 1);
    for(int i = 1; i <= a; i++) sum1[i] = ar1[i] + sum1[i - 1];
    for(int i = 1; i <= b; i++) sum2[i] = ar2[i] + sum2[i - 1];
    unsigned long long f = (1<<64) - 1;
    for(int i = a - 1; i >= 0; i--){
        f = min(f, (sum2[b])*(unsigned LL)(a - i) + sum1[i]);
    }
    for(int i = b - 1; i >= 0; i--){
        f = min(f, (sum1[a])*(unsigned LL)(b - i) + sum2[i]);
    }
    cout << f << endl;

}