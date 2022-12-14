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
#define ALL(A)     A.begin(), A.end()
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

LL fact[100010], inv[100010], ar[100010];
LL ncr(LL n, LL r){
    if(n < r) return 0;
    LL ret = (((fact[n] * inv[r])%mod) * inv[n - r]) % mod;
    return ret;
}
LL go(int l, int r){
    if(l > r) return 1;
    int tl = l, tr = r;
    while(ar[tl] == 0 && tl <= r) tl++;
    while(ar[tr] == 0 && tr >= l) tr--;
    if(tl > tr) return bigmod(2ll, (LL)r - l, mod);
    if(tl == tr){
        if(ar[tl] == 1){
            return ncr(r - l, tl - l);
        }
        LL ret = 0;
        if(tl + ar[tl] - 1 <= r){
            ret = (ret + ncr(r - l + 1 - ar[tl], tl - l) * bigmod(2ll, ar[tl]-2, mod)) % mod;
        }
        if(tl - ar[tl] + 1 >= l){
            ret = (ret + ncr(r - l + 1 - ar[tl], r - tl) * bigmod(2ll, ar[tl]-2, mod)) % mod;
        }
        return ret;
    }
    LL ret = 0;
    if(ar[tl] > ar[tr]){
        if(tl + ar[tl] - 1 < tr) return 0;
        ret = (ret + go(tl + 1, tl + ar[tl] - 1) * ncr(r - l + 1 - ar[tl], tl - l)) % mod;
    } else {
        if(tr - ar[tr] + 1 > tl) return 0;
        ret = (ret + go(tr - ar[tr] + 1, tr - 1) * ncr(r - l + 1 - ar[tr], r - tr)) % mod;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    fact[0] = 1;
    FOR(i, 1, 100010) fact[i] = (fact[i - 1] * i) % mod;
    REP(i, 100010) inv[i] = modinverse(fact[i], mod);
    cin >> a;
    FOR(i, 1, a + 1){
        cin >> ar[i];
    }
    cout << go(1, a) << endl;
}