#include <bits/stdc++.h>
#define int long long
using namespace std;

struct RollbackUF {
  vector<int> e;
  vector<pair<int, int>> st;

  RollbackUF(int n) : e(n, -1) {}
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : find(e[x]); }
  int time() { return st.size(); }

  void rollback(int t) {
    for (int i = time(); i-- > t;)
      e[st[i].first] = st[i].second;
    st.resize(t);
  }

  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    st.push_back({a, e[a]});
    st.push_back({b, e[b]});
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

struct Edge {
  int a, b, w;
};
struct Node {
  Edge key;
  Node *l, *r;
  int delta;
  void prop() {
    key.w += delta;
    if (l)
      l->delta += delta;
    if (r)
      r->delta += delta;
    delta = 0;
  }

  Edge top() {
    prop();
    return key;
  }
};

Node *merge(Node *a, Node *b) {
  if (!a or !b)
    return a ?: b;
  a->prop(), b->prop();
  if (a->key.w > b->key.w)
    swap(a, b);
  swap(a->l, (a->r = merge(b, a->r)));
  return a;
}

void pop(Node *&a) {
  a->prop();
  a = merge(a->l, a->r);
}

int dmst(int n, int r, vector<Edge> &g) {
  RollbackUF uf(n);
  vector<Node *> heap(n);
  for (Edge e : g)
    heap[e.b] = merge(heap[e.b], new Node{e, nullptr, nullptr, 0});
  int res = 0;
  vector<int> seen(n, -1), path(n), par(n);
  seen[r] = r;
  vector<Edge> Q(n), in(n, {-1, -1, 0}), comp;
  deque<tuple<int, int, vector<Edge>>> cycs;
  for (int s = 0; s < n; ++s) {
    int u = s, qi = 0, w;
    while (seen[u] < 0) {
      if (!heap[u])
        return -1;
      Edge e = heap[u]->top();
      heap[u]->delta -= e.w, pop(heap[u]);
      Q[qi] = e, path[qi++] = u, seen[u] = s;
      res += e.w, u = uf.find(e.a);
      if (seen[u] == s) {
        Node *cyc = 0;
        int end = qi, time = uf.time();
        do
          cyc = merge(cyc, heap[w = path[--qi]]);
        while (uf.join(u, w));
        u = uf.find(u), heap[u] = cyc, seen[u] = -1;
        cycs.push_front({u, time, {&Q[qi], &Q[end]}});
      }
    }
    for (int i = 0; i < qi; ++i)
      in[uf.find(Q[i].b)] = Q[i];
  }

  return res;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbLig, nbCol;
  cin >> nbLig >> nbCol;

  auto convert = [&](int iLig, int iCol) { return iCol + nbCol * iLig; };

  vector<string> grid(nbLig);
  for (int iLig = 0; iLig < nbLig; ++iLig)
    cin >> grid[iLig];
  int source = nbLig * nbCol;
  vector<Edge> edges;
  vector<vector<int>> atCol(nbCol);
  for (int iCol = 0; iCol < nbCol; ++iCol) {
    int prev = -1;
    for (int iLig = 0; iLig < nbLig; ++iLig) {
      int curHash = convert(iLig, iCol);
      if (grid[iLig][iCol] != '#') {
        edges.push_back({source, curHash, 0});
        continue;
      }
      if (prev == -1)
        edges.push_back({source, curHash, 1});
      else {
        edges.push_back({prev, curHash, 0});
        if (grid[iLig - 1][iCol] == '#')
          edges.push_back({curHash, prev, 0});
      }
      atCol[iCol].push_back(iLig);
      prev = curHash;
    }
  }
  for (int iCol = 0; iCol < nbCol; ++iCol) {
    for (int iLig : atCol[iCol]) {
      if (iCol) {
        int id =
            lower_bound(atCol[iCol - 1].begin(), atCol[iCol - 1].end(), iLig) -
            atCol[iCol - 1].begin();
        if (id < (int)atCol[iCol - 1].size())
          edges.push_back(
              {convert(iLig, iCol), convert(atCol[iCol - 1][id], iCol - 1), 0});
      }
      if (iCol + 1 != nbCol) {
        int id =
            lower_bound(atCol[iCol + 1].begin(), atCol[iCol + 1].end(), iLig) -
            atCol[iCol + 1].begin();
        if (id < (int)atCol[iCol + 1].size())
          edges.push_back(
              {convert(iLig, iCol), convert(atCol[iCol + 1][id], iCol + 1), 0});
      }
    }
  }
  cout << dmst(nbLig * nbCol + 1, source, edges) << endl;
}