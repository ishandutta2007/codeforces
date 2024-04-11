#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;


int n, k, m;
vector<int>G[2000], B[2000];

bool use[2000];

int rec(int p){
  int r=1;
  use[p]=1;
  
  for(int i=0; i<(int)B[p].size(); i++)
    if(use[B[p][i]])return -1;

  for(int i=0; i<(int)G[p].size(); i++){
    if(!use[G[p][i]]){
      int t=rec(G[p][i]);
      if(t==-1)return -1;
      r+=t;
    }
  }
  
  return r;
}


int main(){

  scanf("%d%d", &n, &k);
  for(int i=0; i<k; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  
  scanf("%d", &m);
  for(int i=0; i<m; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    B[u].push_back(v);
    B[v].push_back(u);
  }

  int ans=0;
  for(int i=0; i<n; i++){
    memset(use, 0, sizeof use);
    ans=max(ans, rec(i));
  }

  printf("%d\n", ans);

  return 0;
}