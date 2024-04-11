#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1025;
const int alpha = ('n' - 'a') + 1;

struct Aho_Corasick{
  int count_node;
  int value[maxn];
  int nxt[maxn][alpha];
  int f[maxn];
  int trie[maxn][alpha];
  vector<int> order;

  Aho_Corasick() {
    for(int i = 0; i < alpha; ++i) {
      trie[0][i] = ++count_node;
    }
  }

  int add(string s, int v) {
    int node = 0;
    for(auto c : s) {
      c -= 'a';
      if(trie[node][c] == 0) trie[node][c] = ++count_node;
      node = trie[node][c];
    }
    value[node] += v;

    return node;
  }

  void process() {
    queue<int> bfs; bfs.push(0);
    while(!bfs.empty()) {
      int v = bfs.front(); bfs.pop();
      order.push_back(v);
      for(int i = 0; i < alpha; ++i) {
        int t = trie[v][i];
        if(t == 0) continue;
        bfs.push(t);
        if(v == 0) continue;
        int cur = f[v];
        while(trie[cur][i] == 0) cur = f[cur];
        f[t] = trie[cur][i];
      }
      for(int j = 0; j < alpha; ++j) {
        if(trie[v][j] == 0) nxt[v][j] = nxt[f[v]][j];
        else nxt[v][j] = trie[v][j];
      }
      value[v] += value[f[v]];
    }
  }

  int go(int i, int j) {
    return nxt[i][j];
  }

  int getVal(int i) {
    return value[i];
  }
}aho;

int n, m;
int f[1 << alpha][maxn];
int cst[maxn][alpha + 5];
int jump[maxn][alpha + 5];


main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> m;
  while(m--) {
    string s; int v;
    cin >> s >> v;
    aho.add(s, v);
  }

  aho.process();

  string s; cin >> s;
  vector<int> pos;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == '?') pos.push_back(i);
  }
  pos.push_back(s.size());

  int n = aho.count_node + 1;
  for(int j = 0; j < n; ++j) {
    int last = 0;
    for(int i = 0; i < pos.size(); ++i) {
      int cur = j, p = pos[i];
      for(int t = last; t < p; ++t) {
        cur = aho.go(cur, s[t] - 'a');
        cst[j][i] += aho.getVal(cur);
      }
      jump[j][i] = cur;
      last = p + 1;
    }
  }

  memset(f, -60, sizeof f);

  f[0][jump[0][0]] = cst[0][0];
  int ans = -1e18;


  int q = pos.size() - 1;
  for(int mask = 0; mask < (1 << alpha); ++mask) {
    int c = __builtin_popcount(mask);
    if(c == q) {
      for(int node = 0; node < n; ++node) {
        ans = max(ans, f[mask][node]);
      }
      continue;
    }
    for(int i = 0; i < alpha; ++i) {
      if(mask & (1 << i)) continue;
      int newmask = mask ^ (1 << i);
      for(int node = 0; node < n; ++node) {
        int newnode = jump[aho.go(node, i)][c + 1];
        int newcost = f[mask][node] + aho.getVal(aho.go(node, i)) + cst[aho.go(node, i)][c + 1];
        f[newmask][newnode] = max(f[newmask][newnode], newcost);
      }
    }
  }

  cout << ans << endl;

  return 0;
}