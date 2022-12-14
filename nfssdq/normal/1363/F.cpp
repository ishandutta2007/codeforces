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
 
int dp[2222][2222], freqs[2222][30], freqt[2222][30], ds[30], dt[30];
string S, T;
 
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int TT; cin >> TT;
  FOR(ts, 1, TT+1){
    int n; cin >> n >> S >> T;
    REP(i, 26) freqs[0][i] = freqt[0][i] = 0;
    REP(i, n){
      if(i) REP(j, 26) {
        freqs[i][j] = freqs[i-1][j];
        freqt[i][j] = freqt[i-1][j];
      }
      freqs[i][S[i] - 'a']++;
      freqt[i][T[i] - 'a']++;
    }
    bool fl = false;
    REP(i, 26){
      if(freqt[n-1][i] != freqs[n-1][i]) fl = true;
    }
    if(fl){
      cout << -1 << endl;
      continue;
    }
 
    REP(i, n+1) dp[n][i] = 0;
    for(int i = n-1; i >= 0; i--){
      dp[i][n] = n-i;
      for(int j = n-1; j >= 0; j--){
        dp[i][j] = mod;
 
        int cs = freqs[j][S[j] - 'a'], ct = freqt[i][S[j] - 'a'];
 
        if(S[j] == T[i]) {
          ct--;
          dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
        }
        if(cs <= ct) dp[i][j] = min(dp[i][j], dp[i][j+1]);
        dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);
        //cout << dp[i][j] << " " ;
      }
      // cout << endl;
    }
    cout << dp[0][0] << endl;
  }
}