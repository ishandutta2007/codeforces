#include <bits/stdc++.h>
using namespace std;
int n,r,i,j,d,x[1010];
double y[1010];
double sqr(double x) { return x*x; }
int main() {
  scanf("%d%d",&n,&r);
  for (i=0; i<n; i++) {
    scanf("%d",&x[i]);
	y[i]=r;
	for (j=0; j<i; j++) {
	  d=abs(x[i]-x[j]);
	  if (d<=2*r) y[i]=max(y[i],y[j]+sqrt(max(0.,sqr(2*r)-sqr(d))));
	}
	printf("%.8lf ",y[i]);
  }
  return 0;
}