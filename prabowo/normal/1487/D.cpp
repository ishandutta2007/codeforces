#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
char s[N];

vector<int> cs;

int solve() {
  scanf("%d", &n);

  int ans = upper_bound(cs.begin(), cs.end(), n) - cs.begin();

  printf("%d\n", ans);
  return 0;
}

void init() {
  for (int i = 3; i*i/2+1 < INF; i += 2) {
    cs.push_back(i*i/2 + 1);
  }
}

int main() {
  init();
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}