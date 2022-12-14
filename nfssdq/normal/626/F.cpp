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

int dp[201][201][1001], ar[201], n;
LL go(int c, int t, int k){
    if(c > n){
        if(t == 0 && k >= 0) return 1;
        return 0;
    }
    int &rr = dp[c][t][k];
    if(rr != -1) return rr;
    rr = 0;
    LL ret = 0;

    k -= (ar[c] - ar[c-1]) * t;
    if(k < 0) return rr;
    ret = (ret + go(c + 1, t, k) * (LL)(t + 1)) % mod;

    ret = (ret + go(c + 1, t + 1, k)) % mod;
    if(t)ret = (ret + (LL)t * go(c + 1, t - 1, k)) % mod;

    return rr = ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k; cin >> n >> k;
    FOR(i, 1, n+1) cin >> ar[i];
    sort(ar + 1, ar + n + 1);

    memset(dp, -1, sizeof dp);
    cout << go(1, 0, k) << endl;
}