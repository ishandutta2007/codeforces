#include <iostream>
#include <cstdio>
using namespace std;
int n,k,e,l;
double v1,v2,p,x;
int main() {
  cin>>n>>l>>v1>>v2>>k;
  e=(n+k-1)/k;
  p=e/v2+(v2-v1)*(e-1)/(v1+v2)/v2-1/v2+1/v1;
  x=l/v1/p;
  printf("%.10lf\n",x/v2+(l-x)/v1);
  return 0;
}