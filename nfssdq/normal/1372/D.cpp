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

LL ar[400001], sum[2][400001];

priority_queue < pair<LL, int > > pq[2];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  FOR(i, 1, n+1) {
    cin >> ar[i];
    ar[i+n] = ar[i];
  }
  if(n == 1){
    cout << ar[1] << endl;
    return 0;
  }
  for(int i = 1; i <= n+n; i++){
    if(i % 2 == 0){
      sum[1][i] = sum[1][i-1];
      sum[0][i] = ar[i] + sum[0][i-1];
    } else {
      sum[0][i] = sum[0][i-1];
      sum[1][i] = ar[i] + sum[1][i-1];
    }
  }

  LL res = max(sum[1][n], sum[0][n+1]);
  for(int i = 1; i <= n; i++){
    if(i % 2 == 0){
      pq[0].push(mp(sum[0][i] - sum[1][i], i));
    } else {
      pq[1].push(mp(sum[1][i] - sum[0][i], i));
    }
  }
  for(int i = 1; i <= n; i++){
    while(pq[0].top().yy <= i) pq[0].pop();
    while(pq[1].top().yy <= i) pq[1].pop();

    if(i % 2 == 0){
      res = max(res, pq[1].top().xx - sum[1][i] + sum[0][n+i-1]);
    } else {
      res = max(res, pq[0].top().xx - sum[0][i] + sum[1][n+i-1]);
    }

    if((i+n) % 2 == 0){
      pq[0].push(mp(sum[0][i+n] - sum[1][i+n], i+n));
    } else {
      pq[1].push(mp(sum[1][i+n] - sum[0][i+n], i+n));
    }
  }
  cout << res << endl;
}