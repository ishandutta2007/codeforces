#include <stdio.h>
int i,n,r=8,a[8],b[8],c[8],d[8],rb[8],rc[8],rd[8];
bool u[257];
void rec(int l) {
  int i,j,k;
  if (a[l]==n) {
    if (l-1<r) {
      for (i=1; i<l; i++) { rb[i]=b[i]; rc[i]=c[i]; rd[i]=d[i]; }
	  r=l-1;
	}
    return;
  }
  if (l>5 || l>=r) return;
  for (i=0; i<=l; i++) for (j=1; j<=l; j++) for (k=1; k<=8 && a[i]+k*a[j]<=n; k*=2) if (!u[a[i]+k*a[j]]) {
    a[l+1]=a[i]+k*a[j];
	u[a[l+1]]=true;
	b[l]=i; c[l]=j; d[l]=k;
	rec(l+1);
	u[a[l+1]]=false;
  }
}
int main() {
  scanf("%d",&n);
  a[0]=0; a[1]=1;
  u[0]=u[1]=true;
  rec(1);
  printf("%d\n",r);
  for (i=1; i<=r; i++) printf("lea e%cx, [e%cx + %d*e%cx]\n",'a'+i,(rb[i]==0)?'z':('a'+rb[i]-1),rd[i],'a'+rc[i]-1);
  return 0;
}