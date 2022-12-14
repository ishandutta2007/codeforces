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


LL dp[55][55][2], k1, k2;
LL go(int l, int r, int f){
    LL &ret = dp[l][r][f];
    if(ret != -1) return ret;
    ret = 0;
    if(f == 0){
        for(int i = 1; i <= min((LL)l, k1); i++){
            ret |= go(l - i, r, f^1) ^ 1;
        }
    } else {
        for(int i = 1; i <= min((LL)r, k2); i++){
            ret |= go(l, r - i, f^1) ^1;
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n1, n2;
    memset(dp, -1, sizeof dp);
    cin >> n1 >> n2 >> k1 >> k2;
    int f = go(n1, n2, 0);
    if(f) cout << "First" << endl;
    else cout << "Second" << endl;
}