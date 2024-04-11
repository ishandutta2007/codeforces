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

set < int > s[300001];
vector < int > ep[300001], vc[300001], single[300001];
int tmp[300001], tc, done[300001], pre[300001], update_id[300001];
map < pair<int,int> ,int > mm;
map <int,int> mm2, mm3;
LL res = 0;

void dfs(int c, int p){
  int mx_sz = 0, mx_p = c;
  for(int nxt: vc[c]) if(nxt != p) {
    dfs(nxt, c);
    if(s[nxt].size() > mx_sz){
      mx_sz = s[nxt].size();
      mx_p = nxt;
    }
  }
  if(c == mx_p){
    for(int id: ep[c]) s[c].insert(id);
    REP(i, single[c].size()) res += s[c].size() + i;
    return;
  }
  tc = 0;
  for(int nxt: vc[c]) if(nxt != mx_p && nxt != p){
    for(int id: s[nxt]){
      if(s[mx_p].find(id) != s[mx_p].end()) {
        tmp[tc++] = id;
        done[id] = nxt;
        if(update_id[id] != c){
          update_id[id] = c;
          pre[id] = mx_p;
        }
        mm[{pre[id], nxt}]++;
        mm3[pre[id]]++;
        mm3[nxt]++;
      }
      else {
        s[mx_p].insert(id);
        pre[id] = nxt;
        update_id[id] = c;
      }
    }
  }

  int oc = 0;
  for(int id: ep[c]) if(s[mx_p].find(id) != s[mx_p].end()) {
    if(update_id[id] != c){
      update_id[id] = c;
      pre[id] = mx_p;
    }
    mm2[pre[id]]++;
    oc++;
  }
  LL extra = 0;
  REP(i, tc){
    int id = tmp[i];
    int lft = s[mx_p].size() - s[done[id]].size();
    if(pre[id] == mx_p) lft -= mx_sz;
    else lft -= s[pre[id]].size();
    res += lft + mm[{pre[id], done[id]}] - oc + mm2[pre[id]] + mm2[done[id]];
    extra += tc - mm3[pre[id]] - mm3[done[id]] + mm[{pre[id], done[id]}];
  }
  //cout << c << " " << extra << endl;

  for(int id: ep[c]) if(s[mx_p].find(id) != s[mx_p].end()){
    if(pre[id] == mx_p) res += s[mx_p].size() - mx_sz;
    else res += s[mx_p].size() - s[pre[id]].size();
    extra += oc - mm2[pre[id]];
    tmp[tc++] = id;
  }

  res -= extra / 2ll;
  for(int id: ep[c]) if(s[mx_p].find(id) == s[mx_p].end()) {
    s[mx_p].insert(id);
    res += tc;
  }
  REP(i, single[c].size()) res += s[mx_p].size() + i;
  REP(i, tc) s[mx_p].erase(tmp[i]);
  swap(s[mx_p], s[c]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  REP(i, n-1){
    int x, y; cin >> x >> y;
    vc[x].pb(y);
    vc[y].pb(x);
  }
  int m; cin >> m;
  REP(i, m){
    int x, y; cin >> x >> y;
    if(x == y){
      single[x].pb(i+1);
      continue;
    }
    ep[x].pb(i+1);
    ep[y].pb(i+1);
  }
  dfs(1, 0);
  cout << res << endl;
}