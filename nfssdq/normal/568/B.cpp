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

LL ncr[4001][4001], dp[4001][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ncr[0][0] = 1;
    for(int i = 1; i <= 4000; i++){
        ncr[i][0] = 1;
        for(int j = 1; j <= i; j++) ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % mod;
    }

    int n; cin >> n;
    dp[0][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            dp[i][0] = (dp[i][0] + ncr[i-1][j] * dp[i-j-1][0]) % mod;
            dp[i][1] = (dp[i][1] + ncr[i-1][j] * dp[i-j-1][1]) % mod;
        }
        dp[i][0] = (dp[i][0] + dp[i-1][0]) % mod;
        dp[i][0] = (dp[i][0] + dp[i-1][1]) % mod;

        dp[i][1] = (dp[i][1] + 2ll*dp[i-1][1]) % mod;
    }

    cout << dp[n][0] << endl;
}