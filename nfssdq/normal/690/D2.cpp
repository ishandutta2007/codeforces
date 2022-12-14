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


LL fact[1000001], inv[1000001];
LL ncr(int n, int r, LL md){
    if(n < r) return 0;
    LL ret = (fact[n] * inv[r]) % md;
    return (ret * inv[n-r]) % md;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n, m; cin >> n >> m;
    LL res = 0;
    LL md = 1000003;

    fact[0] = 1;
    for(LL i = 1; i <= 1000000; i++) fact[i] = (fact[i-1] * i) % md;
    REP(i, 1000001) inv[i] = modinverse(fact[i], md);

    if(n == 1){
        cout << m << endl;
        return 0;
    }

    for(LL i = 1; i <= n; i++){
        if(i > n) break;
        res = (res + ncr(i+m-1, i, md)) % md;
    }
    cout << res << endl;

}