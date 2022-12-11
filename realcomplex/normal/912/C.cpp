#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 10;

set<pii> T[N];
int reg[N];

map<int, int> tq;

int main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  int mx, hl;
  int ff, inc, dmg;
  cin >> ff >> inc >> dmg;
  for(int i = 1; i <= n; i ++ ){
    cin >> mx >> hl >> reg[i];
    if(dmg >= mx && inc > 0){
      cout << "-1\n";
      return 0;
    }
    else{
      T[i].insert(mp(0, hl));
    }
  }
  int idx;
  int tt;
  for(int i = 1; i <= q; i ++ ){
    cin >> tt >> idx >> hl;
    T[idx].insert(mp(tt, hl));
  }
  int tim;
  int nim;
  int ni;
  for(int i = 1; i <= n; i ++ ){
    auto it = T[i].begin();
    while(it != T[i].end()){
      tim = (it->fi);
      hl = (it->se);
      if(hl > dmg){
        it++;
        continue;
      }
      else{
        auto nx = it;
        nx ++ ;
        if(reg[i] == 0){
          if(inc > 0 && nx == T[i].end()){
            cout << "-1\n";
            return 0;
          }
          tq[tim] ++ ;
          if(nx != T[i].end()){
            tq[nx->fi] --;
            tq[nx->fi - 1];
          }
        }
        else{
          tq[tim] ++ ;
          ni = tim + (dmg - hl + reg[i]) / reg[i];
          if(nx != T[i].end()){
            ni = min(ni, nx->fi);
          }
          tq[ni] -- ;
          tq[ni - 1];
        }
      }
      it ++ ;
    }
  }
  int cur = 0;
  ll ans = 0;
  for(auto p : tq){
    cur += p.se;
    ans = max(ans, cur * 1ll * (ff + p.fi * 1ll * inc));
  }
  cout << ans << "\n";
  return 0;
}