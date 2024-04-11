#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, q;
int son[N];
vector <int> a[N];
vector <int> belong[N];
set<int> capture[N];
int dead[N], res[N];
set<int> *s[N];

bool has(const vector <int> &u, int v) {
  return binary_search(u.begin(), u.end(), v);
}

void join(int u, int v) {
  for (int i : *s[v]) {
    int f = has(belong[u], i);
    if (f) {
      res[i]++;
      if (has(belong[v], i)) {
        dead[i] = 1;
      }
    } else {
      if (capture[u].find(i) == capture[u].end()) {
        if (s[u]->find(i) == s[u]->end()) {
          s[u]->insert(i);
        } else {
          s[u]->erase(s[u]->find(i));
          capture[u].insert(i);
          res[i]++;
        }
      }
    }
  }
}

void dfs(int u, int p) {
  son[u] = u;
  s[u] = new set<int> ();
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    if (s[son[u]]->size() < s[v]->size()) {
      son[u] = v;
    }
  }
  if (son[u] != u) {
    s[u] = s[son[u]];
  }
  for (int v : a[u]) {
    if (v == p || v == son[u]) {
      continue;
    }
    join(u, v);
  }
  for (int i : belong[u]) {
    if (s[u]->find(i) != s[u]->end()) {
      res[i]++;
      if (has(belong[son[u]], i)) {
        dead[i] = 1;
      }
    } else {
      s[u]->insert(i);
    }
  }
}

int main() {
 // freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int u;
      scanf("%d", &u);
      belong[u].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(belong[i].begin(), belong[i].end());
  }
  dfs(1, 0);
  for (int i = 1; i <= q; i++) {
    if (dead[i]) {
      printf("-1\n");
    } else {
      printf("%d\n", res[i]);
    }
  }
  return 0;
}