#include <algorithm>
#include <bits/extc++.h>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long i64;

const int N = 200005;
int nw;
map<i64, vector<pair<int, int>>> pt;
__gnu_pbds::gp_hash_table<int, int> f[300005];

int gcd(int n, int m) { return !m ? n : gcd(m, n % m); }

void insert(int x, int y) {
  nw++;
  i64 d = 1ll * x * x + 1ll * y * y;
  int z = gcd(x, y);
  f[x / z][y / z]++;

  for (auto tp : pt[d]) {
    int tx = tp.first, ty = tp.second;
    tx += x, ty += y;
    int z = gcd(tx, ty);
    f[tx / z][ty / z] += 2;
  }
  pt[d].push_back(make_pair(x, y));
}

void erase(int x, int y) {
  nw--;
  i64 d = 1ll * x * x + 1ll * y * y;
  int z = gcd(x, y);
  f[x / z][y / z]--;

  pt[d].erase(find(pt[d].begin(), pt[d].end(), make_pair(x, y)));
  for (auto tp : pt[d]) {
    int tx = tp.first, ty = tp.second;
    tx += x, ty += y;
    int z = gcd(tx, ty);
    f[tx / z][ty / z] -= 2;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int q;
  cin >> q;

  while (q--) {
    int op, x, y;
    cin >> op >> x >> y;

    if (op == 1)
      insert(x, y);
    if (op == 2)
      erase(x, y);
    if (op == 3) {
      int d = gcd(x, y);
      cout << nw - f[x / d][y / d] << '\n';
    }
  }
}