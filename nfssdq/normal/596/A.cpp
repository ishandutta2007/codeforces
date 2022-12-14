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

pair < int, int > pp[5];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n) cin >> pp[i].xx >> pp[i].yy;
    sort(pp, pp + n);

//    if(n == 4){
//        cout << (pp[2].xx - pp[0].xx) * (pp[1].yy - pp[0].yy) << endl;
//    } else if(n == 3){
//        if(pp[0].xx != pp[1].xx){
//            cout << (pp[2].xx - pp[0].xx) * (pp[2].yy - pp[1].yy) << endl;
//        } else {
//            cout << (pp[2].xx - pp[0].xx) * (pp[1].yy - pp[0].yy) << endl;
//        }
//    } else if(n == 2){
//        if(pp[0].xx != pp[1].xx && pp[0].yy != pp[1].yy){
//            cout << (pp[1].xx - pp[0].xx) * (pp[1].yy - pp[0].yy) << endl;
//        } else cout << -1 << endl;
//    } else cout << -1 << endl;

    int dx = 0, dy = 0;
    REP(i, n){
        REP(j, i){
            dx = max(dx, abs(pp[i].xx - pp[j].xx));
            dy = max(dy, abs(pp[i].yy - pp[j].yy));
        }
    }

    if(dx == 0 || dy == 0) cout << -1 << endl;
    else cout << dx * dy << endl;

}