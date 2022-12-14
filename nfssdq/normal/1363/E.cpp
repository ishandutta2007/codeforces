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

vector < int > vc[200001];
int A[200001], B[2000001], C[200001];
LL res = 0;
pair<int,int> dfs(int c, int p, int pv){
  pv = min(pv, A[c]);
  pair<int, int> ret = mp(0, 0);
  REP(i, vc[c].size()){
    if(vc[c][i] == p) continue;
    pair<int,int> pp = dfs(vc[c][i], c, pv);
    ret.xx += pp.xx;
    ret.yy += pp.yy;
  }
  if(B[c] != C[c]){
    if(B[c] == 0) ret.xx++;
    else ret.yy++;
  }
  int t = min(ret.xx, ret.yy);
  //cout << c << " " << ret.xx << " " << ret.yy << endl;
  ret.xx -= t;
  ret.yy -= t;
  res += 2ll * (LL)t * (LL)pv;
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  FOR(i, 1, n+1) cin >> A[i] >> B[i] >> C[i];
  REP(i, n-1){
    int x, y; cin >> x >> y;
    vc[x].pb(y);
    vc[y].pb(x);
  }
  pair<int,int> p = dfs(1, 0, mod);
  if(p.xx || p.yy) res = -1;
  cout << res << endl;
}