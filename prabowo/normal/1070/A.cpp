#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

int D, S;

bool valid(int d, int s) {
  if (s < 0) return false;
  return true;
}

int dist[505][5005];
pair<int, int> bt[505][5005];
void bfs() {
  memset(dist, -1, sizeof dist);

  queue<pair<int, int>> q;
  q.push({0, S});
  dist[0][S] = 0;
  
  while (q.size()) {
    int d = q.front().first;
    int s = q.front().second;
    q.pop();
    
    for (int i=0; i<10; i++) {
      int nd = (d*10 + i) % D;
      int ns = s - i;
      
      if (!valid(nd, ns)) continue;
      if (dist[nd][ns] >= 0) continue;
      
      dist[nd][ns] = dist[d][s] + 1;
      bt[nd][ns] = {d, s};
      q.push({nd, ns});
    } 
  }
}

int main() {
  scanf("%d %d", &D, &S);
  
  bfs();
  
  if (dist[0][0] == -1) return 0 * printf("-1\n");
  
  vector<int> ans;
  int d = 0, s = 0;
  while (d != 0 || s != S) {
    int nd = bt[d][s].first;
    int ns = bt[d][s].second;
    ans.push_back(ns - s);
    d = nd;
    s = ns;
  }
  
  for (int i=(int)ans.size() - 1; i>=0; i--) printf("%d", ans[i]);
  printf("\n");
  
  return 0;
}