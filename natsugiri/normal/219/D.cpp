#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long LL;

int n;
vector<int>G[200100], R[200100];
bool use[200100];
int inv[200100], cnt;

int dfs(int e, int p) {
  int r=0;
  for (int i=0; i<(int)G[e].size(); i++) {
    if (G[e][i]==p) { use[e]=1; continue; }
    r+=dfs(G[e][i], e);
  }
  for (int i=0; i<(int)R[e].size(); i++) {
    if (R[e][i]==p) continue;
    r+=dfs(R[e][i], e)+1;
  }

  return r;
}


void dfs2(int e, int p) {
  if (p<0) inv[e]=cnt;
  else {
    inv[e]=inv[p];
    if (use[e]) inv[e]--;
    else inv[e]++;
  }
  for (int i=0; i<(int)G[e].size(); i++) {
    if (G[e][i]==p) continue;
    dfs2(G[e][i], e);
  }
  for (int i=0; i<(int)R[e].size(); i++) {
    if (R[e][i]==p) continue;
    dfs2(R[e][i], e);
  }
}
int main(){
  scanf("%d", &n);
  for (int i=0; i<n-1; i++) {
    int s,t;
    scanf("%d%d", &s, &t);
    s--; t--;
    G[s].push_back(t);
    R[t].push_back(s);
  }

  cnt=dfs(0,-1);
  dfs2(0,-1);
  int ans=n;
  vector<int>v;
  for (int i=0; i<n; i++) ans=min(ans, inv[i]);
  for (int i=0; i<n; i++) if (ans==inv[i]) v.push_back(i+1);

  printf("%d\n", ans);
  for (int i=0; i<(int)v.size(); i++) {
    printf("%d%c", v[i], i==v.size()-1?'\n':' ');
  }

  return 0;
}