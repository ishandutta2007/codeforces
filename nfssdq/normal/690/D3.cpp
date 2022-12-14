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


LL dp[105], vv[105];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int C, W, H; cin >> C >> W >> H;
    vv[0] = 1;
    LL md = 1000003;
    for(int i = 1; i <= W+1; i++){
        vv[i] = (vv[i-1] * H) % md;
    }
    int fl = 0;
    dp[0] = 1;
    LL sum = 1;
    for(int i = 1; i <= C; i++){
        fl = (fl + 1) % 104;

        if(i > W+1){
            int k = (fl - W - 2 + 104) % 104;
            sum = (sum - ((dp[k] * vv[W+1]) % md) + md) % md;
        }

        dp[fl] = sum;
        sum = (sum * H) % md;
        sum = (sum + dp[fl]) % md;
    }
    LL res = 0;
    int k = fl;
    for(int i = C; i >= C-W; i--){
        if(i < 0) break;
        res = (res + vv[C-i] * dp[k]) % md;
        k--;
        if(k < 0) k = 103;
    }
    cout << res << endl;
}