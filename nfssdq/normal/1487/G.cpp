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
#include<cassert>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<complex>
#include<regex>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        998244353ll
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

LL dp[2][201][201][4][4], dp2[401][26][26], cnt[222][222], dp3[401][201][3][3], cnt2[222];
int ar[26];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  REP(i, 26) cin >> ar[i];
  REP(i, 26) REP(j, 26) dp2[n][i][j] = 1;
  for(int i = n-1; i >= 2; i--){
    REP(j, 26) REP(k, 26) REP(l, 26) 
      if(l != j) dp2[i][j][k] = (dp2[i][j][k] + dp2[i+1][k][l]) % mod;
  }

  LL tot = 0;
  REP(i, 26) REP(j, 26) tot = (dp2[2][i][j] + tot) % mod;

  REP(i, 3) REP(j, 3) dp3[n][0][i][j] = 1;
  for(int i = n-1; i >= 2; i--){
    REP(j, 201) REP(x, 3) REP(y, 3) {
      if(x != 0 && j != 0) dp3[i][j][x][y] += dp3[i+1][j-1][y][0];
      LL opts = 25 - (x > 0);
      if(y == 0) dp3[i][j][x][y] += dp3[i+1][j][y][1] * opts;
      else if(x == y) dp3[i][j][x][y] += dp3[i+1][j][1][2] * opts;
      else dp3[i][j][x][y] += dp3[i+1][j][1][1] + dp3[i+1][j][1][2] * (opts - 1);
      dp3[i][j][x][y] %= mod;
    }
  }
  REP(i, 26) REP(j, 26) REP(k, 201) {
    int x = i, y = j;
    if(i > 0) x = 1;
    if(j > 0) y = (i == j) ? 1 : 2;
    cnt2[k + (i == 0) + (j == 0)] += dp3[2][k][x][y];
  }
  REP(i, 201) cnt2[i] %= mod;
  REP(i, 26) for(int j = ar[i] + 1; j <= 200; j++) tot = (tot + mod - cnt2[j]) % mod;

  bool fl = 0;
  REP(i, 4) REP(j, 4) dp[fl][0][0][i][j] = 1;
  for(int i = n-1; i >= 2; i--){
    fl ^= 1;
    REP(j, 201) REP(k, 201)
      REP(x, 4) REP(y, 4) {
        dp[fl][j][k][x][y] = 0;
        if(x != 0 && j != 0) dp[fl][j][k][x][y] += dp[fl^1][j-1][k][y][0];
        if(x != 1 && k != 0) dp[fl][j][k][x][y] += dp[fl^1][j][k-1][y][1];
        LL opts = 24 - (x > 1);
        if(y <= 1) dp[fl][j][k][x][y] += dp[fl^1][j][k][y][2] * opts;
        else if(x == y) dp[fl][j][k][x][y] += dp[fl^1][j][k][2][3] * opts;
        else dp[fl][j][k][x][y] += dp[fl^1][j][k][2][2] + dp[fl^1][j][k][2][3] * (opts - 1);
        dp[fl][j][k][x][y] %= mod;
      }
  }

  REP(i, 26) REP(j, 26) REP(k, 201) REP(l, 201) {
    int x = i, y = j;
    if(i > 1) x = 2;
    if(j > 1) y = (i == j) ? 2 : 3; 
    cnt[k + (i==0) + (j==0)][l + (i == 1) + (j == 1)] += dp[fl][k][l][x][y];
  }
  REP(i, 201) REP(j, 201) cnt[i][j] %= mod;
  REP(i, 26) REP(j, 26){
    if(i <= j) continue;
    for(int k = ar[i] + 1; k <= 200; k++) 
      for(int l = ar[j] + 1; l <= 200; l++) {
        tot = (tot + cnt[k][l]) % mod;
      }
  }
  cout << tot << endl;
}