#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int B = 350;

vector<pii> seg[N];
vector<pii> ind[N];
vector<pii> kp[500];
int low[N];

struct State{
  int lef;
  int rig;
  int idx;
  bool operator< (const State &F) const {
    if(lef == F.lef) return rig < F.rig;
    else return lef < F.lef;
  }
};

int main(){
  //fastIO;
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i ++ )
    low[i] = (int)1e9 + 91;
  int l, r, p;
  for(int i = 0 ; i < k ; i ++ ){
    cin >> l >> r >> p;
    seg[p].push_back(mp(l, r));
  }
  int rm;
  for(int i = 1; i <= n; i ++ ){
    sort(seg[i].begin(), seg[i].end());
    rm = (int)1e9 + 9;
    for(int j = (int)seg[i].size() - 1; j >= 0 ; j -- ){
      rm = min(rm, seg[i][j].se);
      if(j == 0 || seg[i][j].fi != seg[i][j-1].fi){
        ind[i].push_back(mp(seg[i][j].fi, rm));
      }
    }
    sort(ind[i].begin(), ind[i].end());
  }
  l=1;
  r=0;
  int d;
  int cur;
  int id = 0;
  while(l <= n){
    r = min(r + B, n);
    d = r - l + 1;
    cur = 0;
    priority_queue<pii> ff;
    vector<State> csh;
    for(int j = l ; j <= r; j ++ ){
      ff.push(mp(low[j], j));
      for(auto x : seg[j]){
        csh.push_back({x.fi, x.se, j});
      }
    }
    sort(csh.begin(), csh.end());
    for(int t = (int)csh.size() - 1; t >= 0; t -- ){
      if(low[csh[t].idx] == (int)1e9 + 91)
        cur ++ ;
      low[csh[t].idx] = min(low[csh[t].idx], csh[t].rig);
      ff.push(mp(low[csh[t].idx], csh[t].idx));
      while(ff.top().fi > low[ff.top().se])
        ff.pop();
      if(t == 0 || csh[t].lef != csh[t-1].lef){
        if(d == cur){
          kp[id].push_back(mp(csh[t].lef, ff.top().fi));
        }
      }
    }
    sort(kp[id].begin(), kp[id].end());
    l += B;
    id ++ ;
  }
  int a, b, x, y;
  bool good;
  for(int q = 0; q < m; q ++ ){
    cin >> a >> b >> x >> y;
    good = true;
    while(a + B - 1 <= b){
      if(a % B == 1)
        break;
      id = lower_bound(ind[a].begin(), ind[a].end(), mp(x,-1)) - ind[a].begin();
      if(id >= (int)ind[a].size()) good = false;
      else{
        if(ind[a][id].se > y) good = false;
      }
      a ++ ;
    }
    while(a + B - 1 <= b){
      id = lower_bound(kp[a/B].begin(), kp[a/B].end(), mp(x,-1)) - kp[a/B].begin();
      
      if(id >= kp[a/B].size()) good = false;
      else{
        if(kp[a/B][id].se > y) good = false;
      }
      a += B;
    }
    while(a <= b){
      id = lower_bound(ind[a].begin(), ind[a].end(), mp(x,-1)) - ind[a].begin();
      if(id >= (int)ind[a].size()){
        good = false;
      }
      else{
        if(ind[a][id].se > y) good = false;
      }
      a ++ ;
    }
    if(good)
      cout << "yes\n";
    else
      cout << "no\n";
    fflush(stdout);
  }
  return 0;
}