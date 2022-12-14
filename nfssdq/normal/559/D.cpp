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


typedef long double ld;
pair < ld, ld > pp[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n) cin >> pp[i].xx >> pp[i].yy;

    ld denom = pow(2.0, n) - 1.0 - ((ld)n*(ld)(n-1)/2.0) - (ld)n;
    ld res = 0.0;

    if(n <= 300){
        REP(i, n){
            FOR(j, 1, n){
                ld num = pow(2.0, n - j - 1)-1;
                num /= denom;

                int p = (i + j) % n;
                ld v = pp[i].xx * pp[p].yy - pp[p].xx*pp[i].yy;
                v -= gcd((int)(abs(pp[i].xx-pp[p].xx)+0.1),(int)(abs(pp[i].yy-pp[p].yy)+0.1));
                v /= 2.0;

                res += v * num;
            }
        }
//        res /= 2.0;
        res += 1.0;
    }
    else {
        REP(i, n){
            ld num = 0.5;
            FOR(j, 1, 101){
                num *= 0.5;

                int p = (i + j) % n;
                ld v = pp[i].xx * pp[p].yy - pp[p].xx*pp[i].yy;
                v -= gcd((int)(abs(pp[i].xx-pp[p].xx)+0.1),(int)(abs(pp[i].yy-pp[p].yy)+0.1));
                v /= 2.0;
                res += num * v;
            }
        }
    }
    cout << fixed << setprecision(10) << res << endl;
}