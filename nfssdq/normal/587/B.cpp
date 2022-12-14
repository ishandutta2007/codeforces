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


LL dp[2][1000001], sum[2][1000001];
LL ar[1000001], cc[1000001];
map < LL, LL > mm;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n, k, l; cin >> n >> l >> k;
    REP(i, n) {
        cin >> ar[i];
        mm[ar[i]] = 1;
    }
    int cnt = 0;
    for(auto &v: mm){
        v.yy = ++cnt;
    }
    REP(i, n) {
        ar[i] = mm[ar[i]];
        cc[ar[i]]++;
    }

    dp[0][0] = 1;
    REP(i, cnt + 1) sum[0][i] = 1;

    LL num_groups = (l / n);
    LL extra = l % n;

    LL res = 0;

    int fl = 0;
    for(LL i = 1; i <= k; i++){
        fl ^= 1;
        dp[fl][0] = sum[fl][0] = 0;
        FOR(j, 1, cnt + 1){
            dp[fl][j] = (cc[j] * sum[fl ^ 1][j]) % mod;
            sum[fl][j] = (sum[fl][j - 1] + dp[fl][j]) % mod;

            if(num_groups >= i)res = (res + ((num_groups - i + 1)%mod) * dp[fl][j]) % mod;
        }

        for(LL j = 0; j < extra; j++){
            if(num_groups+1ll >= i)
                res = (res + sum[fl^1][ar[j]]) % mod;
        }
    }

    cout << res << endl;

}