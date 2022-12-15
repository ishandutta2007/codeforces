#include <bits/stdc++.h>
#define int long long
using namespace std;

struct State {
  int id, rank, parity;

  State() { id = -1, rank = 1, parity = 0; }
};

struct rollbackDsu {
  vector<State> states;
  vector<tuple<int, State, int, State>> rollbacks;

  rollbackDsu(int n) : states(n) {
    for (int i = 0; i < n; ++i) {
      states[i].id = i;
    }
  }

  int find(int u) {
    if (states[u].id == u)
      return u;
    return find(states[u].id);
  }

  int disLeader(int u) {
    if (states[u].id == u)
      return 0;
    return disLeader(states[u].id) ^ states[u].parity;
  }

  bool merge(int u, int v) {
    int pu = find(u), pv = find(v);
    rollbacks.emplace_back(pu, states[pu], pv, states[pv]);
    if (states[pu].rank < states[pv].rank) {
      swap(u, v);
      swap(pu, pv);
    }
    int du = disLeader(u), dv = disLeader(v);
    if (pu == pv)
      return du != dv;

    states[pu].rank += states[pv].rank;
    states[pv].id = pu;
    states[pv].parity = du == dv;
    return true;
  }

  void rollback() {
    assert(!rollbacks.empty());
    auto [u, su, v, sv] = rollbacks.back();
    rollbacks.pop_back();
    states[u] = su, states[v] = sv;
  }
};

const int MAXN = 100000;

struct Update {
  int li, ri, u, v; // active in [li, ri)

  Update(int a, int b, int c, int d) : li(a), ri(b), u(c), v(d) {}
};

int nbSommets, nbRequetes;
rollbackDsu dsu(MAXN);
vector<int> sol;

void solve(int deb, int fin, bool isOk, vector<Update> &upd) {
  if (deb == fin)
    return;

  int cntAdded = 0;
  vector<Update> lft, rgt;
  int mil = (deb + fin) / 2;
  for (auto [li, ri, u, v] : upd) {
    if (li <= deb and ri >= fin) {
      isOk &= dsu.merge(u, v), cntAdded++;
    } else if (li >= mil)
      rgt.emplace_back(li, ri, u, v);
    else if (ri < mil)
      lft.emplace_back(li, ri, u, v);
    else {
      lft.emplace_back(li, ri, u, v);
      rgt.emplace_back(li, ri, u, v);
    }
  }

  if (deb + 1 == fin)
    sol[deb] = isOk;
  else {
    solve(deb, mil, isOk, lft);
    solve(mil, fin, isOk, rgt);
  }
  while (cntAdded-- > 0)
    dsu.rollback();
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> nbSommets >> nbRequetes;
  sol.resize(nbRequetes);

  map<pair<int, int>, int> timeSeen;
  vector<Update> updates;
  for (int iRequete = 0; iRequete < nbRequetes; ++iRequete) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (timeSeen.count({u, v})) {
      int t = timeSeen[{u, v}];
      timeSeen.erase({u, v});
      updates.push_back({t, iRequete, u, v});
    } else {
      timeSeen[{u, v}] = iRequete;
    }
  }
  for (auto [p, t] : timeSeen)
    updates.push_back({t, nbRequetes, p.first, p.second});
  solve(0, nbRequetes, 1, updates);
  for (int i = 0; i < nbRequetes; ++i) {
    cout << (sol[i] ? "YES" : "NO") << '\n';
  }
}