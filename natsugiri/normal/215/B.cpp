#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int l,m,n;
int x[5050], y[5050], z[5050], A, B;

int main(){
  scanf("%d", &l);
  for (int i=0; i<l; i++) scanf("%d", x+i);
  scanf("%d", &m);
  for (int i=0; i<m; i++) scanf("%d", y+i);
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", z+i);
  scanf("%d%d", &A, &B);
  double r1=x[0], r2, p1, p2=z[0], a=A, b=B;
  for (int i=0; i<l; i++) r1=max(r1, (double)x[i]);
  for (int i=0; i<n; i++) p2=min(p2, (double)z[i]);
  r2=0;
  for (int i=0; i<m; i++) {
    r2=max(r2, r1*sqrt(b*y[i]/(a*p2+b*y[i])));
  }
  printf("%.16f\n", r2);
  return 0;
}