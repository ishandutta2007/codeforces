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

vector < int > vc[200001];
int deg[200001], mrk[200001], leaves[200001];
set < int > S;
queue < int > Q;

void solve(){
  int n, K; cin >> n >> K;
  FOR(i, 1, n+1) {
    vc[i].clear();
    deg[i] = mrk[i] = leaves[i] = 0;
  }
  REP(i, n-1){
    int x, y; cin >> x >> y;
    vc[x].pb(y);
    vc[y].pb(x);
    deg[x]++;
    deg[y]++;
  } 

  FOR(i, 1, n+1) if(deg[i] == 1){
    Q.push(i);
  }

  int tot = 0;

  while(!Q.empty()){
    int c = Q.front();
    Q.pop();
    mrk[c] = 1;
    REP(i, vc[c].size()){
      if(mrk[vc[c][i]]) continue;
      int nxt = vc[c][i];
      leaves[nxt]++;
      if(leaves[nxt] == K){
        tot++;
        leaves[nxt] -= K;
      }
      deg[nxt]--;
      S.insert(nxt);
    }

    if(Q.empty()){
      for(int v: S){
        if(deg[v] == 1 && leaves[v] == 0) Q.push(v);
      }
      S.clear();
    }
  }
  cout << tot << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  FOR(ts, 1, T+1){
    solve();
  }
}