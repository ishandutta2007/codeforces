#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Edge{
  int ai;
  int bi;
  int wei;
  bool operator< (const Edge &F) const {
    return wei < F.wei;
  }
};

const int N = (int)2e5 + 9;
int par[N];
int sz[N];

int fin(int x){ 
  if(x == par[x]) return x;
  return par[x]=fin(par[x]);
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i ++ ) par[i] = i, sz[i]=1;
  vector<Edge> eg(m);
  for(int i = 0 ; i < m ; i ++ ){
    cin >> eg[i].ai >> eg[i].bi >> eg[i].wei;
  }
  sort(eg.begin(), eg.end());
  reverse(eg.begin(), eg.end());
  int ans = 0;
  for(int i = 0 ; i < m ; i ++ ){
    eg[i].ai = fin(eg[i].ai);
    eg[i].bi = fin(eg[i].bi);
    if(sz[eg[i].ai] + sz[eg[i].bi] == 0){
      if(eg[i].ai != eg[i].bi){
        par[eg[i].bi] = eg[i].ai;
      }
      continue;
    }
    ans += eg[i].wei;
    if(eg[i].ai == eg[i].bi){
      sz[eg[i].ai] -- ;
    }
    else{
      par[eg[i].bi] = eg[i].ai;
      sz[eg[i].ai] += sz[eg[i].bi]-1;
    }
  }
  cout << ans << "\n";
  return 0;
}