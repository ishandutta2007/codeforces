#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2020;

int n;
int cnt;
int child[MAXN];
int L[MAXN], R[MAXN];
int inv[MAXN];
int ans[MAXN];
int order[MAXN];
vector < int > g[MAXN];

void upd(int x, int delta, int bound) {
  for(int id = L[x]; id <= R[x]; ++id) {
    int v = inv[id];
    if(ans[v] >= bound) ans[v] += delta;
  }
}

int sz;
int a[MAXN];

int find(int x, int kth) {
  sz = 0;
  for(int id = L[x]; id <= R[x]; ++id) {
    int v = inv[id];
    a[++sz] = ans[v];
  }
  sort(a + 1, a + sz + 1);
  return a[kth];
}

void write(int x) {
  for(int id = L[x]; id <= R[x]; ++id) {
    int v = inv[id];
    cout << ans[v] << " ";
  }
  cout << endl;
}

void solve(int x) {

  L[x] = ++cnt;
  inv[cnt] = x;

  int temp = order[x];
  //cout << x << " " << order[x] << endl;
  for(int v : g[x]) {
    solve(v);
    upd(v, child[x], 0);
    child[x] += child[v];

    if(child[v] >= temp) {
      int val = find(v, temp) + 1;
      upd(v, 1, val);
      ans[x] = val;
      child[x]++;
      temp = 1e9;
    }
    else {
      temp -= child[v];
    }
  }

  if(temp <= n) {
    if(temp != 0) {
      cout << "NO";
      exit(0);
    }
    child[x]++;
    ans[x] = child[x];
  }
  R[x] = cnt;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    int p; cin >> p >> order[i];
    g[p].push_back(i);
  }

  solve(0);

  cout << "YES\n";
  for(int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }

  return 0;
}