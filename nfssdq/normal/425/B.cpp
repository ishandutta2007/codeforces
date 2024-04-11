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
#define linf       (1<<60)-1
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

int ar[101][101];
LL val[101][4], var[101][4];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b >> c;
    FOR(i, 1, a + 1){
        FOR(j, 1, b + 1) cin >> ar[i][j];
        for(int j = 1; j <= min(b, 10ll); j++)
            if(ar[i][j] == 1)
                val[i][0] |= 1ll<<(j - 1);
    }
    for(int i = 1; i <= b; i++){
        for(int j = 1; j <= min(a, 10ll); j++)
            if(ar[j][i] == 1)
                var[i][0] |= 1ll<<(j - 1);
    }
    e = 11;
    if(b <= c){
        for(int i = 0; i < (1ll<<b); i++){
            d = (1ll<<b) - 1;
            f = 0;
            for(int j = 1; j <= a; j++){
                g = __builtin_popcount(val[j][0] ^ i);
                h = __builtin_popcount(val[j][0] ^ i ^ d);
                f += min(g, h);
            }
            e = min(e, f);
        }
    } else if(a <= c){
        for(int i = 0; i < (1ll<<a); i++){
            d = (1ll<<a) - 1;
            f = 0;
            for(int j = 1; j <= b; j++){
                g = __builtin_popcount(var[j][0] ^ i);
                h = __builtin_popcount(var[j][0] ^ i ^ d);
                f += min(g, h);
            }
            e = min(e, f);
        }
    } else {
        for(int i = 1; i <= a; i++){
            f = 0;
            for(int j = 1; j <= a; j++){
                g = h = 0;
                for(int k = 1; k <= b; k++){
                    g += ar[i][k] ^ ar[j][k];
                    h += ar[i][k] ^ ar[j][k] ^ 1;
                }
                f += min(g, h);
            }
        e = min(e, f);
        }
    }
    if(e <= c) cout << e << endl;
    else cout << -1 << endl;

}