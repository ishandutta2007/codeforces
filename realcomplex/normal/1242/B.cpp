#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;

set<int> nt;
set<int> edg[N];

int mx = 0;

void dfs(int x){
  auto it = nt.begin();
  int nx;
  while(it != nt.end()){
    if(edg[x].count(*it)){
      it++;
      continue;
    }
    nx = *it;
    mx ++ ;
    nt.erase(it);
    dfs(nx);
    it=nt.lower_bound(nx);
  }
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int a, b;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> a >> b;
    edg[a].insert(b);
    edg[b].insert(a);
  }
  for(int i = 1; i <= n; i ++ ){
    nt.insert(i);
  }
  int node;
  while(!nt.empty()){
    auto it = nt.begin();
    node = *it;
    nt.erase(it);
    dfs(node);
  }
  cout << n - 1 - mx << "\n";
  return 0;
}