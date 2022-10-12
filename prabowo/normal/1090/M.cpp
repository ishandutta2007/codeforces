#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  
  int ans = 0;
  int lst = 0;
  int cur = 0;
  for (int i=0; i<n; i++) {
    int a;
    scanf("%d", &a);
    
    if (a == lst) {
      cur = 1;
    } else {
      ++cur;
    }
    
    lst = a;
    ans = max(ans, cur);
  }
  
  printf("%d\n", ans);
  
  return 0;
}