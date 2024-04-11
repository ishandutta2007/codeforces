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

LL fact[300001], inv[300001];
pair < LL, LL > pp[2002];
LL dp[2001];
LL calc(LL x1, LL y1, LL x2, LL y2){
    LL ret = (fact[x2-x1 + y2-y1] * inv[x2-x1]) % mod;
    ret = (ret * inv[y2-y1]) % mod;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fact[0] = 1;
    for(LL i = 1; i <= 300000; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
    REP(i, 300001) inv[i] = modinverse(fact[i], mod);

    LL h, w, n; cin >> h >> w >> n;
    REP(i, n) cin >> pp[i].xx >> pp[i].yy;
    pp[n++] = mp(h, w);
    sort(pp, pp + n);

    REP(i, n){
        dp[i] = (dp[i] + calc(1, 1, pp[i].xx, pp[i].yy)) % mod;
    }
    REP(i, n){
        for(int j = i + 1; j < n; j++){
            if(pp[j].yy < pp[i].yy) continue;
            dp[j] = (dp[j] + mod - (dp[i]*calc(pp[i].xx, pp[i].yy, pp[j].xx, pp[j].yy)) % mod) % mod;
        }
    }

    cout << dp[n-1] << endl;
}