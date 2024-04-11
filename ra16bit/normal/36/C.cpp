#include <stdio.h>
int i,j,n,h[3210],l[3210],r[3210];
double a[3210],c,res,eps=1e-9;
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d",&h[i],&l[i],&r[i]); a[i]=0;
    for (j=0; j<i; j++) {
      if (a[j]>a[i]) a[i]=a[j];
      if (r[i]>r[j]) {
        if (l[i]>=r[j]) {
          if (a[j]+h[j]>a[i]) a[i]=a[j]+h[j];
        } else {
          c=(double(r[j]-l[i])/double(r[i]-l[i]))*h[i];
          if (a[j]+h[j]-c>a[i]) a[i]=a[j]+h[j]-c;
        }
      }
      if (r[i]>=l[j]) {
        c=(double(r[i]-l[j])/double(r[j]-l[j]))*h[j];
        if (c<h[j]+eps && c>h[i]-eps && a[j]+c-h[i]>a[i]) a[i]=a[j]+c-h[i];
        if (l[i]>=l[j]) {
          c=(double(l[i]-l[j])/double(r[j]-l[j]))*h[j];
          if (c<h[j]+eps && a[j]+c>a[i]) a[i]=a[j]+c;
        }
      }
    }
    if (a[i]+h[i]>res) res=a[i]+h[i];
  }
  printf("%.8lf\n",res);
  return 0;
}