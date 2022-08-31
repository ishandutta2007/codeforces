// Bad practice, just doing this for competitive programming!
#include <bits/stdc++.h>
using namespace std;

const int base{1 << 18};
struct node {
  int sum;
  char set, flip;
  node() : sum(0), set(-1), flip(0) {}
  node(int sum, char set, char flip) : sum(sum), set(set), flip(flip) {}
} seg[base << 1];

void lazyflip(int node, int cnt) {
  auto& [sum, set, flip] = seg[node];
  (set != -1 ? set : flip) ^= 1;
  sum = cnt - sum;
}

void lazyset(int node, char val, int cnt) { seg[node] = {val * cnt, val, 0}; }

void propagate(int node, int cnt) {
  if(node >= base) return;
  auto& [sum, set, flip] = seg[node];
  if(set == -1) {
    if (flip) lazyflip(node << 1, cnt / 2), lazyflip((node << 1) | 1, cnt / 2);
  } else lazyset(node<<1, set, cnt/2), lazyset((node<<1)|1, set, cnt/2);
  set = -1, flip = 0;
}

void assign(int node, int L, int R, int l, int r, int val) {
  if (L == l and R == r) {
    seg[node] = {(R - L + 1) * val, (char) val, 0};
    return;
  }
  propagate(node, R - L + 1);
  int M = (L + R) >> 1;
  if (r <= M) assign(node << 1, L, M, l, r, val);
  else if (l > M) assign((node << 1) | 1, M + 1, R, l, r, val);
  else {
    assign(node << 1, L, M, l, M, val);
    assign((node << 1) | 1, M + 1, R, M + 1, r, val);
  }
  seg[node].sum = seg[node << 1].sum + seg[(node << 1) | 1].sum;
}

void invert(int node, int L, int R, int l, int r) {
  auto& [sum, set, flip] = seg[node];
  if (L == l and R == r) {
    sum = R - L + 1 - sum;
    (set == -1 ? flip : set) ^= 1;
    return;
  }
  int cnt = R-L+1;
  propagate(node, cnt);
  int M = (L + R) >> 1;
  if (r <= M) invert(node << 1, L, M, l, r);
  else if (l > M) invert((node << 1) | 1, M + 1, R, l, r);
  else {
    invert(node << 1, L, M, l, M);
    invert((node << 1) | 1, M + 1, R, M + 1, r);
  }
  sum = seg[node << 1].sum + seg[(node << 1) | 1].sum;
}

long long first(int node, int cnt, map<int, long long>& inv) {
  if (node >= base) return inv[node - base];
  propagate(node, cnt);
  if (seg[node << 1].sum != cnt / 2) return first(node << 1, cnt / 2, inv);
  else return first((node << 1) | 1, cnt / 2, inv);
}

int main() {
  int N;
  cin >> N;
  vector<tuple<int, long long, long long>> tlr(N);
  set<long long> coordset{1};

  for (auto& [t, l, r] : tlr) {
    cin >> t >> l >> r;
    coordset.insert(l);
    coordset.insert(r + 1);
  }

  map<long long, int> compress;
  map<int, long long> inv;
  int NMAX = 0;
  for (auto x : coordset) inv[compress[x] = NMAX++] = x;

  for (auto& [t, l, r] : tlr) {
    l = compress[l];
    r = compress[r + 1] - 1;
  }

  for(auto& [t, l, r]: tlr) {
    if (t == 3) invert(1, 0, base - 1, l, r);
    else assign(1, 0, base - 1, l, r, 2 - t);
    cout << first(1, base, inv) << "\n";
  }
  return 0;
}