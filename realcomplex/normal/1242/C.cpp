#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<ll, pii> pos;

const int K = 15;
vector<pii> bits[1 << K];

int main(){
  fastIO;
  int k;
  cin >> k;
  vector<ll> a[k];
  vector<vector<pii>> cyc[k];
  int n;
  ll S = 0;
  for(int i = 0 ; i < k ; i ++ ){
    cin >> n;
    a[i].resize(n);
    cyc[i].resize(n);
    for(int j = 0 ; j < n ; j ++ ){
      cin >> a[i][j];
      pos[a[i][j]] = mp(i,j);
      S += a[i][j];
    }
  }
  if(S % k != 0){
    cout << "No\n";
    return 0;
  }
  S/=k;
  ll q[k];
  for(int i = 0 ; i < k ; i ++ ){
    q[i]=S;
    for(auto x : a[i]){
      q[i] -= x;
    }
  }
  pii ii;
  ll nx;
  for(int i = 0 ; i < k; i ++ ){
    for(int j = 0 ; j < a[i].size(); j ++ ){
      int mask = (1 << i);
      ii = mp(i,j);
      while(1){
        nx = q[ii.fi] + a[ii.fi][ii.se];
        cyc[i][j].push_back(ii);
        if(!pos.count(nx)){
          mask=-1;
          break;
        }
        ii=pos[nx];
        
        if((mask & (1 << ii.fi))){
          if(ii.fi != i || ii.se != j){
            mask=-1;
            break;
          }
          break;
        }
        mask |= (1 << ii.fi);
      }
      if(mask != -1){
        bits[mask] = {mp(i,j)};
      }
    }
  }
  int ot;
  for(int i = 1; i < (1 << k); i ++ ){
    if(!bits[i].empty()) continue;
    for(int j = i; j > 0; j = ((j-1)&i)){
      ot = (i ^ j);
      if(!bits[j].empty() && !bits[ot].empty()){
        for(auto x : bits[j])
          bits[i].push_back(x);
        for(auto x : bits[ot])
          bits[i].push_back(x);
        break;
      }
    }
  }
  if(bits[(1 << k) - 1].empty()){
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  pii sol[k];
  int m;
  for(auto x : bits[(1 << k) - 1]){
    m = cyc[x.fi][x.se].size();
    for(int i = 0 ; i < cyc[x.fi][x.se].size(); i ++ ){
      sol[cyc[x.fi][x.se][(i + 1)%m].fi] = mp(a[cyc[x.fi][x.se][(i+1)%m].fi][cyc[x.fi][x.se][(i+1)%m].se], cyc[x.fi][x.se][i].fi);
    }
  }
  for(int i = 0 ; i < k ; i ++ ){
    cout << sol[i].fi << " " << sol[i].se+1 << "\n";
  }
  return 0;
}