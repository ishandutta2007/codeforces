#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<complex>
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
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


int pre_calc[3001][3001], ar[3001], dp[3001][3001], tmp[3011];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  FOR(ts, 1, T+1){
    int n; cin >> n;
    FOR(i, 1, n+1) cin >> ar[i];
    FOR(i, 1, n){
      FOR(j, i, n+1) tmp[j] = 0;
      int cnt = 0;
      for(int j = i; j < n; j++){
        tmp[min(n, j+ar[j])]++;
        cnt++;
        cnt -= tmp[j];
        pre_calc[i][j] = cnt;
      }
    }

    dp[n][n] = 0;
    for(int i = n-1; i >= 1; i--){
      int mn = 1000000, len = min(n, i + ar[i]);
      for(int j = len; j <= n; j++) dp[i][j] = mn;
      for(int j = len-1; j >= i; j--){
        mn = min(mn, pre_calc[i+1][j] + dp[j+1][len]);
        dp[i][j] = mn;
        //cout << i << " " << j << " " << dp[i][j] << " " << pre_calc[i+1][j] << " " << dp[j+1][len] << " " << len << endl;
      }
    }

    cout << dp[1][1] << endl;
  }
}