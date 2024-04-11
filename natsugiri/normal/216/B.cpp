#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int n, m;
int cnt;
vector<pair<int,int> >v;
vector<int>G[111];
bool use[111];

bool ring(int p, int prev) {
  if (use[p]) return 1;
  use[p]=1;
  cnt++;
  bool b=0;
  for (int i=0; i<(int)G[p].size(); i++) {
    if (G[p][i]==prev) continue;
    if (ring(G[p][i], p)) b=1;
  }
  return b;
}


int main(){
  scanf("%d%d", &n, &m);
  for (int i=0; i<m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  
  for (int i=0; i<n; i++) {
    if (!use[i]) {
      cnt=0;
      if (ring(i, -1)) v.push_back(make_pair(cnt/2, cnt/2));
      else v.push_back(make_pair((cnt+1)/2, cnt/2));
    }
  }

  int x, y;
  x=y=0;
  for (int i=0; i<(int)v.size(); i++) {
    if (x>y) {
      x+=v[i].second;
      y+=v[i].first;
    } else {
      x+=v[i].first;
      y+=v[i].second;
    }
  }
    
  printf("%d\n", n-min(x,y)*2);
  return 0;
}