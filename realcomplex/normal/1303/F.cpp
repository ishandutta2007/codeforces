#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 305;
const int Q = (int)2e6 + 10;
int dir[4][2] = {{-1,0},{+1,0},{0,-1},{0,+1}};
int a[N][N];
bool act[N][N];
int n, m, q;

bool is(int x, int y){  
  return (x >= 1 && y >= 1 && x <= n && y <= m && act[x][y]);
}


struct P{
  int xc;
  int yc;
  int idx;
};

vector<P> del[Q];
vector<P> add[Q];

int con[Q];

pii nx[N][N];

pii fin(pii a){
  if(a==nx[a.fi][a.se])return a;
  return nx[a.fi][a.se]=fin(nx[a.fi][a.se]);
}

bool unite(pii a, pii b){
  a=fin(a);
  b=fin(b);
  if(a==b)return false;
  nx[a.fi][a.se]=b;
  return true;
}

int main(){
  fastIO;
  cin >> n >> m >> q;
  int x, y, c;
  for(int i = 0 ; i < q; i ++ ){
    cin >> x >> y >> c;
    add[c].push_back({x, y, i});
    if(a[x][y] != c){
      del[a[x][y]].push_back({x,y,i});
    }
    a[x][y]=c;
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      del[a[i][j]].push_back({i,j,q});
    }
  }
  int ni, nj;
  for(int p = 0 ; p < Q; p ++ ){
    if(add[p].empty()) continue;
    for(int i = 1; i <= n; i ++ ) for(int j = 1; j <= m ; j ++ ) nx[i][j]=mp(i,j),act[i][j]=false;
    for(auto x : add[p]){
      act[x.xc][x.yc]=true;
      for(int d = 0; d < 4; d ++ ){
        ni = x.xc + dir[d][0];
        nj = x.yc + dir[d][1];
        if(is(ni,nj)){
          if(unite(mp(x.xc,x.yc),mp(ni, nj))) con[x.idx] ++ ;
        }
      }
    }
  }
  for(int p = 0 ; p < Q; p ++ ){
    if(del[p].empty()) continue;
    reverse(del[p].begin(), del[p].end());
    for(int i = 1; i <= n; i ++ ){
      for(int j = 1; j <= m ; j ++ ){
        nx[i][j]=mp(i,j);
        act[i][j]=false;
      }
    }
    for(auto x : del[p]){
      act[x.xc][x.yc]=true;
      for(int d = 0; d < 4; d ++ ){
        ni = x.xc + dir[d][0];
        nj = x.yc + dir[d][1];
        if(is(ni,nj)){
          if(unite(mp(x.xc,x.yc),mp(ni,nj))) con[x.idx] -- ;
        }
      }
    }
  }
  int ans = 0;
  for(int i = 0 ; i < q; i ++ ){
    ans += con[i];
    cout << 1-ans << "\n";
  }
  return 0;
}