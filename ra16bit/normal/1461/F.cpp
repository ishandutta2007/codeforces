#include <bits/stdc++.h>
using namespace std;
const int inf=1100100;
int n,m,i,j,a[100100],b[100100],c[100100],p[100100],f[22],prv[22];
bool ins[277];
char s[7];
void rec(int pos, int m) {
  if (m==0) return;
  int pr=prv[m],lst=pos;
  for (int i=pr+1; i<=m; i++) pos-=b[i]+c[i];
  rec(pos,pr);
  //printf("(rec %d..%d)",pos+1,lst);
  for (int i=pos+1; i<lst-c[m]; i++) printf("%d*",a[i]);
  printf("%d",a[lst-c[m]]);
  for (int i=lst-c[m]+1; i<=lst; i++) printf("+%d",a[i]);
  if (lst!=j-1) putchar('+');
}
void solve(int lft, int rgh) {
  if (lft>0) putchar('+');
  for (; lft<rgh && a[lft]==1; lft++) printf("1+");
  if (lft==rgh && a[rgh]==1) {
    putchar('1');
    return;
  }
  int m=0,i;
  for (int i=lft; i<=rgh; ) {
    ++m;
    int j=i;
    for (b[m]=0, p[m]=1; j<=rgh && a[j]!=1; j++) {
      b[m]++;
      p[m]*=a[j];
      if (p[m]>inf) p[m]=inf;
    }
    for (c[m]=0; j<=rgh && a[j]==1; j++) c[m]++;
    i=j;
  }
  if (m>=21) {
    for (int i=lft; i<rgh-c[m]; i++) printf("%d*",a[i]);
    printf("%d",a[rgh-c[m]]);
    for (int i=rgh-c[m]+1; i<=rgh; i++) printf("+%d",a[i]);
    return;
  }
  f[0]=0;
  for (int i=1; i<=m; i++) {
    long long cur=1;
    for (int j=i; j>0; j--) {
      cur*=p[j];
      if (cur>inf) cur=inf;
      long long now=f[j-1]+cur;
      if (now>inf) now=inf;
      if (j==i || now>=f[i]) {
        f[i]=now;
        prv[i]=j-1;
      }
    }
    f[i]+=c[i];
    if (f[i]>inf) f[i]=inf;
  }
  rec(rgh,m);
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  scanf("%s",s);
  m=strlen(s);
  if (m==1) {
    for (i=0; i<n-1; i++) printf("%d%c",a[i],s[0]);
    printf("%d\n",a[n-1]);
    return 0;
  }
  for (i=0; i<m; i++) ins[s[i]]=true;
  if (!ins['+']) {
    printf("%d",a[0]);
    for (i=1; i<n; i++) printf("%c%d",(a[i]==0)?'-':'*',a[i]);
    puts("");
    return 0;
  }
  if (!ins['*']) {
    for (i=0; i<n-1; i++) printf("%d+",a[i]);
    printf("%d\n",a[n-1]);
    return 0;
  }
  for (i=0; i<n; i=j) {
    for (; i<n && a[i]==0; i++) {
      if (i) putchar('+');
      putchar('0');
    }
    if (i>=n) break;
    for (j=i; j<n && a[j]!=0; j++);
    solve(i,j-1);
  }
  return 0;
}