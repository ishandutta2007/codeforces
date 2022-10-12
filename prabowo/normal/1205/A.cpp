#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int main() {
  scanf("%d", &n);
  if (n % 2 == 0) return 0 * printf("NO\n");
  
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      a[i] = i*2 + 2;
      a[i+n] = i*2 + 1;
    } else {
      a[i] = i*2 + 1;
      a[i+n] = i*2 + 2;
    }
  }
  
  printf("YES\n");
  for (int i = 0; i < n*2; ++i) printf("%d ", a[i]);
  printf("\n");
  return 0;
}