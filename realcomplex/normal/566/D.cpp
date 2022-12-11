#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

const int N = (int)2e5 + 912;

struct Union{
  int nex[N];
  int siz[N];
  void Init(){
    for(int i = 0;i < N; i ++ )
      nex[i] = i, siz[i] = 1;
  }
  int fin(int a){
    if(a == nex[a])
      return a;
    nex[a] = fin(nex[a]);
    return nex[a];
  }
  void Merge(int a, int b){
    a = fin(a);
    b = fin(b);
    if(a == b)
      return;
    if(siz[a] > siz[b])
      swap(a, b);
    siz[b] += siz[a];
    nex[a] = b;
  }
  bool Same(int a, int b){
    return fin(a) == fin(b);
  }
};

Union teams;
set<pii> segm;

int main(){
  fastIO;
  teams.Init();
  int n, q;
  cin >> n >> q;
  int ty;
  int x, y;
  int tl, tr;
  int las;
  for(int tti = 0; tti < q; tti ++ ){
    cin >> ty;
    if(ty == 2){
      cin >> x >> y;
      tl = x, tr = y;
      las = x;
      auto it = segm.lower_bound(mp(x, 0));
      if(it != segm.begin()){
        it -- ;
      }
      while(it != segm.end() and it->fi <= y){
        if(it -> se < x){
          it ++ ;
          continue;
        }
        tl = min(tl, it -> fi);
        tr = max(tr, it -> se);
        for(int xix = (it -> fi); xix >= las; xix -- ){
          teams.Merge(xix, las);
        }
        las = (it -> se);
        auto nex = it;
        nex ++ ;
        segm.erase(it);
        it = nex;
      }
      for(int is = las; is <= y; is ++ ){
        teams.Merge(is, las);
      }
      segm.insert(mp(tl, tr));
    }
    else if(ty == 1){
      cin >> x >> y;
      teams.Merge(x, y);
    }
    else{
      cin >> x >> y;
      cout << (teams.Same(x, y) == true ? "YES\n" : "NO\n");
    }
  }
  return 0;
}