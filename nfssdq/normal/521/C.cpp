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

string s;
LL fact[100001], inv[100001], nck[100001];
LL ncr(LL n, LL r){
    if(n < r) return 0;
    LL ret = (fact[n] * inv[r]) % mod;
    return ret = (ret * inv[n - r]) % mod;
}
LL val[100001], p10[100001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    fact[0] = 1;
    for(LL i = 1; i <= 100000; i++) fact[i] = (fact[i - 1] * i) % mod;
    REP(i, 100001) inv[i] = modinverse(fact[i], mod);

    LL n, k; cin >> n >> k;
    cin >> s;

    if(k == 0){
        LL v = 0;
        REP(i, s.size()) v = (v * 10ll + s[i] - '0') % mod;
        cout << v << endl;
        return 0;
    }

    for(int i = n-1; i >= k-1; i--) nck[i] = ncr(i, k-1);

    p10[0] = 1;
    FOR(i, 1, n + 1) p10[i] = (p10[i - 1] * 10ll) % mod;

    for(int i = 1; i <= n; i++){
        int nv = n - i - 1;
        if(nv < k-1) val[i] = 0;
        else val[i] =  (p10[i - 1] * nck[nv]) % mod;

        val[i] = (val[i - 1] + val[i]) % mod;
    }

    LL res = 0;
    REP(i, s.size()){
        int p = s.size() - 1 - i;
        res = (res + val[p] * (LL)(s[i] - '0')) % mod;

        LL t = ncr(n - 1 - p, k);
        t = (t * p10[p]) % mod;
        res = (res + t*(LL)(s[i] - '0')) % mod;

    }

    cout << res << endl;

}
/*
n-1Ck
p
v*n-2Ck-1
v*10*n-3Ck-1
*/