#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,i,j,k,e,x,l[7],r[7];
double p,c,res,f[7][7][3];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&l[i],&r[i]);
  for (i=1; i<=10000; i++) {
    memset(f,0,sizeof(f));
    f[0][0][0]=1;
    for (j=0; j<n; j++) {
      p=1./(r[j]-l[j]+1.);
      for (k=0; k<=j; k++) for (e=0; e<2; e++) if (f[j][k][e]) {
        x=min(r[j]+1,i)-l[j];
        if (x>0) f[j+1][k][e]+=f[j][k][e]*x*p;
        if (i>=l[j] && i<=r[j]) f[j+1][k+1][e]+=f[j][k][e]*p;
        x=r[j]-max(l[j]-1,i);
        if (x>0) f[j+1][k][e+1]+=f[j][k][e]*x*p;
      }
    }
    for (c=0, k=1; k<=j; k++) for (e=0; e<2; e++) if ((k>1 && e==0) || e==1) c+=f[n][k][e];
    res+=c*i;
  }
  printf("%.15lf\n",res);
  return 0;
}