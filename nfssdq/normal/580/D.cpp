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

LL dp[1<<18][20];
LL ar[19][19], ar1[19];
int n, m;
LL go(int bp, int c){
    if(__builtin_popcount(bp) == m) return 0;
    LL &ret = dp[bp][c];
    if(ret != -1) return ret;
    ret = 0;

    REP(i, n){
        if(bp & 1<<i) continue;
        LL p = ar1[i] + ar[i][c];

        ret = max(ret, p + go(bp | 1<<i, i));
    }

    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof dp);
    int k; cin >> n >> m >> k;
    REP(i, n) cin >> ar1[i];
    REP(i, k){
        int x, y, c; cin >> x >> y >> c;
        ar[y-1][x-1] = c;
    }
    cout << go(0, 18) << endl;
}