#include <bits/stdc++.h>
using namespace std;
int n,x,i,s,mx;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    s+=x;
    mx=max(mx,x);
  }
  for (i=mx; ; i++) {
    if (i*n-s>s) break;
  }
  printf("%d\n",i);
  return 0;
}