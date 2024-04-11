#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=500000;
int m,i,j,ii;
long long l,r,k,R,h,s,a[2][2],b[2][2],f[2][2];
void upd(long long h) {
  if (r/h-(l-1)/h>=k) R=max(R,h);
}
int main() {
  scanf("%d%I64d%I64d%I64d",&m,&l,&r,&k);
  for (h=1; h<=MX; h++) upd(h);
  for (h=1; r/h>MX; h++) upd(r/h);
  for (h=1; (l-1)/h>MX; h++) upd((l-1)/h);
  R--;
  a[0][0]=0; a[0][1]=1%m;
  a[1][0]=1%m; a[1][1]=1;
  f[0][0]=1%m; f[0][1]=0;
  f[1][0]=0; f[1][1]=1%m;
  for (ii=60; ii>=0; ii--) {
    for (i=0; i<2; i++) for (j=0; j<2; j++) {
	  b[i][j]=0;
	  for (int k=0; k<2; k++) b[i][j]=(b[i][j]+f[i][k]*f[k][j])%m;
	}
	if (R&(1LL<<ii)) for (i=0; i<2; i++) for (j=0; j<2; j++) {
	  f[i][j]=0;
	  for (int k=0; k<2; k++) f[i][j]=(f[i][j]+b[i][k]*a[k][j])%m;
	} else for (i=0; i<2; i++) for (j=0; j<2; j++) f[i][j]=b[i][j];
  }
  printf("%I64d\n",f[1][1]%m);
  return 0;
}