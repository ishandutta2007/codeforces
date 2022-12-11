#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5005;
vector<pii> T[N];
int col[N];

int state[N];

int m;

bool check(){
  for(int i =0  ;i  <m ; i ++ )
    if(col[i] == 0)
      return true;
  return false;
}

int cur=0;
void dfs(int u){  
  if(state[u]==2)
    return;
  state[u]=1;
  for(auto x : T[u]){
    if(col[x.se] != 0) continue;
    if(state[x.fi] != 1){
      col[x.se] = cur;
      dfs(x.fi);
    }
  }
  state[u]=2;
}

int main(){
  fastIO;
  int n;
  cin >> n >> m;
  int u, v;
  for(int i= 0 ; i < m ; i ++ ){
    cin >> u >> v;
    T[u].push_back(mp(v,i));
  }
  while(check()){
    cur++;
    for(int i = 1; i <= n; i ++ )
      state[i] = 0;
    for(int i = 1; i <= n; i ++ )
      dfs(i);
  }
  cout << cur << "\n";
  for(int i = 0; i < m; i ++ )
    cout << col[i] << " ";
  return 0;
}