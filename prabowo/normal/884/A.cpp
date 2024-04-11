#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int t, n;

int main() {
  scanf("%d %d", &n, &t);
  for (int i=0; i<n; i++) {
    int a;
    scanf("%d", &a);
    t -= 86400 - a;
    if (t <= 0) return 0 * printf("%d\n", i+1);
  }
  return 0;
}