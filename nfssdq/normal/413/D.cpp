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

LL dp[2001][(1<<11) + 3], n;
LL ar[2001], cnt[2001], k;
LL go(int c, int bp){
    if(bp >= 1<<k) return bigmod(2ll, (LL)(cnt[n] - cnt[c - 1]), mod);
    if(c > n) return 0;
    LL &ret = dp[c][bp];
    if(ret != -1) return ret;
    ret = 0;
    if(ar[c] == 2 || ar[c] == 0){
        ret = (ret + go(c + 1, bp + 2)) % mod;
    }
    if(ar[c] == 4 || ar[c] == 0){
        if(bp % 4 == 2) bp = 0;
        ret = (ret + go(c + 1, bp + 4)) % mod;
    }
    return ret;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b;
    FOR(i, 1, a + 1) {
        cin >> ar[i];
        cnt[i] = cnt[i - 1] + (ar[i] == 0);
    }
    n = a; k = b;
    memset(dp, -1, sizeof dp);
    cout << go(1, 0) << endl;
}