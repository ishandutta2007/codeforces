#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int idx;
};

int n, m, s;
vector<int> des[314514];
vector<Edge> ues[314514];
bool used[314514];
char ansmax[314514];
char ansmin[314514];
int us[314514];
int vs[314514];
int ts[314514];

int CalcMin() {
  queue<int> q;
  
  fill(used, used+n, false);
  q.push(s);
  used[s] = true;
  int cnt = 1;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (Edge &e : ues[v]) {
      int u = e.to;
      int idx = e.idx;
      if (ansmin[idx]) continue;

      if (us[idx] == v) ansmin[idx] = '-';
      else ansmin[idx] = '+';
    }

    for (int u : des[v]) {
      if (!used[u]) {
        cnt++;
        used[u] = true;
        q.push(u);
      }
    }
  }

  return cnt;
}


int CalcMax() {
  queue<int> q;
  
  fill(used, used+n, false);
  q.push(s);
  used[s] = true;
  int cnt = 1;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (Edge &e : ues[v]) {
      int u = e.to;
      int idx = e.idx;
      if (ansmax[idx]) continue;

      if (us[idx] == v) ansmax[idx] = '+';
      else ansmax[idx] = '-';
      if (!used[u]) {
        cnt++;
        used[u] = true;
        q.push(u);
      }
    }

    for (int u : des[v]) {
      if (!used[u]) {
        cnt++;
        used[u] = true;
        q.push(u);
      }
    }
  }

  return cnt;
}

int main() {
  scanf("%d%d%d", &n, &m, &s);
  --s;
  for (int i=0; i<m; i++) {
    scanf("%d%d%d", &ts[i], &us[i], &vs[i]);
    --us[i];
    --vs[i];
    if (ts[i] == 1) des[us[i]].emplace_back(vs[i]);
    else {
      ues[us[i]].emplace_back(Edge{vs[i], i});
      ues[vs[i]].emplace_back(Edge{us[i], i});
    }
  }

  int minans = CalcMin();
  int maxans = CalcMax();

  printf("%d\n", maxans);
  for (int i=0; i<m; i++) {
    if (ts[i] == 1) continue;
    if (ansmax[i]) printf("%c", ansmax[i]);
    else printf("%c", '+');
  }
  puts("");

  printf("%d\n", minans);
  for (int i=0; i<m; i++) {
    if (ts[i] == 1) continue;
    if (ansmin[i]) printf("%c", ansmin[i]);
    else printf("%c", '-');
  }
  puts("");
}