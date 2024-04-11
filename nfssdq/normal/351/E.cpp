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

LL dp[2001][2001], n, sz[2001], szR[2001];
pair < int, int > pp[2001];
LL go(int c, int p){
    if(c < 0) return 0;
    LL &ret = dp[c][p];
    if(ret != -1) return ret;
    ret = mod;
    if(c < n - 1 && pp[c + 1].xx != pp[c].xx) p = 0;
    ret = min(ret, szR[pp[c].yy ] + p + go(c - 1, p));
    ret = min(ret, sz[ pp[c].yy ] + go(c - 1, p + 1));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a;
    REP(i, a){
        cin >> pp[i].xx;
        pp[i] = mp(abs(pp[i].xx), i);
    }
    REP(i, a){
        REP(j, i) if(pp[j].xx < pp[i].xx) sz[i]++;
    }
    REP(i, a){
        for(int j = i + 1; j < a; j++) if(pp[j].xx < pp[i].xx) szR[i]++;
    }
    sort(pp, pp + a); n = a;
    memset(dp, -1, sizeof dp);
    cout << go(a - 1, 0) << endl;
}