#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
int query(const vector<int> &indices) {
  assert((int)indices.size() == k);
  cout << "?";
  for (auto v : indices)
    cout << ' ' << v + 1;
  cout << endl;
  int ret;
  cin >> ret;
  return ret;
}

signed main(void) {
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  vector<int> par(n + 1, -1);

  queue<int> q;
  q.push(0);
  par[0] = 0;
  while (!q.empty()) {
    int nbImpairs = q.front();
    int nbPairs = n - nbImpairs;
    q.pop();

    for (int delta = -k; delta <= k; delta++) {
      int nbP = (delta + k) / 2;
      int nbI = (k - delta) / 2;
      if (nbImpairs < nbI or nbPairs < nbP)
        continue;
      if (abs(delta) % 2 != k % 2 or par[nbImpairs + delta] != -1)
        continue;
      par[nbImpairs + delta] = nbImpairs;
      q.push(nbImpairs + delta);
    }
  }
  if (par[n] == -1) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> path;
  int cur = n;
  while (cur) {
    int delta = cur - par[cur];
    cur = par[cur];
    path.push_back(delta);
  }
  reverse(path.begin(), path.end());

  vector<bool> parite(n);
  int ret = 0;
  for (auto delta : path) {
    vector<int> indices;
    int nbP = (delta + k) / 2;
    int nbI = (k - delta) / 2;
    assert(nbP + nbI == k);
    for (int i = 0; i < n; ++i) {
      if (parite[i] and nbI) {
        nbI--;
        parite[i] = !parite[i];
        indices.push_back(i);
      } else if (!parite[i] and nbP) {
        parite[i] = !parite[i];
        nbP--;
        indices.push_back(i);
      }
    }
    ret ^= query(indices);
  }
  cout << "! " << ret << endl;
}