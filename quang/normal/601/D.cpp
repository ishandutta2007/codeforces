#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
vector <int> a[N];
int c[N];
int res, way;
char s[N];

struct node {
  int sum;
  node* son[26];
  node() {
    sum = 0;
  }
};

node* null;
node* b[N];

node* newnode() {
  node* res = new node();
  for (int i = 0; i < 26; i++) {
    res->son[i] = null;
  }
  return res;
}

void go(node* u, node* v) {
  u->sum = 1;
  for (int i = 0; i < 26; i++) {
    if (v->son[i] == null) {
      continue;
    }
    if (u->son[i] == null) {
      u->son[i] = v->son[i];
    } else {
      go(u->son[i], v->son[i]);
    }
  }
  for (int i = 0; i < 26; i++) {
    u->sum += u->son[i]->sum;
  }
}

node* mergetree(node* u, node* v) {
  if (u->sum < v->sum) {
    swap(u, v);
  }
  go(u, v);
  return u;
}

void dfs(int u, int p) {
  b[u] = newnode();
  b[u]->sum = 1;
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    node* foo = newnode();
    foo->son[s[v] - 'a'] = b[v];
    foo->sum = b[v]->sum + 1;
    b[v] = foo;
    b[u] = mergetree(b[v], b[u]);
  }
  if (b[u]->sum + c[u] == res) {
    way++;
  }
  if (b[u]->sum + c[u] > res) {
    res = b[u]->sum + c[u];
    way = 1;
  }
}

int main() {
  null = new node();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", c + i);
  }
  if (n == 1) {
    printf("%d\n%d", c[1] + 1, 1);
    return 0;
  }
  scanf("%s", s + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, 0);
  printf("%d\n%d",res, way);
  return 0;
}