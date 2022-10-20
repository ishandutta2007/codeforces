#include <bits/stdc++.h>

using namespace std;

const int N = 100010, magic = 350;

int n, m, k;
int a[N];
int cnt1[N * 30], cnt2[N * 30];
long long cur = 0;
long long res[N];

struct query {
  int l, r, id;

  query(int l = 0, int r = 0, int id = 0) {
    this->l = l;
    this->r = r;
    this->id = id;
  }
} q[N];

bool cmp(query u, query v) {
  int xx = u.l / magic;
  int yy = v.l / magic;
  if (xx == yy) {
    return u.r < v.r;
  }
  return xx < yy;
}

int main() {
 // freopen("input.txt", "r", stdin);
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    a[i] ^= a[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &q[i].l, &q[i].r);
    q[i].id = i;
  }
  sort(q + 1, q + m + 1, cmp);
  int curl = q[1].l, curr = q[1].r;
  for (int i = q[1].l; i <= q[1].r; i++) {
    cnt1[a[i - 1]]++;
    cnt2[a[i]]++;
    cur += cnt1[a[i] ^ k];
  }
  res[q[1].id] = cur;
  for (int i = 2; i <= m; i++) {
    while (curl < q[i].l) {
      cur -= cnt2[a[curl - 1] ^ k];
      cnt2[a[curl]]--;
      cnt1[a[curl - 1]]--;
      curl++;
    }
    while (curl > q[i].l) {
      curl--;
      cnt2[a[curl]]++;
      cnt1[a[curl - 1]]++;
      cur += cnt2[a[curl - 1] ^ k];
    }
    while (curr > q[i].r) {
      cur -= cnt1[a[curr] ^ k];
      cnt1[a[curr - 1]]--;
      cnt2[a[curr]]--;
      curr--;
    }
    while (curr < q[i].r) {
      curr++;
      cnt1[a[curr - 1]]++;
      cnt2[a[curr]]++;
      cur += cnt1[a[curr] ^ k];
    }
    res[q[i].id] = cur;
  }
  for (int i = 1; i <= m; i++) {
    printf("%I64d\n", res[i]);
  }
//  freopen("input.txt", "w", stdout);
//  cout << 100000 << " " << 100000 << " " << rand() << endl;
//  for (int i = 1; i <= 100000; i++) {
//    cout << 1ll * rand() * rand() % 1000000 << " ";
//  }
//  cout << endl;
//  for (int i = 1; i <= 100000; i++) {
//    int l = 1ll * rand() * rand() % 100000 + 1;
//    int r = 1ll * rand() * rand() % 100000 + 1;
//    if (l > r) {
//      swap(l, r);
//    }
//    cout << l << " " << r << endl;
//  }
  return 0;
}