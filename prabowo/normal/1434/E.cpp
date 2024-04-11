#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

// current nim values if the second move is at i
int nim[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  vector<bool> has(n + 1, false);
  priority_queue<int> pq[n + 1];
  vector<int> decrements[n + 1];

  for (int i = n - 1; i >= 0; --i) {
    int mex;
    vector<int> idxs;
    for (mex = 0; ; ++mex) {
      while (pq[mex].size() > 0 && nim[pq[mex].top()] != mex) pq[mex].pop();
      if (pq[mex].size() == 0) break;

      idxs.push_back(upper_bound(a, a + n, a[i] - (a[pq[mex].top()]-a[i])) - a);
    }
    nim[i] = mex;
    has[mex] = true;
    pq[mex].push(i);

    if (mex) decrements[idxs[0]].push_back(i);
    for (int j = 1; j < idxs.size(); ++j) {
      idxs[j] = max(idxs[j], idxs[j - 1]);
      decrements[idxs[j]].push_back(i);
    }

    for (int j : decrements[i]) pq[--nim[j]].push(j);
  }

  int mex;
  for (mex = 0; has[mex]; ++mex);
  return mex;
}

int main() {
  int t;
  scanf("%d", &t);
  int ans = 0;
  for (int i = 0; i < t; ++i) {
    ans ^= solve();
  }
  if (ans) printf("YES\n");
  else printf("NO\n");
  return 0;
}