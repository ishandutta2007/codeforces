#include <cstdio>
#include <iostream>
using namespace std;
const int MX=82;
int t,n,i,j,g[MX+1],a1[MX+1],an[MX+1],b1[MX+1],bn[MX+1],c[MX+1];
long long x,y,f[MX+1],a[MX+1],b[MX+1];
bool qa[MX+1],qb[MX+1];
int main() {
  scanf("%d%d",&t,&n);
  f[1]=1; f[2]=1;
  for (i=3; i<=MX; i++) f[i]=f[i-1]+f[i-2];
  for (i=2; i<=MX; i++) g[i]=g[i-1]+1-(i&1);
  while (t--) {
    scanf("%I64d%I64d",&x,&y);
	j=-1;
	if (x>y) swap(x,y);
	for (i=min(n+1,MX); i>0; i--) {
	  if (j<0 && x<=f[i] && y>f[i]) j=i;
	  a[i]=x; if (x>f[i]) { x-=f[i]; qa[i-1]=true; } else qa[i-1]=false;
	  b[i]=y; if (y>f[i]) { y-=f[i]; qb[i-1]=true; } else qb[i-1]=false;
	}
	for (i=2; i<=min(n+1,MX); i++) {
	  if (a[i]<=f[i]) {
	    a1[i]=min(a1[i-1],an[i-1]+2);
		an[i]=min(a1[i-1],an[i-1])+1+g[i-2];
		if (i>j) {
		  c[i]=c[i-1];
		  if (!qa[i] && !qb[i]) c[i]=min(c[i],min(a1[i-1]+2+bn[i-1],an[i-1]+2+b1[i-1]));
		}
		if (i==j) c[i]=min(a1[i-1],an[i-1])+1+b1[i-2];
	  } else {
	    a1[i]=a1[i-2]+1;
		an[i]=an[i-2];
		if (i>j) c[i]=c[i-1];
	  }
	  if (b[i]<=f[i]) {
	    b1[i]=min(b1[i-1],bn[i-1]+2);
		bn[i]=min(b1[i-1],bn[i-1])+1+g[i-2];
	  } else {
	    b1[i]=b1[i-2]+1;
		bn[i]=bn[i-2];
	  }
	  //printf("%d: (%d %d) |%I64d| |%I64d| <<%d %d>> %d %d , %d %d | %d\n",i,int(f[i]),int(f[i-1]),a[i],b[i],qa[i],qb[i],a1[i],an[i],b1[i],bn[i],c[i]);
	}
	printf("%d\n",c[min(n+1,MX)]);
  }
  return 0;
}