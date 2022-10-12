#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, x;

int main() {
  scanf("%d %d", &n, &x);
  int sum = 0;
  for (int i=0; i<n; i++) {
    int a;
    scanf("%d", &a);
    sum += a;
  }
  
  if (sum + n-1 == x) printf("YES\n");
  else printf("NO\n");
  return 0;
}