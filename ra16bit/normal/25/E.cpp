#include <stdio.h>
#include <string.h>
int i,k,r,e,z,n[3],a[3],p[333333];
bool u[3],q;
char s[3][111111],t[333333];
void rec(int l) {
  if (l==3) {
    k=e=0;
    for (i=0; i<n[a[1]]; i++) t[k++]=s[a[1]][i];
    t[k++]='$';
    for (i=0; i<n[a[0]]; i++) t[k++]=s[a[0]][i];
    q=false;
    for (i=1; i<k; i++) {
      while (e>0 && t[e]!=t[i]) e=p[e-1];
      if (t[e]==t[i]) e++;
      p[i]=e;
      if (e==n[a[1]]) q=true;
    }
    z=p[k-1];
    k=e=0;
    for (i=0; i<n[a[2]]; i++) t[k++]=s[a[2]][i];
    t[k++]='$';
    for (i=0; i<n[a[0]]; i++) t[k++]=s[a[0]][i];
    if (!q) for (i=z; i<n[a[1]]; i++) t[k++]=s[a[1]][i];
    q=false;
    for (i=1; i<k; i++) {
      while (e>0 && t[e]!=t[i]) e=p[e-1];
      if (t[e]==t[i]) e++;
      p[i]=e;
      if (e==n[a[2]]) q=true;
    }
    if (q) z=k-n[a[2]]-1; else z=k-p[k-1]-1;
    if (z<r) r=z;
    return;
  }
  for (int i=0; i<3; i++) if (!u[i]) {
    a[l]=i; u[i]=true; rec(l+1); u[i]=false;
  }
}
int main() {
  for (i=0; i<3; i++) { gets(s[i]); n[i]=strlen(s[i]); r+=n[i]; }
  rec(0);
  printf("%d\n",r);
  return 0;
}