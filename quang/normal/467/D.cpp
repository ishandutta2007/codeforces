#include <bits/stdc++.h>

using namespace std;

const int N = 200100, Base = 10007;

int m, n;
long long a[N];
pair <long long, long long> b[N];
string s;
vector <long long> ds;

vector <int> ke[N], Ke[N];
int root[N], low[N], num[N], used[N], cnt, st[N], top, Deg[N], bot;
pair<int, int> Val[N], dp[N];

map <long long, pair<int, int> > M;

long long Turn() {
  int CntR = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] += 'a' - 'A';
    }
    CntR += (s[i] == 'r');
  }
  long long code = 0;
  for (int i = 0; i < s.size(); i++) {
    code = code * Base + s[i] - 'a' + 1;
  }
  M[code] = make_pair(CntR, s.size());
  return code;
}

void DFS(int u) {
  low[u] = num[u] = ++cnt;
  st[top++] = u;
  for (int i = 0; i < ke[u].size(); i++) {
    int v = ke[u][i];
    if (!used[v]) {
      if (!num[v]) {
        DFS(v);
      }
      low[u] = min(low[u], low[v]);
    }
  }
  if (low[u] == num[u]) {
    Val[u] = M[ds[u]];
    int v;
    do {
      v = st[--top];
      root[v] = u;
      used[v] = 1;
      Val[u] = min(Val[u], M[ds[v]]);
    } while (v != u);
  }
}

void BuildSCC() {
  for (int i = 1; i <= n; i++) {
    int posu = lower_bound(ds.begin(), ds.end(), b[i].first) - ds.begin();
    int posv = lower_bound(ds.begin(), ds.end(), b[i].second) - ds.begin();
    ke[posu].push_back(posv);
  }
  for (int i = 0; i < ds.size(); i++) {
    if (!num[i]) {
      DFS(i);
    }
  }
  for (int u = 0; u < ds.size(); u++) {
    for (int j = 0; j < ke[u].size(); j++) {
      int v = ke[u][j];
      if (root[u] == root[v]) {
        continue;
      }
      Ke[root[v]].push_back(root[u]);
      Deg[root[u]]++;
    }
  }
  for (int i = 0; i < ds.size(); i++) {
    if (root[i] == i) {
      dp[i] = Val[i];
      if (!Deg[i]) {
        st[top++] = i;
      }
    }
  }
  while (bot < top) {
    int u = st[bot++];
    for (int i = 0; i < Ke[u].size(); i++) {
      int v = Ke[u][i];
      dp[v] = min(dp[v], dp[u]);
      Deg[v]--;
      if (!Deg[v]) {
        st[top++] = v;
      }
    }
  }
}

int main() {
  //freopen("D.inp", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> s;
    a[i] = Turn();
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    long long u = Turn();
    cin >> s;
    long long v = Turn();
    b[i] = make_pair(u, v);
    ds.push_back(u);
    ds.push_back(v);
  }
  sort(ds.begin(), ds.end());
  ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
  BuildSCC();
  long long res1 = 0, res2 = 0;
  for (int i = 1; i <= m; i++) {
    int pos = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin();
    if (pos >= ds.size() || a[i] != ds[pos]) {
      res1 += M[a[i]].first;
      res2 += M[a[i]].second;
    } else {
      int u = root[pos];
      res1 += dp[u].first;
      res2 += dp[u].second;
    }
  }
  cout << res1 << " " << res2;
  return 0;
}