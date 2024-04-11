#include <stdio.h>
const int md=1000000007,MX=1000100;
int n,i,j,a[100100],b[MX],s[MX],bb,r;
long long cur;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) {
    cur=1;
	for (j=a[i]; j>0; j&=j-1) cur+=s[j];
    cur=((cur%md)*a[i])%md;
	bb=md-b[a[i]];
	r=(r+bb)%md;
	for (j=a[i]; j<MX; j=(j<<1)-(j&(j-1))) s[j]=(s[j]+bb)%md;
	r=(r+cur)%md;
	for (j=a[i]; j<MX; j=(j<<1)-(j&(j-1))) s[j]=(s[j]+cur)%md;
	b[a[i]]=cur;
  }
  printf("%d\n",r);
  return 0;
}