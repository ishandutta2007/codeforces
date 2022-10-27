#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
const int N = 1000005;
int n, q, a[150005], x, y;
int mp[1000005], bg[150005];
bool ok[1000005];
vector<int> d[1000005];
unordered_set<int> f[150005];
namespace task0 {
int fa[150005];
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
inline void merge(int x, int y) {fa[find(x)] = find(y);}
void build() {for (int i = 1; i <= n; i++) fa[i] = i;}
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) scanf("%d", a + i), mp[a[i]] = i;
  task0::build();
  for (int i = 2; i <= 1000000; i++) {
    if (ok[i]) continue;
    int x = mp[i];
    for (int j = 2 * i; j <= 1000000; j += i) {
      ok[j] = 1;
      if (mp[j]) {
        if (!x) x = mp[j];
        else task0::merge(mp[j], x);
      }
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (ok[i]) continue;
    int x = 0;
    for (int j = i; j <= 1000000; j += i) {
      if (mp[j]) {
        x = task0::find(mp[j]);
        break;
      }
    }
    if (x) {
      for (int j = i; j <= 1000001; j += i)
        if (mp[j - 1]) d[j].push_back(x);
    }
  }
  for (int i = 1; i <= n; i++) bg[i] = task0::find(i);
  for (int i = 1; i <= n; i++) {
    int x = a[i] + 1;
    d[x].push_back(bg[i]);
    sort(d[x].begin(), d[x].end());
    auto ed = unique(d[x]. begin(), d[x].end());
    for (auto l = d[x].begin(); l != ed; l++)
      for (auto r = l + 1; r != ed; r++)
        f[*l].insert(*r);
  }
  while (q--) {
    scanf("%d%d", &x, &y);
    x = bg[x], y = bg[y];
    if (x == y) {
      puts("0");
      continue;
    }
    if (x > y) swap(x, y);
    if (f[x].find(y) != f[x].end()) putchar('1');
    else putchar('2');
    putchar('\n');
  }
}