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

LL dp[2001][2001];
LL go(int c, int v){
    if(v > c) return 0;
    if(c == 0) return 1;
    LL &ret = dp[c][v];
    if(ret != -1 )return ret;
    ret = 0;
    ret = (ret + go(c - 1, v + 1)) % mod;
    if(v > 0) ret = (ret + go(c - 1, v - 1)) % mod;

    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; int n, m; cin >> n >> m >> s;
    int mn = 0, tot = 0;
    REP(i, s.size()){
        if(s[i] == '(') tot++;
        else tot--;
        mn = min(mn, tot);
    }

    memset(dp, -1, sizeof dp);
    n -= m;
    LL res = 0;
    for(int i = 0; i <= n; i++){
        for(int j = -mn; j <= n; j++){
            res = (res + go(i, j) * go(n-i, j+tot)) % mod;
        }
    }

    cout << res << endl;
}