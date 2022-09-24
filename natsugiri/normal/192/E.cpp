#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k;
vector<int>v[100100];
vector<pair<int, int> >edge;
int parent[100100], depth[100100], d[100100][22], e[100100];

void dfs(int p, int t, int d) {
  parent[t]=p;
  depth[t]=d;
  for (int i=0; i<(int)v[t].size(); i++) {
    if (v[t][i]==p) continue;
    dfs(t, v[t][i], d+1);
  }
}

int lca(int a, int b) {
  for (int i=20; i>=0; i--) if (depth[b] <= depth[a]-(1<<i)) a=d[a][i];
  for (int i=20; i>=0; i--) if (depth[a] <= depth[b]-(1<<i)) b=d[b][i];

  if (a==b) return a;

  for (int i=20; i>=0; i--) {
    if (d[a][i]!=d[b][i]) {
      a=d[a][i];
      b=d[b][i];
    }
  }
  return parent[a];
}

int dfss(int p, int t) {
  int s=0;
  for (int i=0; i<(int)v[t].size(); i++) {
    if (v[t][i]==p) continue;
    s+=dfss(t, v[t][i]);
  }
  return e[t]=e[t]+s;
}

int main() {

  scanf("%d", &n);

  for (int i=0; i<n-1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--; y--;
    v[x].push_back(y);
    v[y].push_back(x);
    edge.push_back(make_pair(x, y));
  }

  dfs(-1, 0, 0);

  for (int i=0; i<n; i++) d[i][0]=parent[i];
  d[0][0]=0;

  
  for (int i=1; i<=20; i++) for (int j=0; j<n; j++) d[j][i]=d[d[j][i-1]][i-1];

  
  scanf("%d", &k);
  for (int i=0; i<k; i++) {
    int x, y, z;
    scanf("%d%d", &x, &y);
    x--; y--;
    z=lca(x, y);
    e[x]++; e[y]++; e[z]-=2;
  }

  dfss(-1, 0);

  for (int i=0; i<n-1; i++) {
    int x;
    if (depth[edge[i].first]<depth[edge[i].second]) x=edge[i].second;
    else x=edge[i].first;
    printf("%d%c", e[x], n-2-i?' ':'\n');
  }
  
  return 0;
}