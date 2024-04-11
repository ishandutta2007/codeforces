#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
int const N = 777777;
int const INF = 1 << 30;
int a[N], was[N], dpl[N], dpr[N], color[N], crs[N], lens[N], ts[N];
int cn;
vector<int> edges[N], redges[N];
vector<int> cedges[N];
int cts;
int fr;
char sss[N];

struct Node {
  Node * link[26];
  int id;
  Node() {
    for (int i = 0; i < 26; i++) link[i] = 0;
    id = -1;
  }
};

Node * root;

void dfs(int v) {
  was[v] = true;
  for (int & to : edges[v]) {
    if (!was[to]) dfs(to);
  }
  ts[cts++] = v;
}

void paint(int v, int c) {
  color[v] = c;
  for (int & to : redges[v]) {
    if (color[to] < 0) {
      paint(to, c);
    }
  }
}

int add(string const & s) {
  Node * v = root;
  int rc = 0;
  int len = 0;
  for (char const & ch : s) {
    int c = ch - 'a';
    if (c < 0 || c >= 26) c = c - 'A' + 'a';
    if (!v->link[c]) {
      v->link[c] = new Node();
    }
    v = v->link[c];
    ++len;
    if (c == 'r' - 'a') ++rc;
  }
  if (v->id < 0) {
    v->id = cn++;
    crs[cn - 1] = rc;
    lens[cn - 1] = len;
  }
  return v->id;
}

int main() {
  int n;
  scanf("%d", &n);
  fr = 1;
  cn = 0;
  root = new Node();
  for (int i = 0; i < n; i++) {
    scanf("%s", sss);
    string str(sss);
    a[i] = add(str);
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%s", sss);
    string str1(sss);
    int from = add(str1);
    scanf("%s", sss);
    string str2(sss);
    int to = add(str2);
    edges[from].push_back(to);
    redges[to].push_back(from);
  }
  for (int i = 0; i < cn; i++) color[i] = -1;
  cts = 0;
  for (int i = 0; i < cn; i++) if (!was[i]) dfs(i);
  int cc = 0;
  for (int it = cn - 1; it >= 0; it--) {
    int i = ts[it];
    if (color[i] < 0) {
      paint(i, cc);
      ++cc;
    }
  }
  for (int i = 0; i < cc; i++) {
    dpr[i] = INF;
    dpl[i] = INF;
  }
  for (int i = 0; i < cn; i++) {
    if (dpr[color[i]] > crs[i] || (dpr[color[i]] == crs[i] && dpl[color[i]] > lens[i])) {
      dpr[color[i]] = crs[i];
      dpl[color[i]] = lens[i];
    }
  }
  for (int i = 0; i < cn; i++) {
    for (int & j : edges[i]) {
      cedges[color[i]].push_back(color[j]);
    }
  }
  for (int i = cc - 1; i >= 0; i--) {
    for (int & to : cedges[i]) {
      if (dpr[to] < dpr[i] || (dpr[to] == dpr[i] && dpl[to] < dpl[i])) {
        dpr[i] = dpr[to];
        dpl[i] = dpl[to];
      }
    }
  }
  int ansr = 0;
  long long ansl = 0;
  for (int i = 0; i < n; i++) {
    ansr += dpr[color[a[i]]];
    ansl += dpl[color[a[i]]];
  }
  printf("%d %I64d\n", ansr, ansl);
}