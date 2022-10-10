#include <stdio.h>
#include <string.h>
const int MX=1000100;
int n,m,i,j,k,o,p,d,t,it,e,z,pw,a[MX],b[MX],u[MX],was[MX];
char s[MX],ns[MX];
int main() {
  scanf("%s",s);
  n=strlen(s);
  scanf("%d",&m);
  for (t=1; t<=m; t++) {
    scanf("%d%d",&k,&d);
    for (z=i=0; i<d; i++) for (j=i; j<k; j+=d, z++) a[j]=z-1;
    o=n-k+1; e=0;
    for (j=k-1; j>=0; j=a[j]) b[e++]=j;
    for (p=e-1; p>0; p--) {
      i=b[p];
      u[i]=t;
      if (p+o<e) j=o+b[p+o]; else j=e-1-p;
      ns[j]=s[i];
    }
    for (i=k-1; i<n; i++) {
      if (i>=o) pw=n-i; else pw=k;
      if (pw<e) j=o+b[pw]; else j=i-k+e;
      ns[j]=s[i];
    }
    for (i=0; i<k; i++) if (u[i]!=t) {
      e=0; ++it;
      for (j=i; was[j]!=it; j=a[j]) {
        if (j==-1 || u[j]==t) break;
        was[j]=it;
        b[e++]=j;
      }
      if (j>=0 && was[j]==it) for (p=0; p<e; p++) {
        u[b[p]]=t;
        ns[o+b[(p+o)%e]]=s[b[p]];
      }
    }
    for (i=0; i<n; i++) s[i]=ns[i];
    puts(s);
  }
  return 0;
}