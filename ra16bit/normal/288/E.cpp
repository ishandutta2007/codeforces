#include <stdio.h>
#include <string.h>
const int md=1000000007,MX=100100;
int i,st,n;
char s[MX],t[MX];
long long x,y,cnt,sum,res,a[MX],b[MX],c[MX],l[MX],r[MX],p[MX],es[MX],et[MX];
int main() {
  scanf("%s",s);
  scanf("%s",t);
  n=strlen(s);
  p[0]=1; c[0]=1;
  for (i=1; i<=n; i++) {
	x=(4LL*p[i-1])%md;
	y=(7LL*p[i-1])%md;
	a[i]=(((x+y)%md)*c[i-1]+2LL*a[i-1])%md;
	cnt=(c[i-1]+md-1)%md;
	sum=((2LL*a[i-1])%md+md-l[i-1]+md-r[i-1])%md;
	b[i]=(2*b[i-1])%md;
	b[i]=(((x*x+y*y)%md)*cnt+b[i])%md;
	b[i]=((((x+y)%md)*sum)%md+b[i])%md;
	b[i]=(x*y+b[i])%md;
	b[i]=(r[i-1]*y+b[i])%md;
	b[i]=(x*l[i-1]+b[i])%md;
	b[i]=(r[i-1]*l[i-1]+b[i])%md;
	c[i]=(2*c[i-1])%md;
	l[i]=(x+l[i-1])%md;
	r[i]=(y+r[i-1])%md;
    p[i]=(10LL*p[i-1])%md;
  }
  for (i=0; i<n; i++) {
    es[i]=(es[i-1]+p[n-i-1]*(s[i]-'0'))%md;
	et[i]=(et[i-1]+p[n-i-1]*(t[i]-'0'))%md;
  }
  for (st=0; s[st]==t[st]; st++);
  for (i=n-1; i>st; i--) if (s[i]=='4') {
    x=(es[i-1]+4LL*p[n-i-1])%md;
    y=(es[i-1]+7LL*p[n-i-1])%md;
	res=(res+b[n-i-1])%md;
	cnt=(c[n-i-1]+md-1)%md;
	sum=((2LL*a[n-i-1])%md+md-l[n-i-1]+md-r[n-i-1])%md;
	res=(((y*y)%md)*cnt+res)%md;
	res=((y*sum)%md+res)%md;
	res=(x*y+res)%md;
	res=(r[n-i-1]*y+res)%md;
	res=(x*l[n-i-1]+res)%md;
	res=(r[n-i-1]*l[n-i-1]+res)%md;
  }
  x=es[st];
  y=et[st];
  res=(x*y+res)%md;
  res=(r[n-st-1]*y+res)%md;
  res=(x*l[n-st-1]+res)%md;
  res=(r[n-st-1]*l[n-st-1]+res)%md;
  for (i=st+1; i<n; i++) if (t[i]=='7') {
    x=(et[i-1]+7LL*p[n-i-1])%md;
    y=(et[i-1]+4LL*p[n-i-1])%md;
	res=(res+b[n-i-1])%md;
	cnt=(c[n-i-1]+md-1)%md;
	sum=((2LL*a[n-i-1])%md+md-l[n-i-1]+md-r[n-i-1])%md;
	res=(((y*y)%md)*cnt+res)%md;
	res=((y*sum)%md+res)%md;
	res=(x*y+res)%md;
	res=(l[n-i-1]*y+res)%md;
	res=(x*r[n-i-1]+res)%md;
	res=(r[n-i-1]*l[n-i-1]+res)%md;
  }
  printf("%I64d\n",res);
  return 0;
}