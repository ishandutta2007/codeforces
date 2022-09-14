#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 1 << 20;
ll tr[2][N * 2], m[2][N * 2], qp[N], qd[N], ts[N * 2];

void push(int t, int v) {
  if (v < N) {
    m[t][v * 2] += m[t][v];
    m[t][v * 2 + 1] += m[t][v];
  }
  tr[t][v] += m[t][v];
  m[t][v] = 0;
}

void rel(int t, int v) {
  tr[t][v] = max(tr[t][v * 2], tr[t][v * 2 + 1]);
}

void add(int t, int cl, int cr, ll d, int v=1, int l=0, int r=N) {
  if (r <= cl || cr <= l) {
    push(t, v);
    return;
  }
  if (cl <= l && r <= cr) {
    m[t][v] += d;
    push(t, v);
    return;
  }
  push(t, v);
  add(t, cl, cr, d, v * 2, l, (l + r) / 2);
  add(t, cl, cr, d, v * 2 + 1, (l + r) / 2, r);
  rel(t, v);
}

ll getm(int t, int cl, int cr, int v=1, int l=0, int r=N) {
  push(t, v);
  if (cr <= l || r <= cl)
    return 0;
  if (cl <= l && r <= cr)
    return tr[t][v];
  return max(getm(t, cl, cr, v * 2, l, (l + r) / 2), getm(t, cl, cr, v * 2 + 1, (l + r) / 2, r));
}

ll getp(int t, int cl, int cr, ll d, int v=1, int l=0, int r=N) {
  push(t, v);
  if (cr <= l || r <= cl || tr[t][v] < d)
    return -1;
  if (r - l == 1)
    return l;
  ll x = getp(t, cl, cr, d, v * 2, l, (l + r) / 2);
  if (x != -1)
    return x;
  return getp(t, cl, cr, d, v * 2 + 1, (l + r) / 2, r);
}

void adds(int v, ll d) {
  for (int i = N + v; i; i /= 2)
    ts[i] += d;
}

ll sums(int cl, int cr, int v=1, int l=0, int r=N) {
  if (cr <= l || r <= cl)
    return 0;
  if (cl <= l && r <= cr)
    return ts[v];
  return sums(cl, cr, v * 2, l, (l + r) / 2) + sums(cl, cr, v * 2 + 1, (l + r) / 2, r);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q, p, d;
  cin >> q;
  char c;
  rep(z, q) {
    cin >> c >> p;
    if (c == '+') {
      cin >> d;
      qp[z] = p;
      qd[z] = d;
      add(0, p, p + 1, p);
      add(0, 0, p + 1, d);
      add(1, p, p + 1, p);
      add(1, p + 1, N, -d);
      adds(p, d);
    } else if (c == '-') {
      d = qd[p - 1];
      p = qp[p - 1];
      add(0, p, p + 1, -p);
      add(0, 0, p + 1, -d);
      add(1, p, p + 1, -p);
      add(1, p + 1, N, d);
      adds(p, -d);
    } else {
      ll s2 = sums(p + 1, N);
      ll pm = getm(0, 0, p + 1) - s2;
      cout << max(pm - p, 0ll) << '\n';
    }
  }

}