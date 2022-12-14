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

vector < LL > divisor[100001];
LL mobius[100001], isp[100001];
LL fact[200001], inverse[200001];
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    divisor[1].pb(1);
    REP(i, 100001) mobius[i] = 1;
    for(int i = 2; i <= 100000; i++){
        divisor[i].pb(1);
        if(isp[i] == 0){
            for(int j = i * 2; j <= 100000; j += i){
                isp[j] = 1;
                if(j % (i*i) == 0) mobius[j] = 0;
                mobius[j] *= -1;
            }
            mobius[i] *= -1;
        }
        for(int j = i; j <= 100000; j += i) divisor[j].pb(i);
    }
    fact[0] = 1;
    for(LL i = 1; i <= 200000; i++) fact[i] = (fact[i - 1] * i) % mod;
    REP(i, 200001) inverse[i] = modinverse(fact[i], mod);
    cin >> a;
    REP(i, a){
        cin >> b >> c;
        f = 0;
        REP(j, divisor[b].size()){
            d = b / divisor[b][j];
            if(d < c) continue;
            if(d == c) {
                f = (f + mobius[divisor[b][j]] + mod) % mod;
                continue;
            }
            d -= c;
            e = (fact[d + c - 1] * inverse[c - 1]) % mod;
            e = (e * inverse[d]) % mod;
            e *= mobius[divisor[b][j]];
            if(e < 0) e += mod;
            f = (f + e) % mod;
        }
        cout << f << endl;
    }

}