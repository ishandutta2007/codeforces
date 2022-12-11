#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = (int)3e5 + 9;

set<int>E[N];
set<int>vis;

void dfs(int u){
  vector<int> cc;
  for(auto x : vis)
    if(!E[u].count(x))
      cc.push_back(x);
  for(auto x : cc)
    vis.erase(x);
  for(auto x : cc)
    dfs(x);
}

int main(){
  fastIO;
  int n,m,k;
  cin >> n >> m >> k;
  int ai, bi;
  int deg = n-1;
  for(int i = 0;i < m; i ++ ){
    cin >> ai >> bi;
    if(ai == 1 or bi == 1)
      deg -- ;
    E[ai].insert(bi);
    E[bi].insert(ai);
  }
  if(deg < k){
    cout << "impossible\n";
    return 0;
  }
  for(int i = 2;i <= n;i ++ ){
    vis.insert(i);
  }
  int comp = 0;
  for(int i = 2;i <= n;i ++ ){
    if(E[1].count(i) == 0 and vis.count(i)){
      dfs(i);
      comp ++ ;
    }
  }
  if(!vis.empty()){
    cout << "impossible\n";
    return 0;
  }
  if(comp > k){
    cout << "impossible\n";
    return 0;
  }
  cout << "possible\n";
  return 0;
}