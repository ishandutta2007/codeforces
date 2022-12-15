#include <bits/stdc++.h>
#define int long long
using namespace std;

map<pair<int, int>, int> hshAngle;
vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> sol;
vector<bool> seen;
vector<int> tin;
int curTime;
int nbAngles;

int getHash(const pair<int, int> angle) {
  if (!hshAngle.count(angle)) {
    hshAngle[angle] = nbAngles++;
    adj.push_back({});
  }
  return hshAngle[angle];
}

int dfs(int u) {
  tin[u] = curTime++;
  seen[u] = true;
  vector<int> restants;
  for (auto [v, id] : adj[u]) {
    if (!seen[v]) {
      int r = dfs(v);
      if (r == -1)
        restants.push_back(id);
      else
        sol.emplace_back(r, id);
    } else if (tin[v] > tin[u]) {
      restants.push_back(id);
    }
  }

  while (restants.size() >= 2) {
    int i = restants.back();
    restants.pop_back();
    int j = restants.back();
    restants.pop_back();
    sol.emplace_back(i, j);
  }
  return restants.empty() ? -1 : restants.front();
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbPoints;
  cin >> nbPoints;
  for (int i = 0; i < nbPoints; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int p1 = d * (a + b), q1 = c * b, p2 = a * d, q2 = b * (c + d);
    int g1 = gcd(p1, q1), g2 = gcd(p2, q2);

    int u = getHash({p1 / g1, q1 / g1});
    int v = getHash({p2 / g2, q2 / g2});
    adj[u].emplace_back(v, i);
    adj[v].emplace_back(u, i);
  }
  tin.resize(nbAngles);
  seen.assign(nbAngles, false);
  for (int i = 0; i < nbAngles; ++i)
    if (!seen[i])
      dfs(i);

  cout << sol.size() << endl;
  for (auto [i, j] : sol)
    cout << i + 1 << ' ' << j + 1 << '\n';
}