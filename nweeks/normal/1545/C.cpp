#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

using ll = long long;
#define SZ(v) ((int)v.size())
struct Edge {
  int to;
  ll f, c;
};

struct Graph {
  vector<Edge> edges;
  vector<vector<int>> G;
  int s, t;
  Graph(int n, int s, int t) : edges(), G(n), s(s), t(t) {}

  void addEdge(int a, int b, ll c1, ll c2 = 0) // If not directed, take c2=c1
  {
    G[a].push_back(SZ(edges));
    edges.push_back(Edge{b, 0, c1});
    G[b].push_back(SZ(edges));
    edges.push_back(Edge{a, 0, c2});
  }
};

struct Dinic : public Graph {
  vector<int> dis, ptr;
  Dinic(int n, int s, int t) : Graph(n, s, t) {}

  ll dfs(ll v, ll maxF) {
    if (!maxF or v == t)
      return maxF;
    for (; ptr[v] < SZ(G[v]); ++ptr[v]) {
      int k = G[v][ptr[v]];
      Edge &ed = edges[k];
      if (ed.c > ed.f and dis[ed.to] == dis[v] + 1)
        if (ll df = dfs(ed.to, min(maxF, ed.c - ed.f))) {
          ed.f += df;
          edges[k ^ 1].f -= df;
          return df;
        }
    }
    return 0;
  }

  ll flow(void) {
    int N = SZ(G);
    ll f(0);
    while (1) {
      dis.assign(N, -1);
      queue<int> q;
      q.push(s);
      dis[s] = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t)
          break;
        for (auto k : G[u]) {
          Edge ed = edges[k];
          if (ed.c > ed.f and dis[ed.to] == -1) {
            dis[ed.to] = dis[u] + 1;
            q.push(ed.to);
          }
        }
      }
      if (dis[t] == -1)
        break;
      ptr.assign(N, 0);
      while (ll df = dfs(s, (1LL << 62)))
        f += df;
    }
    return f;
  }
};

// addVar creates new var, returns x, use x to access var, and ~x to access not
// var
struct twoSat {
  int nbSommets;
  vector<vector<int>> gr;
  vector<int> values; // 0 = false, 1 = true

  twoSat(int n = 0) : nbSommets(n), gr(2 * n) {}

  int addVar() {
    gr.emplace_back();
    gr.emplace_back();
    return nbSommets++;
  }

  void either(int f, int j) {
    f = max(2 * f, -1 - 2 * f);
    j = max(2 * j, -1 - 2 * j);
    gr[f].push_back(j ^ 1);
    gr[j].push_back(f ^ 1);
  }

  void setValue(int x) { either(x, x); }

  void atMostOne(const vector<int> &li) {
    if ((li).size() <= 1)
      return;
    int cur = ~li[0];
    for (int i = 2; i < (int)li.size(); ++i) {
      int nxt = addVar();
      either(cur, ~li[i]);
      either(cur, nxt);
      either(~li[i], nxt);
      cur = ~nxt;
    }
    either(cur, ~li[1]);
  }

  vector<int> val, comp, z;
  int time = 0;

  int dfs(int i) {
    int low = val[i] = ++time, x;
    z.push_back(i);
    for (int e : gr[i])
      if (!comp[e])
        low = min(low, val[e] ?: dfs(e));
    if (low == val[i])
      do {
        x = z.back();
        z.pop_back();
        comp[x] = low;
        if (values[x >> 1] == -1)
          values[x >> 1] = x & 1;
      } while (x != i);
    return val[i] = low;
  }

  bool solve() {
    values.assign(nbSommets, -1);
    val.assign(2 * nbSommets, 0);
    comp = val;
    for (int i = 0; i < 2 * nbSommets; ++i)
      if (!comp[i])
        dfs(i);
    for (int i = 0; i < nbSommets; ++i)
      if (comp[2 * i] == comp[2 * i + 1])
        return 0;
    return 1;
  }
};

