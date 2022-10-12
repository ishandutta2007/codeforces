#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
 
int n;
int a[N];
 
pair<int, int> ord[N];
int pre[N], suf[N];
 
int check() {
  for (int i = 0; i < n; ++i) {
    ord[i] = {a[i], i};
  }  
 
  sort(ord, ord + n);

  int maxi = 1;
  pre[0] = 1;
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (ord[i-1].second < ord[i].second) {
      ++cnt;
    } else {
      cnt = 1;
      int j = i-1;
      while (j >= 0 && ord[j].first == ord[i-1].first) {
        if (ord[j].second < ord[i].second) ++cnt;
        --j;
      }
    }
    pre[i] = cnt;
    maxi = max(maxi, cnt);
  }
 
  for (int i = n-1; i >= 0; ) {
    int j = i;
    while (j >= 0 && ord[j].first == ord[i].first) --j;
 
    if (j >= 0) {
      for (int k = i; k > j; --k) {
        if (ord[j].second < ord[k].second) {
          maxi = max(maxi, pre[j] + i-k+1);
        } else break;
      }
    }
 
    i = j;
  }

  for (int i = 0; i < n;) {
    int j = i;
    while (j < n && ord[j].first == ord[i].first) ++j;

    int k = j;
    while (k < n && ord[k].first == ord[j].first) ++k;

    int m = j;
    for (int l = i; l < j; ++l) {
      while (m < k && ord[m].second < ord[l].second) ++m;
      maxi = max(maxi, l-i+1 + k-m);
    }

    i = j;
  }
 
  return maxi;
}

int solve() {
  scanf("%d", &n); 
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  printf("%d\n", n - check());
  return 0;
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}