#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
vector<int> T[N];

int res = -1, x=-1,y=-1,z=-1;

int mx[N];
int mxi[N];

void dfs1(int u, int par){
  mxi[u]=u;
  mx[u]=0;
  for(auto p : T[u]){
    if(p == par) continue;
    dfs1(p, u);
    if(mx[p] + 1 > mx[u]){
      mx[u] = mx[p] + 1;
      mxi[u] = mxi[p];
    }
  }
}

void dfs2(int u, int par, int bes, int id){
  vector<pii> bel;
  for(auto p : T[u]){
    if(p == par) continue;
    bel.push_back(mp(mx[p]+1, mxi[p]));
  }
  sort(bel.begin(), bel.end());
  reverse(bel.begin(), bel.end());
  int sum = 0;
  int ax=-1,ay=-1,az=-1;
  for(int i = 0 ; i < 3; i ++ ){
    if(i<bel.size()){
      sum += bel[i].fi;
      if(i==0)ax=bel[i].se;
      else if(i==1)ay=bel[i].se;
      else az=bel[i].se;
    }
    if(i<2){
      if(sum + bes > res){
        res = sum + bes;
        x=ax;
        y=ay;
        z=id;
      }
    }
    else{
      if(sum > res){
        res = sum;
        x=ax;
        y=ay;
        z=az;
      }
    }
  }
  bes++;
  multiset<pii> good;
  for(auto p : T[u]){
    if(p==par) continue;
    good.insert(mp(mx[p]+1, mxi[p]));
  }
  for(auto p : T[u]){
    if(p==par) continue;
    good.erase(mp(mx[p]+1,mxi[p]));
    auto it = good.end();
    if(it != good.begin())it--;
    if(it != good.end() && it->fi + 1 > bes){
      dfs2(p,u,it->fi+1, it->se);
    }
    else{
      dfs2(p,u,bes, id);
    }
    good.insert(mp(mx[p]+1,mxi[p]));
  }
}


int main(){
  fastIO;
  int n;
  cin >> n;
  int a, b;
  for(int i = 1; i < n ; i ++ ){
    cin >> a >> b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  dfs1(1,-1);
  dfs2(1,-1,0,1);
  if(y==-1)swap(y,x);
  if(z==-1)swap(z,x);
  if(x==-1){
    for(int i = 1; i <= n; i ++ ){
      if(i != z && i != y){
        x=i;
        break;
      }
    }
  }
  cout << res << "\n";
  cout << x << " " << y << " " << z << "\n";
  return 0;
}