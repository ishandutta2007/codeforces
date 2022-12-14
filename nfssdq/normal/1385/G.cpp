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

int ar[2][2000001];
bool bad[200001];
int vis[200001];
set < int > S;
vector < int > vc[200001], vp[200001];

vector < int > tmp[2], res;

void solve(){
  int n; cin >> n;
  res.clear();
  FOR(i, 1, n+1) {
    vc[i].clear();
    vp[i].clear();
    bad[i] = vis[i] = false;
  }
  REP(i, 2) FOR(j, 1, n+1) cin >> ar[i][j];
  FOR(i, 1, n+1){
    vc[ar[0][i]].pb(ar[1][i]);
    vp[ar[0][i]].pb(i);
    vc[ar[1][i]].pb(ar[0][i]);
    vp[ar[1][i]].pb(i);
  }


  REP(i, 2){
    S.clear();
    FOR(j, 1, n+1) {
      if(S.find(ar[i][j]) != S.end()) bad[ar[i][j]] = 1;
      S.insert(ar[i][j]);
    }
  }

  FOR(i, 1, n+1){
    if(vc[i].size() != 2) {
      cout << -1 << endl;
      return;
    }
  }

  FOR(i, 1, n+1){
    if(vis[i] || bad[i] == 0) continue;
    REP(s, 2){
      bool fl = true;
      vis[i]++;
      tmp[s].clear();
      tmp[s].pb(vp[i][s]);
      for(int j = vc[i][s]; ;){
        if(bad[j]) fl ^= 1;
        vis[j]++;
        bool found = false;
        REP(k, vc[j].size()){
          if(vis[vc[j][k]] == s+1) continue;
          found = true;
          if(fl) tmp[s].pb(vp[j][k]);
          j = vc[j][k];
          break;
        }
        if(!found) break;
      }
      if(fl){
        cout << -1 << endl;
        return;
      }
    }
    bool take = 0;
    if(tmp[0].size() > tmp[1].size()) take = 1;
    REP(j, tmp[take].size()) res.pb(tmp[take][j]);
  }

  cout << res.size() << endl;
  REP(i, res.size()) cout << res[i] << " ";
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  FOR(ts, 1, T+1){
    solve();
  }
}