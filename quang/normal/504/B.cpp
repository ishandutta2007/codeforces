#include <bits/stdc++.h>

#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 200100;

int n;

struct BIT {
  int tree[N];
  void Reset() {
    memset(tree, 0, sizeof tree);
  }
  void Set(int x, int val) {
    if (x)
      while (x < n) {
        tree[x] += val;
        x += (x & -x);
      }
    else tree[0] += val;
  }
  int Get(int x) {
    int ans = 0;
    while(x) {
      ans += tree[x];
      x -= (x & -x);
    }
    ans += tree[0];
    return ans;
  }
};

int a[N], b[N], OrdA[N], OrdB[N], Ordres[N];

void Chuanbi(int c[], int Ord[]) {
  BIT t;
  t.Reset();
  for (int i = 0; i < n; i++) t.Set(i, 1);
  for (int i = 1; i <= n; i++) {
    Ord[i] = t.Get(c[i]) - 1;
    t.Set(c[i], -1);
  }
}

void Plus() {
  int m = 0;
  for (int i = n; i; i--) {
    Ordres[i] = OrdA[i] + OrdB[i] + m;
    if (Ordres[i] >= n - i + 1) {
      Ordres[i] -= n - i + 1;
      m = 1;
    } else m = 0;
  }
}

void Gores() {
  BIT t;
  t.Reset();
  for (int i = 0; i < n; i++) t.Set(i, 1);
  for (int i = 1; i <= n; i++) {
    int l = -1, r = n;
    while (r - l > 1) {
      int m = (l + r) / 2;
      int sl = t.Get(m);
      if (sl - 1 >= Ordres[i]) r = m;
      else l = m;
    }
    t.Set(r, -1);
    cout << r << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  Chuanbi(a, OrdA);
  Chuanbi(b, OrdB);
  Plus();
  Gores();
  return 0;
}