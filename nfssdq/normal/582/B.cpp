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

LL dp[10001][301], cnt[301], tmp[10001];
LL dp1[10001][301], ar[101];
void go1(int N, int T){
    int p = 0;
    for(int i = 1; i <= T; i++){
        for(int j = 1; j <= N; j++){
            tmp[++p] = ar[j];
        }
    }
    FOR(i, 1, N+1) cnt[ar[i]]++;

    LL res = 0;
    FOR(i, 1, N*T + 1){
        for(int j = 1; j <= 300; j++){
            dp[i][j] = dp[i-1][j];
            if(tmp[i] <= j) dp[i][j] = max(dp[i][j], 1 + dp[i-1][tmp[i]]);
            res = max(res, dp[i][j]);
        }
    }

    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL N, T; cin >> N >> T;
    FOR(i, 1, N+1) cin >> ar[i];
    if(T <= 100){
        go1(N, T);
        return 0;
    }
    int p = 0;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= N; j++){
            tmp[++p] = ar[j];
        }
    }
    FOR(i, 1, N+1) cnt[ar[i]]++;

    FOR(i, 1, N*100 + 1){
        for(int j = 1; j <= 300; j++){
            dp[i][j] = dp[i-1][j];
            if(tmp[i] <= j) dp[i][j] = max(dp[i][j], 1 + dp[i-1][tmp[i]]);
        }
    }
    reverse(tmp + 1, tmp + N*100 + 1);
    FOR(i, 1, N*100 + 1){
        for(int j = 1; j <= 300; j++){
            dp1[i][j] = dp1[i-1][j];
            if(tmp[i] >= j) dp1[i][j] = max(dp1[i][j], 1 + dp1[i-1][tmp[i]]);
        }
    }

    LL res = 0;
    for(int i = 1; i <= 300; i++){
        for(int j = 1; j <= 100; j++){
            for(int k = 1; k <= 100; k++){
                if(j + k > T) continue;
                res = max(res, dp[N*j][i] + dp1[N*k][i] + (T-j-k)*cnt[i]);
            }
        }
    }

    cout << res << endl;
}