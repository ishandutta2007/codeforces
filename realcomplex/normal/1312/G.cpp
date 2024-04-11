#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 100;
const int AL = 26;

int cnt = 0;
int nx[N][AL];
int id[N];
vector<int> rf[N];
int ans[N];

int dep[N];
int subt[N];

void dfs(int u){
  subt[u] = (!rf[u].empty());
  for(int i = 0 ; i < AL; i ++ ){
    if(nx[u][i] != -1) {
      dep[nx[u][i]] = dep[u] + 1;
      dfs(nx[u][i]);
      subt[u] += subt[nx[u][i]];
    }
  }
}

void dfs1(int u, int o1, int o2, int idx){
  idx += (!rf[u].empty());
  int cur = o2 + dep[u];
  if(!rf[u].empty()){
    cur = min(cur, o1 + idx);
    assert(cur > 0);
    for(auto p : rf[u]) ans[p] = cur;
  }
  for(int i = 0 ; i < AL; i ++ ){
    if(nx[u][i] != -1){
      dfs1(nx[u][i],min(o1,cur-idx+1),min(o2,cur-dep[u]),idx);
      idx += subt[nx[u][i]];
    }
  }
}

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 0 ; i < n + 10; i ++ )
    for(int j = 0 ; j < AL; j ++ )
      nx[i][j]=-1;
  int par;
  char iq;
  id[0]=0;
  int fp;
  for(int i = 1; i <= n; i ++ ){
    cin >> par >> iq;
    fp = id[par];
    if(nx[fp][iq - 'a'] == -1){
      cnt ++ ;
      nx[fp][iq - 'a'] = cnt;
    }
    id[i] = nx[fp][iq - 'a'];
  }
  int k;
  cin >> k;
  int x;
  for(int i = 1; i <= k ; i ++ ){
    cin >> x;
    rf[id[x]].push_back(i);
  }
  dfs(0);
  dfs1(0, 0, 0, 0);
  for(int i = 1; i <= k ; i ++ )
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}