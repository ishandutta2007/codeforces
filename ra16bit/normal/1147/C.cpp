#include <bits/stdc++.h>
using namespace std;
int n,i,a[55];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  if (a[0]==a[n/2]) puts("Bob"); else puts("Alice");
  return 0;
}