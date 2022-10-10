#include <cstdio>
#include <algorithm>
using namespace std;
const char p[4]={'W','Y','R','B'};
int ii,i,j,k,d,l,r,s[1010],a[22],f[22][22],md=1000000007;
long long pw2,b[22][22],c[22][22];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void rec(int l) {
  if (l==3) {
    f[(s[0]<<2)+s[1]][(s[1]<<2)+s[2]]=1;
	f[(s[0]<<2)+s[1]][16]=1;
	a[(s[0]<<2)+s[1]]=1;
	return;
  }
  if (l==0 || (s[l-1]!=0 && s[l-1]!=1)) {
    s[l]=0; rec(l+1);
	s[l]=1; rec(l+1);
  }
  if (l==0 || (s[l-1]!=2 && s[l-1]!=3)) {
    if (l<2 || s[l-1]!=0 || s[l-2]!=3) { s[l]=2; rec(l+1); }
	if (l<2 || s[l-1]!=0 || s[l-2]!=2) { s[l]=3; rec(l+1); }
  }	
}
void pow(int x) {
  int i,j,k,ii;
  for (i=0; i<=16; i++) for (j=0; j<=16; j++) b[i][j]=int(i==j);
  for (ii=30; ii>=0; ii--) {
    for (i=0; i<=16; i++) for (j=0; j<=16; j++) {
	  c[i][j]=0;
	  for (k=0; k<=16; k++) c[i][j]=(c[i][j]+b[i][k]*b[k][j])%md;
	}
    if (x&(1<<ii)) {
	  for (i=0; i<=16; i++) for (j=0; j<=16; j++) {
	    b[i][j]=0;
		for (k=0; k<=16; k++) b[i][j]=(b[i][j]+c[i][k]*f[k][j])%md;
	  }
	} else for (i=0; i<=16; i++) for (j=0; j<=16; j++) b[i][j]=c[i][j];
  }
}
long long solve(int n) {
  if (n==0) return 0;
  long long r=0,c=0;
  int i;
  pow(n-1);
  for (i=0; i<=16; i++) r=(r+a[i]*b[i][16])%md;
  if (n>2) {
    pow((n+1)/2-1);
    for (i=0; i<=16; i++) c=(c+a[i]*b[i][16])%md;
	c=(c+md-8)%md;
  }
  return (((r+md-c)*pw2)%md+c)%md;
}
int main() {
  scanf("%d%d",&l,&r);
  rec(0); pw2=pw(2,md-2);
  f[16][16]=1; a[16]=8;
  printf("%I64d\n",(solve(r)+md-solve(l-1))%md);
  return 0;
}