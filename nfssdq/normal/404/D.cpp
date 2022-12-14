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

LL dp[1000001][2][2], n;
char pp[1000001];
LL go(int c, int l, int r){
    if(c == n) return 1;
    LL &ret = dp[c][l][r];
    if(ret != -1)return ret;
    ret = 0;
    if(pp[c] == '?'){
        if(l == 0 && (c == n - 1 || pp[c + 1] == '?' || pp[c + 1] == '0' || pp[c + 1] == '1'))
            ret = (ret + go(c + 1, 0, 0)) % mod;
        if(l == 1 && (c == n - 1 || pp[c + 1] == '?' || pp[c + 1] == '0' || pp[c + 1] == '1'))
            ret = (ret + go(c + 1, 0, 0)) % mod;
        if(l == 0 && c < n - 1 && (pp[c + 1] == '?' || pp[c + 1] == '*'))
            ret = (ret + go(c + 2, 1, 1)) % mod;
        if(l == 1 && c < n - 1 && (pp[c + 1] == '?' || pp[c + 1] == '*'))
            ret = (ret + go(c + 2, 1, 1)) % mod;
        if(r == 1) ret = (ret + go(c + 1, 1, 1)) % mod;
    } else if(pp[c] == '0'){
        if(l == 1)return ret;
        if(c == n - 1 || pp[c + 1] == '?' || pp[c + 1] == '0' || pp[c + 1] == '1')
           ret = (ret + go(c + 1, 0, 0)) % mod;
    } else if(pp[c] == '1'){
        if(l == 1 && (c == n - 1 || pp[c + 1] == '?' || pp[c + 1] == '0' || pp[c + 1] == '1'))
            ret = (ret + go(c + 1, 0, 0)) % mod;
        if(l == 0 && c < n - 1 && (pp[c + 1] == '?' || pp[c + 1] == '*'))
            ret = (ret + go(c + 2, 1, 1)) % mod;
    } else if(pp[c] == '2'){
        if(l == 0)return ret;
        if(c < n - 1 && (pp[c + 1] == '?' || pp[c + 1] == '*'))
            ret = (ret + go(c + 2, 1, 1)) % mod;
    } else if(pp[c] == '*'){
        if(r == 0)return ret;
        ret = (ret + go(c + 1, 1, 1)) % mod;
    }
    return ret;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> pp;
    n = strlen(pp);
    memset(dp, -1, sizeof dp);
    cout << go(0, 0, 1) << endl;
}