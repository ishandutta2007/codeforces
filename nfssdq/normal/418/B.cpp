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
#define FOR(I,A,B) for(LL I = (A); I < (B); ++I)
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

struct data {
    LL k,x,m,f;
    vector < LL > vc;
    data(){
        k = x = m = f = 0;
        vc.clear();
    }
    void in(){
        cin >> x >> k >> m;
        REP(i, m) {
            LL c;
            cin >> c;
            f |= 1<<(c - 1);
        }
    }
};
bool operator<(data a, data b){
    return a.k < b.k;
}
data ar[101];
LL M,B, n;
LL dp[2][(1<<20) + 1];

main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h,x,y,z;
    cin >> a >> M >> B;
    n = a;
    REP(i, a) ar[i].in();
    sort(ar, ar + a);
    g = 1ll<<62;
    for(int i = a - 1; i >= 1; i--) ar[i].k -= ar[i - 1].k;
    for(int i = 0; i < (1<<M) - 1; i++)dp[0][i] = g;
    dp[0][(1<<M) - 1] = 0;
    b = 1; c = 0;
    for(int i = a - 1; i >= 0; i--){
        dp[b][(1<<M) - 1] = 0;
        d = ar[i].k * B;
        e = ar[i].x;
        for(int j = 0; j < (1<<M) - 1; j++){
            dp[b][j] = g;
            if(dp[c][j] < g - d)dp[b][j] = min(dp[b][j], dp[c][j] + d);
            f = j | ar[i].f;
            if(dp[c][f] < g - d - e)dp[b][j] = min(dp[b][j], dp[c][f] + d + e);
        }
        b ^= 1;
        c ^= 1;
    }
    if(dp[c][0] >= g) cout << -1 << endl;
    else cout << dp[c][0] << endl;
}