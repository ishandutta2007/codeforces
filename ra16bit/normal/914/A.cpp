#include <bits/stdc++.h>
using namespace std;
int n,i,a[1010];
bool b[1000100];
int main() {
  for (i=0; i<=1000; i++) b[i*i]=true;
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  reverse(a,a+n);
  for (i=0; i<n; i++) if (a[i]<0 || !b[a[i]]) break;
  printf("%d\n",a[i]);
  return 0;
}