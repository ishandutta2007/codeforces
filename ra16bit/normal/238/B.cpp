#include <cstdio>
#include <algorithm>
using namespace std;
int n,h,i,p,a0,a1,a2,a3,b0,b1,b2,b3,cx,cn,r,rz,a[100100],b[100100],c[100100],k[100100];
bool cmp(int i, int j) { return a[i]<a[j]; }
int main() {
  scanf("%d%d",&n,&h);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); k[i]=i; }
  sort(k,k+n,cmp);
  rz=r=a[k[n-1]]+a[k[n-2]]-a[k[0]]-a[k[1]];
  for (p=0; p<16; p++) {
    a0=a1=a2=a3=b0=b1=b2=b3=-1;
    for (i=0; i<n-1; i++) b[i]=(p>>min(i,3))&1;
	b[n-1]=(p>>3)&1;
	for (i=0; i<n; i++) if (b[i]) {
	  if (a0==-1) a0=a[k[i]]; else if (a1==-1) a1=a[k[i]];
	  if (a3==-1) a3=a[k[i]]; else { a2=a3; a3=a[k[i]]; }
	} else {
	  if (b0==-1) b0=a[k[i]]; else if (b1==-1) b1=a[k[i]];
	  if (b3==-1) b3=a[k[i]]; else { b2=b3; b3=a[k[i]]; }
	}
	if (a0==-1 || b0==-1) continue;
	cx=b3+a3+h;
	if (a2!=-1) cx=max(a2+a3,cx);
	if (b2!=-1) cx=max(b2+b3,cx);
	cn=b0+a0+h;
	if (a1!=-1) cn=min(a0+a1,cn);
	if (b1!=-1) cn=min(b0+b1,cn);
	if (cx-cn<r) {
	  r=cx-cn;
	  for (i=0; i<n; i++) c[k[i]]=b[i];
	}
  }
  printf("%d\n",r);
  for (i=0; i<n; i++) printf("%d%c",(r==rz)?1:(2-c[i]),(i==n-1)?'\n':' ');
  return 0;
}