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
const int M = N * 2;
const int P = 1200;

struct Query{
  int ch;
  int lef;
  int rig;
  int idx;
  bool operator< (const Query &F) const {
    if(ch/P == F.ch/P){
      if(lef/P == F.lef/P) return rig < F.rig;
      return lef/P < F.lef/P;
    }
    return ch/P < F.ch/P;
  }
};

struct Chn{
  int idx;
  int pv;
  int nx;
};

int a[N];

map<int, int> ash;
int ct;

int fin(int x){
  if(ash.count(x)) return ash[x];
  return ash[x] = ++ct;
}

int res[N];

int cnt[M];
int has[N];
int in[N];

int main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    a[i]=fin(a[i]);
    in[i]=a[i];
  }
  vector<Query> qqi;
  vector<Chn> ish;
  int ty, l, r;
  for(int t = 0 ;t < q; t ++ ){
    cin >> ty >> l >> r;
    if(ty == 2){
      r=fin(r);
      ish.push_back({l,a[l],r});
      a[l]=r;
    }
    else{
      qqi.push_back({(int)ish.size(), l, r, (int)qqi.size()});
    }
  }
  for(int i = 1; i <= n; i ++ )
    a[i] = in[i];
  sort(qqi.begin(), qqi.end());
  int ti = 0;
  int li = 1, ri = 0;
  int ans;
  for(auto pq : qqi){
    while(ti < pq.ch){
      if(ish[ti].idx >= li && ish[ti].idx <= ri){
        has[cnt[ish[ti].pv]] -- ;
        cnt[ish[ti].pv] -- ;
        has[cnt[ish[ti].pv]] ++ ;
        
        has[cnt[ish[ti].nx]] -- ;
        cnt[ish[ti].nx] ++ ;
        has[cnt[ish[ti].nx]] ++ ;
      }
      a[ish[ti].idx] = ish[ti].nx;
      ti ++ ;
    }
    while(ti > pq.ch){
      ti -- ;
      if(ish[ti].idx >= li && ish[ti].idx <= ri){
        has[cnt[ish[ti].nx]] -- ;
        cnt[ish[ti].nx] -- ;
        has[cnt[ish[ti].nx]] ++ ;
        
        has[cnt[ish[ti].pv]] -- ;
        cnt[ish[ti].pv] ++ ;
        has[cnt[ish[ti].pv]] ++ ;
      }
      a[ish[ti].idx] = ish[ti].pv;
    }
    while(li < pq.lef){
      has[cnt[a[li]]] -- ;
      cnt[a[li]] -- ;
      has[cnt[a[li]]] ++ ;
      li ++ ;
    }
    while(li > pq.lef){
      li -- ;
      has[cnt[a[li]]] -- ;
      cnt[a[li]] ++ ;
      has[cnt[a[li]]] ++ ;
    }
    while(ri < pq.rig){
      ri ++ ;
      has[cnt[a[ri]]] -- ;
      cnt[a[ri]] ++ ;
      has[cnt[a[ri]]] ++ ;
    }
    while(ri >  pq.rig){
      has[cnt[a[ri]]] -- ;
      cnt[a[ri]] -- ;
      has[cnt[a[ri]]] ++ ;
      ri -- ;
    }
    ans = 1;
    while(has[ans] > 0) ans ++ ;
    res[pq.idx] = ans;
  }
  for(int t = 0 ; t < qqi.size(); t ++ )
    cout << res[t] << "\n";
  return 0;
}