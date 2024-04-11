#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 100;
int wantedHeight[MAXN];
int maxCut, nbBamboo;

vector<int> split(int x) {
  vector<int> possibles;
  for (int i(1); i * i <= x; ++i) {
    possibles.push_back(x / i);
    possibles.push_back(i);
  }
  vector<int> splitPoints;
  for (auto v : possibles) {
    int lo = (x + 1 + v) / (v + 1);
    if (x / lo == v)
      splitPoints.push_back(lo);
  }
  splitPoints.push_back(x + 1);
  return splitPoints;
}

int calcCost(int x) {
  int cost = 0;
  for (int iBamboo = 0; iBamboo < nbBamboo; ++iBamboo) {
    int cur = x - wantedHeight[iBamboo] % x;
    if (cur == x)
      cur = 0;
    cost += cur;
  }
  return cost;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> nbBamboo >> maxCut;
  for (int iBamboo = 0; iBamboo < nbBamboo; ++iBamboo) {
    cin >> wantedHeight[iBamboo];
  }
  vector<int> splits;
  for (int iBamboo = 0; iBamboo < nbBamboo; ++iBamboo) {
    auto vec = split(wantedHeight[iBamboo]);
    for (auto v : vec)
      splits.push_back(v);
    for (int d(1); d * d <= wantedHeight[iBamboo]; ++d)
      if (wantedHeight[iBamboo] % d == 0) {
        splits.push_back(d);
        splits.push_back(wantedHeight[iBamboo] / d);
      }
  }
  sort(splits.begin(), splits.end());
  splits.resize(unique(splits.begin(), splits.end()) - splits.begin());

  int bst = -1;
  for (auto d : splits)
    if (calcCost(d) <= maxCut)
      bst = max(bst, d);

  for (int i(0); i < (int)splits.size(); ++i) {
    int lo = splits[i] + 1;
    int up = (i + 1 == (int)splits.size() ? 1e18 : splits[i + 1] - 1);
    if (lo > up)
      continue;

    int a = 0, b = 0;
    for (int iBamboo = 0; iBamboo < nbBamboo; ++iBamboo) {
      a += 1 + wantedHeight[iBamboo] / lo;
      b -= wantedHeight[iBamboo];
    }
    int d = (maxCut - b) / a;
    if (d > up)
      d = up;
    if (d < lo)
      continue;
    bst = max(bst, d);
  }
  cout << bst << endl;
}