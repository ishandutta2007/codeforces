#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const int S = 320;

int a[N];
int ans[S][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", a + i);
  
  for (int i=1; i<S; ++i) {
    for (int j=n-1; j>=0; --j) 
      ans[i][j] = (j + i + a[j] < n ? ans[i][j + i + a[j]] + 1 : 1);
  }
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int p, k;
    scanf("%d %d", &p, &k);
    if (k < S) printf("%d\n", ans[k][--p]);
    else {
      int ans = 0;
      for (int i=--p; i<n; i+=a[i]+k) ans++;
      printf("%d\n", ans);
    }
  }
  return 0;
}