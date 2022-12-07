#include <bits/stdc++.h>
#define next D7sus4add9

using namespace std;

const int N = 500050;

int n, cnt;
int idx[N * 5];
int ans[N];
int next[N];
int deg[N * 5];
list < int > g[N * 5];

#define mid ((l + r) >> 1)

void build(int x, int l, int r) {
  idx[x] = ++cnt;
  if(l == r) {
    ++deg[r];
    g[idx[x]].push_back(r);
    return;
  }
  build(x + x, l, mid);
  build(x + x + 1, mid + 1, r);

  ++deg[idx[x + x]];
  ++deg[idx[x + x + 1]];

  g[idx[x]].push_back(idx[x + x]);
  g[idx[x]].push_back(idx[x + x + 1]);
}

void addEdge(int x, int l, int r, int u, int v, int k) {
  if(u > v) return;
  if(l > v || r < u) return;
  if(l >= u && r <= v) {
    ++deg[idx[x]];
    g[k].push_back(idx[x]);
    return;
  }
  addEdge(x + x, l, mid, u, v, k);
  addEdge(x + x + 1, mid + 1, r, u, v, k);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int T; cin >> T;

  while(T--) {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> next[i];

    cnt = n;
    build(1, 1, n);


    for(int i = 1; i <= n; ++i) {
      if(next[i] == -1) continue;
      if(next[i] <= n) {
        g[next[i]].push_back(i);
        ++deg[i];
      }
      addEdge(1, 1, n, i + 1, next[i] - 1, i);
    }

    list < int > qu;
    for(int i = 1; i <= cnt; ++i) {
      if(deg[i] == 0) {
        qu.push_back(i);
      }
    }

    int val = n, cntQu = 0;

    while(!qu.empty()) {
      int x = qu.front(); qu.pop_front();
      ++cntQu;
      if(x <= n) {
        ans[x] = val--;
      }
      for(int y : g[x]) {
        if(--deg[y] == 0) qu.push_back(y);
      }
    }

    if(cntQu < cnt) {
      cout << -1 << '\n';
    }
    else {
      for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
      cout << '\n';
    } 
    for(int i = 1; i <= cnt; ++i) g[i].clear(), deg[i] = 0;
  }

  return 0;
}