#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, k;
vector<int> S[N];

int ask(vector<int> idxs) {
  printf("? %d", (int) idxs.size());
  for (int idx: idxs) printf(" %d", idx);
  printf("\n");
  fflush(stdout);

  int maxi;
  scanf("%d", &maxi);
  return maxi;
}

int ask(int l, int r) {
  vector<int> v;
  for (int i = l; i <= r; ++i) v.push_back(i);
  return ask(v);
}

int answer(vector<int> v) {
  printf("!");
  for (int u: v) printf(" %d", u);
  printf("\n");
  fflush(stdout);

  char s[20];
  scanf("%s", s);
  return 0;
}

int maxi;
int maxiLoc(int l, int r) {
  if (l == r) return l;
  int mid = (l + r) >> 1;

  if (ask(l, mid) == maxi) return maxiLoc(l, mid);
  else return maxiLoc(mid+1, r);
}

int solve() {
  scanf("%d %d", &n, &k);

  for (int i = 0; i < k; ++i) {
    int c;
    scanf("%d", &c);
    S[i].resize(c);

    for (int j = 0; j < c; ++j) scanf("%d", &S[i][j]);
    sort(S[i].begin(), S[i].end());
  }

  maxi = ask(1, n);
  int idxMax = maxiLoc(1, n);

  vector<int> ans;
  for (int i = 0; i < k; ++i) {
    if (binary_search(S[i].begin(), S[i].end(), idxMax)) {
      vector<int> v;
      for (int j = 1; j <= n; ++j) {
        if (binary_search(S[i].begin(), S[i].end(), j));
        else v.push_back(j);
      }
      ans.push_back(ask(v));
    }
    else ans.push_back(maxi);
  }

  answer(ans);
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