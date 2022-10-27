#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100005, inf = 1 << 29;
int n, q;
char a[N];

int tra[3][3] = {{1, 0, 0}, {inf, 0, 0}, {inf, inf, 0}};
int trb[3][3] = {{0, 0, 0}, {inf, 1, 0}, {inf, inf, 0}};
int trc[3][3] = {{0, 0, 0}, {inf, 0, 0}, {inf, inf, 1}};

namespace sgt {
int tr[N << 2][3][3], p[N];

void update(int i) {
  memset(tr[i], 0x3f, sizeof tr[i]);
  for (int j = 0; j < 3; j++)
    for (int k = j; k < 3; k++)
      for (int l = k; l < 3; l++)
        tr[i][j][l] = min(tr[i][j][l], tr[i << 1][j][k] + tr[i << 1 | 1][k][l]);
}

void build(int i, int l, int r) {
  if (l == r) {
    p[l] = i;
    if (a[l] == 'a')
      memcpy(tr[i], tra, sizeof tra);
    if (a[l] == 'b')
      memcpy(tr[i], trb, sizeof trb);
    if (a[l] == 'c')
      memcpy(tr[i], trc, sizeof trc);
    return;
  }

  int mid = (l + r) >> 1;
  build(i << 1, l, mid), build(i << 1 | 1, mid + 1, r);
  update(i);
}

void modify(int x, char v) {
  int i = p[x];
  if (v == 'a')
    memcpy(tr[i], tra, sizeof tra);
  if (v == 'b')
    memcpy(tr[i], trb, sizeof trb);
  if (v == 'c')
    memcpy(tr[i], trc, sizeof trc);

  while (i >>= 1)
    update(i);
}
} // namespace sgt

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> q >> (a + 1);

  sgt::build(1, 1, n);

  while (q--) {
    int x;
    char c;
    cin >> x >> c;
    sgt::modify(x, c);

    cout << min({sgt::tr[1][0][0], sgt::tr[1][0][1], sgt::tr[1][0][2]}) << '\n';
  }
}