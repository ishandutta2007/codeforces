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

#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>
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
#define ALL(A)     A.begin(), A.end()
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

LL isp[100001], ar[333], cc[333];
vector < int > factor[333], prime;
LL dp[302][1<<11], n, tt[333][333], p;
LL go(int c, int bp){
    if(c >= n){
        return bp == 0 ? 0 : 1ll<<60;
    }
    LL &ret = dp[c][bp];
    if(ret != -1) return ret;
    ret = 0;
    ret = go(c + 1, bp);
    ret = min(ret, cc[c] + go(c + 1, bp&tt[p][c]));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = -1,e,f = -1,g,h = 0,x,y,z = 0;
    for(int i = 2; i <= 100000; i++){
        if(isp[i] == 0){
            for(int j = i*2; j <= 100000; j += i) isp[j] = 1;
            prime.pb(i);
        }
    }
    cin >> a;
    REP(i, a) {
        cin >> ar[i];
        b = ar[i];
        REP(j, prime.size()){
            if(b % prime[j] == 0) factor[i].pb(prime[j]);
            while(b % prime[j] == 0) b /= prime[j];
        }
        if(b > 1) factor[i].pb(b);
    }
    REP(i, a) cin >> cc[i];
    REP(i, a){
        FOR(j, i, a){
            b = 0;
            REP(k, factor[i].size()){
                REP(l, factor[j].size()){
                    if(factor[i][k] == factor[j][l]) b |= 1ll<<k;
                }
            }
            tt[i][j] = b;
        }
    }
    n = a;
    f = mod * 10000000ll;
    for(int i = 0; i < a; i++){
        memset(dp, -1, sizeof dp);
        p = i;
        f = min(f, go(i, (1ll<<factor[i].size())-1) + cc[i]);
    }
    if(f > 1000000000000000ll) cout << -1 << endl;
    else cout << f << endl;
}