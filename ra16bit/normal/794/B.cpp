#include <bits/stdc++.h>
using namespace std;
int n,h,i;
double s,a;
int main() {
  scanf("%d%d",&n,&h);
  s=h/double(n);
  for (i=1; i<n; i++) {
    a=sqrt((i*s)/h);
    printf("%.10lf ",a*h);
  }
  return 0;
}