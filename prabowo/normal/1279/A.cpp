#include <bits/stdc++.h>
using namespace std;

int n;

int main() {  
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a[3];
    scanf("%d %d %d", a, a + 1, a + 2);

    sort(a, a + 3);

    if (a[2] > a[0] + a[1] + 1) printf("No\n");
    else printf("Yes\n");
  }
  return 0;
}