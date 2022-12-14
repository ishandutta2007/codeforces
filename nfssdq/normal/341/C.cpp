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
#define ALL(A)     (A).begin(), (A).end()
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

LL dp[2001][2001], fact[2001];
LL go(int c, int p){
    if(c == 0) return fact[p];
    LL &ret = dp[c][p];
    if(ret != -1) return ret;
    ret = 0;
    ret = ((LL)(c - 1) * go(c - 2, p + 1)) % mod;
    if(p > 0) ret = (ret + (LL)p * go(c - 1, p)) % mod;
    return ret;
}
LL ar[2001], on[2001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z = 0;
    memset(dp, -1, sizeof dp);
    fact[0] = 1; FOR(i, 1, 2001) fact[i] = (fact[i - 1] * i) % mod;
    cin >> a;
    b = a, c = 0;
    FOR(i, 1, a + 1){
        cin >> ar[i];
        if(ar[i] != -1) {
            on[ar[i]] = 1;
            b--;
        }
    }
    FOR(i, 1, a + 1){
        if(ar[i] != -1){
            if(on[i] == 0) {
                c++; b--;
            }
        }
    }
    cout << go(b, c) << endl;
}