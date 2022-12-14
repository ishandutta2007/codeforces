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

vector < int > divisor[100001];
LL ar[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    for(int i = 1; i <= 100000; i++){
        for(int j = i; j <= 100000; j += i) {
            divisor[j].pb(i);
        }
        divisor[i].pb(100001);
    }
    cin >> a;
    REP(i, a) cin >> ar[i];
    sort(ar, ar + a);
    for(int i = 100000; i > 0; i--){
        f = 1;
        REP(j, divisor[i].size() - 1){
            b = divisor[i][j], c = divisor[i][j + 1];
            g = lower_bound(ar, ar + a, b) - ar;
            h = lower_bound(ar, ar + a, c) - ar;
            h -= g;
//            if(i == 2) cout << h << " " << b << endl;
            if(b == i && h == 0) f = 0;
            else if(b != i)f = (f * bigmod((LL)j+1, h, mod)) % mod;
            else {
                e = bigmod((LL)j+1, h, mod);
                e = (e - bigmod((LL)j, h, mod) + mod) % mod;
                f = (f * e) % mod;
            }
        }
        d = (d + f) % mod;
    }
    cout << d << endl;
}
/*
1234
1111
1112
1121
1122
1211
1212
1221
1222
*/