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

vector < int > vc[100001];
int ar[100001], sum[100001];
void dfs(int c){
    sum[c] = ar[c];
    REP(i, vc[c].size()){
        dfs(vc[c][i]);
        sum[c] += sum[ vc[c][i] ];
    }
}
LL dp[100001][2];
LL go(int c, int p){
    if(dp[c][p] != -1) return dp[c][p];
    dp[c][p] = 1;
    if(ar[c] == 1 || p == 1){
        REP(i, vc[c].size()){
            if(ar[vc[c][i]] == 1) dp[c][p] = (dp[c][p] * go(vc[c][i], 0)) % mod;
            else {
                if(sum[vc[c][i]] > 0) dp[c][p] = (dp[c][p] * (go(vc[c][i], 1) + go(vc[c][i], 0))) % mod;
                else dp[c][p] = (dp[c][p] * go(vc[c][i], 1)) % mod;
            }
        }
        return dp[c][p];
    }
    LL tmp = 1.0;
    dp[c][p] = 0;
    REP(i, vc[c].size()) {
        if(ar[vc[c][i]] == 1) tmp = (tmp * go(vc[c][i], 0)) % mod;
        else {
            if(sum[vc[c][i]] > 0) tmp = (tmp * (go(vc[c][i], 1) + go(vc[c][i], 0))) % mod;
            else tmp = (tmp * go(vc[c][i], 1)) % mod;
        }
    }
    REP(i, vc[c].size()) {
        if(sum[vc[c][i]] > 0) {
            LL tp;
            if(ar[vc[c][i]] == 0) tp = (go(vc[c][i], 0) + go(vc[c][i], 1)) % mod;
            else tp = go(vc[c][i], 0);
            tp = (tmp * modinverse(tp, mod)) % mod;
            tp = (tp * go(vc[c][i], 0));
            dp[c][p] = (dp[c][p] + tp) % mod;
        }
    }
    return dp[c][p];
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z;
    cin >> a;
    FOR(i, 1, a){
        cin >> b;
        vc[b].pb(i);
    }
    REP(i, a) cin >> ar[i];
    dfs(0);
    memset(dp, -1, sizeof dp);
    cout << go(0, 0) << endl;
}