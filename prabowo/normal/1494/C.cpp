#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m;
int a[N], b[N];

int solve(vector<int> a, vector<int> b) {
  int i = 0;
  int ret = 0;

  int same = 0;
  for (int j = 0; j < b.size(); ++j) if (binary_search(a.begin(), a.end(), b[j])) ++same;

  for (int j = 0; j < b.size(); ++j) {
    if (binary_search(a.begin(), a.end(), b[j])) --same;
    while (i < a.size() && a[i] <= b[j]) ++i;
    ret = max(ret, j - (int) (upper_bound(b.begin(), b.end(), b[j] - i) - b.begin()) + 1 + same);
    // if (ret == 3) cerr << i << " " << j << endl;
  }
  // cerr << ret << endl;
  return ret;
}

int solve() {
  scanf("%d %d", &n, &m);

  vector<int> al, ar;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] < 0) al.push_back(-a[i]);
    else ar.push_back(a[i]);
  }
  vector<int> bl, br;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
    if (b[i] < 0) bl.push_back(-b[i]);
    else br.push_back(b[i]);
  }

  reverse(al.begin(), al.end());
  reverse(bl.begin(), bl.end());

  printf("%d\n", solve(al, bl) + solve(ar, br));
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}