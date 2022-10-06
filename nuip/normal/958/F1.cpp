#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int as[114];
int ks[114];
int cnt[114];

int main() {
  scanf("%d%d", &n, &m);
  for (int i=0; i<n; i++) {
    scanf("%d", &as[i]);
    as[i]--;
  }

  for (int i=0; i<m; i++) {
    scanf("%d", &ks[i]);
  }

  for (int l=0; l<n; l++) {
    for (int r=l+1; r<=n; r++) {
      for (int i=0; i<m; i++) {
        cnt[i] = 0;
      }

      for (int i=l; i<r; i++) {
        cnt[as[i]]++;
      }

      int ok = 0;
      for (int i=0; i<m; i++) {
        ok += (cnt[i] == ks[i]);
      }

      if (ok == m) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
}