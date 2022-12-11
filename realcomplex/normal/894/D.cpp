#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 9;
vector<ll> T[N];
vector<ll> pf[N];
vector<pii> nx[N];
int par[N];
int dip[N];

void build(int node){ 
  if(nx[node].empty()){
    T[node].push_back(0);
    return;
  }
  vector<ll> f[2];
  int c = 0;
  for(auto x : nx[node]){
    build(x.fi);
    f[c]=T[x.fi];
    for(auto &y : f[c]){
      y += x.se;
    }
    c ++ ;
  }
  int p = 0;
  T[node].push_back(0);
  for(int i = 0 ; i < f[0].size(); i ++ ){
    while(p < f[1].size() && f[1][p]<f[0][i]){
      T[node].push_back(f[1][p]);
      p++;
    }
    T[node].push_back(f[0][i]);
  }
  while(p < f[1].size()){
    T[node].push_back(f[1][p]);
    p ++ ;
  }
}

int main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  int l;
  for(int i = 2; i <= n; i ++ ){
    cin >> l;
    nx[i/2].push_back(mp(i,l));
    par[i]=i/2;
    dip[i]=l;
  }
  build(1);
  for(int i =1 ; i <= n; i ++ ){
    pf[i]=T[i];
    for(int j = 1; j < pf[i].size(); j ++ ){
      pf[i][j] += pf[i][j-1];
    }
  }
  int node;
  int dis;
  int pv;
  int cur;
  ll ans;
  int ned;
  int id;
  for(int t = 0; t < q; t ++ ){
    cin >> node >> dis;
    pv=-1;
    cur = 0;
    ans = 0;
    while(node>=1){
      if(cur > dis) break;
      ans += dis-cur;
      for(auto x : nx[node]){
        if(x.fi==pv)continue;
        ned=dis-cur-x.se;
        id=upper_bound(T[x.fi].begin(),T[x.fi].end(),ned)-T[x.fi].begin();
        id--;
        if(id>=0){
          ans+=(id+1)*1ll*dis;
          ans-=(id+1)*1ll*(cur+x.se);
          ans-=pf[x.fi][id];
        }
      }
      if(node==1)break;
      cur += dip[node];
      pv=node;
      node=par[node];
    }
    cout << ans << "\n";
  }
  return 0;
}