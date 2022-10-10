#include <stdio.h>
int n,i,l,r,f,a[2200000],b[2200000],s[2200000],t[2200000],p[2200000],md=51123987;
char st[2200000];
long long e,f1,f2;
int main() {
  scanf("%d",&n); gets(st); gets(st); l=r=-1;
  for (i=0; i<n; i++) {
    if (r>=i) {
      a[i]=a[2*l-i];
      if (i+a[i]>r) a[i]=r-i;
    } else a[i]=0;
    if (i+a[i]>=r) {
      for (; i-a[i]>=0 && i+a[i]<n && st[i-a[i]]==st[i+a[i]]; a[i]++);
      l=i; r=i+(--a[i]);
    }
    f=(f+a[i]+1)%md;
    s[i-a[i]]++; s[i+1]--;
    t[i+a[i]]++; t[i-1]--;
  }
  l=r=0;
  for (i=1; i<n; i++) {
    if (r>=i) {
      b[i]=b[2*l-i];
      if (i+b[i]-1>r) b[i]=r-i+1;
    } else b[i]=1;
    if (i+b[i]>r) {
      for (; i-b[i]>=0 && i+b[i]<=n && st[i-b[i]]==st[i+b[i]-1]; b[i]++);
      l=i; r=i+(--b[i])-1;
    }
    f=(f+b[i])%md;
    s[i-b[i]]++; s[i]--;
    t[i+b[i]-1]++; t[i-1]--;
  }
  p[n]=l=0;
  for (i=n-1; i>=0; i--) {
    l+=t[i];
    p[i]=(p[i+1]+l)%md;
  }
  for (r=e=i=0; i<n; i++) {
    e+=s[i];
    r=(r+e*(p[0]-p[i]))%md;
  }
  f1=f; f2=f-1;
  if (f1&1) f2/=2; else f1/=2;
  f1%=md; f2%=md;
  r=(f1*f2-r)%md;
  printf("%d\n",r);
  return 0;
}