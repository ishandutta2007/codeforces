#include<bits/stdc++.h>

using namespace std;

const int maxn = 200005;

int n, m;
vector<int> g[maxn], e[maxn];
int markup[maxn], markdown[maxn];

void up(int v) {
  markup[v] = 1;
  for(int s : e[v]) if(!markup[s]) up(s);
}

void down(int v) {
  markdown[v] = 1;
  for(int s : g[v]) if(!markdown[s]) down(s);
}

int deg[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    g[--x].push_back(--y);
    e[y].push_back(x);
    deg[y]++;
  }

  vector<int> que;
  for(int i = 0; i < n; ++i) {
    if(deg[i] == 0) que.push_back(i);
  }

  while(que.size()) {
    int v = que.back(); que.pop_back();
    for(int s : g[v]) {
      if(--deg[s] == 0) que.push_back(s);
    }
  }

  for(int i = 0; i < n; ++i) {
    if(deg[i] != 0) {
      cout << -1 << endl;
      exit(0);
    }
  }

  int ans = 0; string res;
  for(int i = 0; i < n; ++i) {
    if(!markup[i] && !markdown[i]) ans++, res += 'A'; 
    else res += 'E';
    up(i), down(i);
  }

  cout << ans << endl << res << endl;

  return 0;
}