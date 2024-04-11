#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int m[N];
int maks[N];

int main() {
  int n;
  scanf("%d", &n);
  
  int maks_all = 0;
  for (int i=0; i<n; i++) {
    scanf("%d", &m[i]);
    
    int p;
    for (int j=0; j<m[i]; j++) {
      scanf("%d", &p);
      maks[i] = max(maks[i], p);
    }
    
    maks_all = max(maks_all, maks[i]);
  }
  
  long long ans = 0;
  for (int i=0; i<n; i++) ans += 1LL * (maks_all - maks[i]) * m[i];
  printf("%lld\n", ans);
  return 0;
}