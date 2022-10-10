#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,ii,c;
long long xa,xb,xc,xd,mask,a[100100],b[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%I64d.%I64d.%I64d.%I64d",&xa,&xb,&xc,&xd);
	a[i]=(xa<<24)+(xb<<16)+(xc<<8)+xd;
  }
  sort(a,a+n);
  for (ii=31; ii>0; ii--) {
    mask|=1LL<<ii;
	for (c=i=0; i<n; i++) {
	  b[i]=a[i]&mask;
	  if (i==0 || b[i]!=b[i-1]) c++;
	}
	if (c==m) {
	  printf("%I64d.%I64d.%I64d.%I64d\n",(mask>>24)&255,(mask>>16)&255,(mask>>8)&255,mask&255);
	  return 0;
	}
  }
  puts("-1");
  return 0;
}