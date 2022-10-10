#include <bits/stdc++.h>
using namespace std;
int n,i,j,a[100100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  reverse(a,a+n);
  for (i=0; i<n; i=j) {
    for (j=i; j<n && a[i]==a[j]; j++);
    if (j%2==1) { puts("Conan"); return 0; }
  }
  puts("Agasa");
  return 0;
}