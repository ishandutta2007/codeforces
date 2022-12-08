#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int N = 250010;

int unite(int x, int y) {
  return x ? x : y;
}

struct Node {
  int v, s, revs;
  union {
    struct { Node *ls, *rs; };
    Node* ch[2];
  };
  bool rev;
  Node *prt, *pth;

  bool rel() const { return this == prt->rs; }

  int get(bool f) const { return (rev ^ f) ? revs : s; }

  void pd() {
    if (rev) {
      swap(ls, rs);
      swap(s, revs);
      for (int i = 0; i < 2; ++i)
        if (ch[i])
          ch[i]->rev ^= true;
      rev = false;
    }
  }

  void upd() {
    revs = s = v;
    if (ls) {
      s = unite(ls->get(false), s);
      revs = unite(revs, ls->get(true));
    }
    if (rs) {
      s = unite(s, rs->get(false));
      revs = unite(rs->get(true), revs);
    }
  }

  void rot() {
    if (prt->prt)
      prt->prt->pd();
    prt->pd();
    pd();
    swap(pth, prt->pth);
    bool f = rel();
    Node* p = prt;
    if (prt->prt) prt->prt->ch[prt->rel()] = this;
    prt = prt->prt;
    p->ch[f] = ch[!f];
    if (ch[!f]) ch[!f]->prt = p;
    p->prt = this;
    ch[!f] = p;
    p->upd();
    upd();
  }

  void spl(Node* goal = NULL) {
    while (prt != goal) {
      if (prt->prt == goal)
        return rot();
      prt->prt->pd();
      prt->pd();
      if (rel() == prt->rel()) {
        prt->rot();
        rot();
      } else {
        rot();
        rot();
      }
    }
  }

  void expose() {
    spl();
    pd();
    if (rs) {
      rs->pth = this;
      rs->prt = NULL;
      rs = NULL;
      upd();
    }
  }

  bool splice() {
    spl();
    if (!pth)
      return false;
    pth->expose();
    pth->rs = this;
    prt = pth;
    pth = NULL;
    prt->upd();
    return true;
  }

  void access() {
    expose();
    while (splice());
  }

  void evert() {
    access();
    rev ^= true;
  }
};

int query(Node* x, Node* y) {
  x->evert();
  y->access();
  return y->get(false);
}

void link(Node* x, Node* y) {
  x->evert();
  x->pth = y;
}

void cut(Node* x, Node* y) {
  x->evert();
  y->access();
  x->expose();
  y->pth = NULL;
}

int n;
int u2[N], v2[N], deg[N];
vector<int> t1[N];
Node pool[N * 2];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int rep = 1; rep < n; ++rep) {
    int u, v;
    scanf("%d%d", &u, &v);
    t1[u].push_back(v);
    t1[v].push_back(u);
    ++deg[u]; ++deg[v];
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u2[i], &v2[i]);
    pool[n + i].v = i;
    pool[n + i].upd();
    link(pool + u2[i], pool + n + i);
    link(pool + v2[i], pool + n + i);
  }
  printf("%d\n", n - 1);
  queue<int> q;
  for (int i = 1; i <= n; ++i) if (deg[i] == 1) q.push(i);
  for (int rep = 1; rep < n; ++rep) {
    int u = q.front(); q.pop();
    deg[u] = 0;
    int v = 0;
    for (int x : t1[u])
      if (deg[x]) {
        v = x;
        break;
      }
    if (--deg[v] == 1)
      q.push(v);
    printf("%d %d ", u, v);
    int id = query(pool + u, pool + v);
    printf("%d %d\n", u2[id], v2[id]);
    cut(pool + u2[id], pool + n + id);
    cut(pool + v2[id], pool + n + id);
    link(pool + u, pool + v);
//    cerr << "link " << u2[id] << ' ' << v2[id] << '\n';

  /*  for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        cerr << i << ' ' << j << " = " << query(pool + i, pool + j) << ' ' << u2[query(pool + i, pool + j)] << ' ' << v2[query(pool + i, pool + j)] << '\n';
    cerr << "--------------\n";*/
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}