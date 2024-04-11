#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;
typedef pair<int, int> pi;

int n;
vector <pair<int, int> > a[1010];
int res[N];
int cur = 0;

int main() {
  //ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    int x = u / 1000;
    a[x].push_back(make_pair(v, i));
  }
  for (int i = 0; i <= 1001; i++) {
    sort(a[i].begin(), a[i].end());
  }
  for (int i = 0; i <= 1001; i++) {
    if (i & 1) {
      for (pair<int, int> j : a[i]) {
        res[++cur] = j.second;
      }
    } else {
      for (int j = a[i].size() - 1; j >= 0; j--) {
        res[++cur] = a[i][j].second;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", res[i]);
  }
  return 0;
}