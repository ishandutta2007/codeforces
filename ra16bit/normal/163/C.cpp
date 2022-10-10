#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,l;
long long v1,v2,vsum,a[400400];
long double le,ri,dist,r[100100];
int main() {
  scanf("%d%d%I64d%I64d",&n,&l,&v1,&v2);
  for (i=0; i<n; i++) {
    scanf("%I64d",&a[i]);
    for (j=0; j<3; j++) a[i+(j+1)*n]=a[i+j*n]+2*l;
  }
  //for (i=0; i<4*n; i++) printf("%d ",a[i]); puts("");
  vsum=v1+v2;
  dist=(l*v2)/((long double)vsum);
  //printf("%.5lf\n",double(dist));
  for (j=2; (a[j]-a[0])*vsum<l*v2; j++);
  for (i=1; i<=n; i++) {
    for (; ; j++) {
      le=max((long double)a[i-1],a[j-1]-dist);
      ri=min((long double)a[i],a[j]-dist);
      //printf("%d..%d : %.5lf %.5lf\n",i,j,double(le),double(ri));
      r[j-i]+=ri-le;
      if ((a[j]-a[i])*vsum>=l*v2) break;
    }
  }
  r[0]=2*l;
  for (i=1; i<=n; i++) r[0]-=r[i];
  for (i=0; i<=n; i++) printf("%.14lf\n",double(r[i])/double(2*l));
  return 0;
}