void solve() {
  int lenPerms, nbPerms;
  cin >> lenPerms;
  nbPerms = lenPerms * 2;

  vector<vector<int>> perms(nbPerms);
  for (auto &v : perms) {
    v.resize(lenPerms);
    for (auto &w : v) {
      cin >> w;
      --w;
    }
  }

  vector<bool> alive(nbPerms, true);
  vector<int> latinSquare;
  vector<int> seen(lenPerms);

  for (int i = 0; i < lenPerms; ++i) {
    bool found = false;
    for (int iCol = 0; iCol < lenPerms; ++iCol) {
      seen.assign(lenPerms, -1);
      for (int iPerm = 0; iPerm < nbPerms; ++iPerm)
        if (alive[iPerm]) {
          if (seen[perms[iPerm][iCol]] == -2)
            continue;
          else if (seen[perms[iPerm][iCol]] != -1)
            seen[perms[iPerm][iCol]] = -2;
          else
            seen[perms[iPerm][iCol]] = iPerm;
        }
      for (int iVal = 0; iVal < lenPerms; ++iVal)
        if (seen[iVal] >= 0) {
          found = true;
          latinSquare.push_back(seen[iVal]);
          for (int iPerm = 0; iPerm < nbPerms; ++iPerm)
            if (alive[iPerm]) {
              bool bad = false;
              for (int j = 0; j < lenPerms; ++j)
                bad |= perms[iPerm][j] == perms[seen[iVal]][j];
              if (bad)
                alive[iPerm] = false;
            }
          break;
        }
      if (found)
        break;
    }
    if (found)
      continue;
    // exactly 2 each time
    twoSat ts(nbPerms);
    for (int iCol = 0; iCol < lenPerms; ++iCol) {
      seen.assign(lenPerms, -1);
      for (int iPerm = 0; iPerm < nbPerms; ++iPerm)
        if (alive[iPerm]) {
          int v = perms[iPerm][iCol];
          if (seen[v] != -1) {
            ts.either(~iPerm, ~seen[v]);
            ts.either(iPerm, seen[v]);
          }
          seen[v] = iPerm;
        }
    }

    assert(ts.solve());
    for (int i = 0; i < nbPerms; ++i)
      if (alive[i] and ts.values[i])
        latinSquare.push_back(i);
    break;
  }

  assert((int)latinSquare.size() == lenPerms);
  sort(latinSquare.begin(), latinSquare.end());
  vector<int> compLatin;
  for (int i = 0; i < nbPerms; ++i) {
    auto it = lower_bound(latinSquare.begin(), latinSquare.end(), i);
    if (it == latinSquare.end() or *it != i)
      compLatin.push_back(i);
  }
  assert((int)compLatin.size() == lenPerms);

  int s = nbPerms, t = s + 1;
  Dinic dic(nbPerms + 2, s, t);
  for (int i : latinSquare)
    dic.addEdge(s, i, 1);
  for (int i : compLatin)
    dic.addEdge(i, t, 1);
  for (int i : latinSquare)
    for (int j : compLatin) {
      bool bad = false;
      for (int k = 0; k < lenPerms; ++k)
        bad |= perms[i][k] == perms[j][k];
      if (bad)
        dic.addEdge(i, j, 1);
    }

  assert(dic.flow() == lenPerms);
  vector<int> other(nbPerms);

  vector<array<int, 2>> pairs;
  for (int i : latinSquare)
    for (int ed : dic.G[i])
      if (dic.edges[ed].f == 1) {
        pairs.push_back({i, dic.edges[ed].to});
        break;
      }
  assert((int)pairs.size() == lenPerms);
  set<vector<bool>> possibles;

  vector<vector<int>> toFlip(lenPerms);
  for (int i = 0; i < lenPerms; ++i)
    for (int j = 0; j < lenPerms; ++j)
      if (i != j) {
        bool bad = false;
        for (int k = 0; k < lenPerms; ++k)
          bad |= perms[pairs[i][1]][k] == perms[pairs[j][0]][k];
        if (bad)
          toFlip[i].push_back(j);
      }

  vector<vector<bool>> isBad(lenPerms, vector<bool>(lenPerms));
  for (int i = 0; i < lenPerms; ++i)
    for (int j = i + 1; j < lenPerms; ++j) {
      bool bad = false;
      for (int k = 0; k < lenPerms; ++k)
        bad |= perms[pairs[i][1]][k] == perms[pairs[j][1]][k];
      isBad[i][j] = isBad[j][i] = bad;
    }

  for (int flipStart = 0; flipStart < lenPerms; ++flipStart) {
    bool bad = false;
    vector<bool> flipped(lenPerms);
    queue<int> q;
    q.push(flipStart);
    flipped[flipStart] = true;
    while (!q.empty()) {
      int flipping = q.front();
      q.pop();
      for (int nxt : toFlip[flipping])
        if (!flipped[nxt]) {
          flipped[nxt] = true;
          q.push(nxt);
        }
    }
    for (int i = 0; i < lenPerms; ++i)
      for (int j = i + 1; j < lenPerms; ++j)
        if (flipped[i] and flipped[j] and isBad[i][j]) {
          bad = true;
          break;
        }
    if (!bad)
      possibles.insert(flipped);
  }
  for (int i : latinSquare)
    for (int j : latinSquare)
      if (i < j)
        for (int k = 0; k < lenPerms; ++k)
          assert(perms[i][k] != perms[j][k]);

  long long ret = 1;
  for (int i = 0; i < (int)possibles.size(); ++i)
    ret = ret * 2 % MOD;
  cout << ret << '\n';
  for (int i : latinSquare)
    cout << i + 1 << ' ';
  cout << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}