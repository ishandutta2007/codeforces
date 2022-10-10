#include <stdio.h>
int i,k,r,n,m,a[55],c[55],f[55];
char s[111];
bool q;
void go(int n, int k) {
  for (int i=0; i<n; i++) s[i]='B';
  int j=0;
  if (c[k]) s[j++]='C';
  for (int i=0; i<f[k]; i++) {
    s[j+i*2]='A';
    s[j+i*2+1]='C';
  }
  if (a[k]) s[n-1]='A';
  s[n]=0;
  puts(s);
}
void rec(int l) {
  if (l==3) {
    for (i=3; i<=k; i++) {
      c[i]=c[i-2];
      a[i]=a[i-1];
      f[i]=f[i-1]+f[i-2]+int(a[i-2] && c[i-1]);
      if (f[i]>r) break;
    }
    if (i>k && f[k]==r) {
      go(n,1);
      go(m,2);
      q=true;
    }
    return;
  }
  int nn=n;
  if (l==2) nn=m;
  for (a[l]=0; a[l]<2; a[l]++) for (c[l]=0; c[l]<2; c[l]++) for (f[l]=0; f[l]*2+a[l]+c[l]<=nn; f[l]++) {
    rec(l+1);
    if (q) return;
  }
}
int main() {
  scanf("%d%d%d%d",&k,&r,&n,&m);
  rec(1);
  if (!q) puts("Happy new year!");
  return 0;
}