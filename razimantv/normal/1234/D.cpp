#include <iostream>
#include <string>

const int base = 1 << 17;
int segtree[base << 1];

void update(int pos, int bit) {
  pos += base;
  segtree[pos] ^= (1 << bit);
  for (pos >>= 1; pos; pos >>= 1) {
    segtree[pos] = segtree[pos << 1] | segtree[(pos << 1) | 1];
  }
}

int query(int node, int l, int r, int L, int R) {
  if (l == L and r == R) return segtree[node];
  int M = (L + R) >> 1;
  if (r <= M)
    return query(node << 1, l, r, L, M);
  else if (l > M)
    return query((node << 1) | 1, l, r, M + 1, R);
  else
    return query(node << 1, l, M, L, M) |
           query((node << 1) | 1, M + 1, r, M + 1, R);
}

int main() {
  std::string s;
  std::cin >> s;

  for (int i = 0; i < s.size(); ++i) {
    update(i, s[i] - 'a');
  }

  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int type;
    std::cin >> type;
    if (type == 1) {
      int pos;
      char val;
      std::cin >> pos >> val;
      --pos;
      update(pos, s[pos] - 'a');
      s[pos] = val;
      update(pos, s[pos] - 'a');
    } else {
      int l, r;
      std::cin >> l >> r;
      std::cout << __builtin_popcount(query(1, l - 1, r - 1, 0, base - 1))
                << std::endl;
    }
  }
  return 0;
}