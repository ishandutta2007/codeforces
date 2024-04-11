#include <bits/stdc++.h>

using namespace std;

const int N = 50010, magic = 500;

struct query {
  int u, v;
  char op;
};

int n, m, q;
int online[N];
int big[N], res[N];
query p[N * 5];
pair<int, int> b[N * 3];
set<pair<int, int> > S;
vector <pair<int, int > > a[N];

void add_friend(int u, int v) {
  if (big[u] == big[v]) {
    int pos = lower_bound(a[u].begin(), a[u].end(), make_pair(v, 0)) - a[u].begin();
    a[u][pos].second = 1;
    pos = lower_bound(a[v].begin(), a[v].end(), make_pair(u, 0)) - a[v].begin();
    a[v][pos].second = 1;
    return;
  }
  if (big[u] && !big[v]) {
    swap(u, v);
  }
  int pos = lower_bound(a[u].begin(), a[u].end(), make_pair(v, 0)) - a[u].begin();
  a[u][pos].second = 1;
  if (online[u]) {
    res[v]++;
  }
}

void del_friend(int u, int v) {
  if (big[u] == big[v]) {
    int pos = lower_bound(a[u].begin(), a[u].end(), make_pair(v, 0)) - a[u].begin();
    a[u][pos].second = 0;
    pos = lower_bound(a[v].begin(), a[v].end(), make_pair(u, 0)) - a[v].begin();
    a[v][pos].second = 0;
    return;
  }
  if (big[u] && !big[v]) {
    swap(u, v);
  }
  int pos = lower_bound(a[u].begin(), a[u].end(), make_pair(v, 0)) - a[u].begin();
  a[u][pos].second = 0;
  if (online[u]) {
    res[v]--;
  }
}

int getans(int u) {
  int ans = res[u];
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i].first;
    int f = a[u][i].second;
    if (!f || !online[v]) {
      continue;
    }
    ans++;
  }
  return ans;
}

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  scanf("%d %d %d", &n, &m, &q);
  int o;
  scanf("%d", &o);
  for (int i = 1; i <= o; i++) {
    int u;
    scanf("%d", &u);
    online[u] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u > v) {
      swap(u, v);
    }
    b[i] = make_pair(u, v);
    S.insert(make_pair(u, v));
    a[u].push_back(make_pair(v, 1));
    a[v].push_back(make_pair(u, 1));
  }
  for (int i = 1; i <= q; i++) {
    scanf("\n%c", &p[i].op);
    if(p[i].op == 'O' || p[i].op == 'F' || p[i].op == 'C') {
      scanf("%d", &p[i].u);
    } else {
      scanf("%d %d", &p[i].u, &p[i].v);
      if (p[i].u > p[i].v) {
        swap(p[i].u, p[i].v);
      }
      if (S.find(make_pair(p[i].u, p[i].v)) == S.end()) {
        S.insert(make_pair(p[i].u, p[i].v));
        a[p[i].u].push_back(make_pair(p[i].v, 0));
        a[p[i].v].push_back(make_pair(p[i].u, 0));
      }
    }
  }
  S.clear();
  for (int i = 1; i <= n; i++) {
    if (a[i].size() > magic) {
      big[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (big[i]) {
      vector <pair<int, int> > f;
      for (int j = 0; j < a[i].size(); j++) {
        if (big[a[i][j].first]) {
          f.push_back(a[i][j]);
        }
      }
      a[i].swap(f);
      f.clear();
    } else {
      if (!online[i]) {
        continue;
      }
      for (int j = 0; j < a[i].size(); j++) {
        int u = a[i][j].first;
        int is_friend = a[i][j].second;
        if (!big[u] || !is_friend) {
          continue;
        }
        res[u]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(a[i].begin(), a[i].end());
  }
  for (int i = 1; i <= q; i++) {
    if (p[i].op == 'O') {
      int u = p[i].u;
      online[u] = 1;
      if (big[u]) {
        continue;
      }
      for (int j = 0; j < a[u].size(); j++) {
        int v = a[u][j].first;
        int f = a[u][j].second;
        if (!f || !big[v]) {
          continue;
        }
        res[v]++;
      }
    }
    if (p[i].op == 'F') {
      int u = p[i].u;
      online[u] = 0;
      if (big[u]) {
        continue;
      }
      for (int j = 0; j < a[u].size(); j++) {
        int v = a[u][j].first;
        int f = a[u][j].second;
        if (!f || !big[v]) {
          continue;
        }
        res[v]--;
      }
    }
    if (p[i].op == 'A') {
      int u = p[i].u, v = p[i].v;
      add_friend(u, v);
    }
    if (p[i].op == 'D') {
      del_friend(p[i].u, p[i].v);
    }
    if (p[i].op == 'C') {
      printf("%d\n", getans(p[i].u));
    }
  }
  return 0;
}