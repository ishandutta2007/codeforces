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
vector < pair < LL, LL > > res;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL x; cin >> x;
    for(LL i = 1; i <= 2000000; i++){
        LL a = i*i;
        LL b = i*(i-1) / 2ll;
        LL c = i*(i-1);
        LL v = 6;
        if(c % 2 == 0){
            c /= 2;
            v /= 2;
        }
        if(c % 3 == 0){
            c /= 3;
            v /= 3;
        }
        c *= 2ll*i - 1;
        c /= v;
        LL p = x - c;
        p += b * i;
        LL d = a - b;
        if(p % d == 0){
            p /= d;
            if(p < i) break;
            res.pb(mp(i, p));
            if(i != p) res.pb(mp(p, i));
        }

    }

    vsort(res);
    cout << res.size() << endl;
    REP(i, res.size()) {
        cout << res[i].xx << " " << res[i].yy << endl;
    }
}
/*
nm -0n -0m + 0
nm - n - m + 1
nm -2n -2m + 4
nm -3n -3m + 9

nnm - (n+m)*(n*(n-1)/2) + n*(n+1)*(2n+1)/6
-n*n +
*/