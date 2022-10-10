#include <stdio.h>
int l,d,v,g,r;
double c,t;
int main() {
  scanf("%d%d%d%d%d",&l,&d,&v,&g,&r);
  t=double(l)/double(v);
  c=double(d)/double(v);
  while (c>g+r) c-=g+r;
  if (c>=g-1e-10) t+=g+r-c;
  printf("%.10lf\n",t);
  return 0;
}