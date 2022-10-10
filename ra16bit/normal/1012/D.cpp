#include <bits/stdc++.h>
using namespace std;
int n,m,an,bn,cn,cm,dn,dm,ln,lm,rn,rm,sn,sm,pa,pb,i,j,ii,jj,x,y,cur,cnt,r=1000000000;
char s[200200],t[200200],a[400400],b[400400];
bool peq,req,fi;
int main() {
  scanf("%s",s); n=strlen(s);
  for (cn=i=1; i<n; i++) if (s[i]!=s[i-1]) cn++;
  scanf("%s",t); m=strlen(t);
  for (cm=i=1; i<m; i++) if (t[i]!=t[i-1]) cm++;
  if (cn<cm) {
    ln=min(5,cn); lm=cm;
  } else {
    ln=cn; lm=min(5,cm);
  }
  for (i=0; i<=ln; i++) for (j=0; j<=lm; j++) {
    cur=int(i>0 || j>0);
    dn=cn-i+j;
    dm=cm-j+i;
    if (s[0]==t[0]) {
      if (i<cn && j>0 && i%2!=j%2) dn--;
      if (j<cm && i>0 && i%2!=j%2) dm--;
    } else {
      if (i<cn && j>0 && i%2==j%2) dn--;
      if (j<cm && i>0 && i%2==j%2) dm--;
    }
    if (j==0) {
      pa=s[0]-'a';
      if (i%2) pa^=1;
    } else pa=t[0]-'a';
    if (i==0) {
      pb=t[0]-'a';
      if (j%2) pb^=1;
    } else pb=s[0]-'a';
    peq=(pa==pb);
    cur+=max(dn,dm)-1;
    if (dn==dm && peq) cur++;
    if (cur<r) { r=cur; rn=i; rm=j; req=peq; fi=(dn>dm); }
  }
  printf("%d\n",r);
  if (rn>0 || rm>0) {
    for (i=0; i<rn; i++) for (ii=sn; sn<n && s[sn]==s[ii]; sn++);
    for (i=0; i<rm; i++) for (ii=sm; sm<m && t[sm]==t[ii]; sm++);
    printf("%d %d\n",sn,sm);
    for (i=0; i<sm; i++) a[an++]=t[i];
    for (j=0; j<sn; j++) b[bn++]=s[j];
    for (; i<m; i++) b[bn++]=t[i];
    for (; j<n; j++) a[an++]=s[j];
    r--;
  } else {
    for (an=n, i=0; i<n; i++) a[i]=s[i];
    for (bn=m, i=0; i<m; i++) b[i]=t[i];
  }
  x=y=i=j=0;
  if (req) {
    if (fi) {
      for (ii=i; i<an && a[i]==a[ii]; i++, x++);
    } else {
      for (jj=j; j<bn && b[j]==b[jj]; j++, y++);
    }
    printf("%d %d\n",x,y);
    swap(x,y);
    r--;
  }
  for (; r>0; r--) {
    for (ii=i; i<an && a[i]==a[ii]; i++, x++);
    for (jj=j; j<bn && b[j]==b[jj]; j++, y++);
    printf("%d %d\n",x,y);
    swap(x,y);
  }
  for (ii=i; i<an && a[i]==a[ii]; i++);
  for (jj=j; j<bn && b[j]==b[jj]; j++);
  if (i<an || j<bn) { x/=0; printf("%d\n",x); }
  return 0;
}