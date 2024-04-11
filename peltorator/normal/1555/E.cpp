#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = (1 << 24);
 
int tree[N];
int psh[N];
 
void push(int v, int l, int r) {
  psh[2 * v] += psh[v];
  psh[2 * v + 1] += psh[v];
  tree[2 * v] += psh[v];
  tree[2 * v + 1] += psh[v];
  psh[v] = 0;
}
 
void inc(int v, int l, int r, int ql, int qr, int val) {
  if (qr <= l || r <= ql) {
    return;
  }
  if (ql <= l && r <= qr) {
    tree[v] += val;
    psh[v] += val;
    return;
  }
  push(v, l, r);
  int mid = (r + l) / 2;
  inc(2 * v, l, mid, ql, qr, val);
  inc(2 * v + 1, mid, r, ql, qr, val);
  tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}
 
int main() {
  int n, m;
  cin >> n >> m;
  m--;
  vector<pair<int, pair<int, int>>> q(n);
  for (int i = 0; i < n; i++) {
    cin >> q[i].second.first >> q[i].second.second >> q[i].first;
  }
  sort(q.begin(), q.end());
  int ans = 1e9;
  for (int l = 0, r = 0; l < n; l++) {
    while (tree[1] == 0 && r < n) {
      inc(1, 0, m, q[r].second.first - 1, q[r].second.second - 1, 1);
      r++;
    }
    if (tree[1] == 0) {
      break;
    }
    ans = min(ans, q[r - 1].first - q[l].first);
    inc(1, 0, m, q[l].second.first - 1, q[l].second.second - 1, -1);
  }
  cout << ans << '\n';
}