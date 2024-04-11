#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100005;
int t, n;
struct node {
  int v, id;
  bool operator<(const node &j) const { return v != j.v ? v < j.v : id < j.id; }
} a[N];
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].v), a[i].id = i;
    sort(a + 1, a + n + 1);
    long long ans = 0, tp = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i].v != a[i - 1].v) tp = 0;
      ans += tp * (n - a[i].id + 1), tp += a[i].id;
    }
    cout << ans << endl;
  }
}