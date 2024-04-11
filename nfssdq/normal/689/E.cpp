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

pair < LL, LL > pp[500001];
LL fact[200001], inv[200001];
LL ncr(int n, int r){
    if(n < r) return 0;
    LL res = (fact[n] * inv[r]) % mod;
    return (res * inv[n-r]) % mod;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fact[0] = 1;
    for(LL i = 1; i <= 200000; i++) fact[i] = (fact[i-1] * i) % mod;
    REP(i, 200001) inv[i] = modinverse(fact[i], mod);

    int n, k; cin >> n >> k;
    int cnt = 0;
    REP(i, n){
        int x, y; cin >> x >> y;
        pp[cnt++] = mp(x, 1);
        pp[cnt++] = mp(y+1, -1);
    }
    sort(pp, pp + cnt);

    LL res = 0, tot = 1;
    FOR(i, 1, cnt){
        res = (res + ncr(tot, k) * (pp[i].xx - pp[i-1].xx)) % mod;
        tot += pp[i].yy;
    }
    cout << res << endl;
}