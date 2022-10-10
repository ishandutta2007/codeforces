#include <bits/stdc++.h>
using namespace std;
int n,i,a,b,x;
int main() {
  scanf("%d",&n);
  for (b=i=0; i<n; i++) {
    scanf("%d",&x);
    a=x+b;
    b=max(a,b);
    printf("%d ",a);
  }
  return 0;
}