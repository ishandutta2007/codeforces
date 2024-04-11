#include <stdio.h>
const int mx=10000100;
int n,j,s,a[1000100],b[mx+100],p[1000100],r[1000100];
long long i,d,e,f;
int gcd(int a, int b) { return (b==0)?a:gcd(b,a%b); }
void un(int a, int b) {
  if (a==b) return;
  if (r[a]<r[b]) p[a]=b; else {
    if (r[a]==r[b]) r[a]++;
    p[b]=a;
  }
}
int findset(int x) {
  if (x!=p[x]) p[x]=findset(p[x]);
  return p[x];
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    b[a[i]]=i; p[i]=i; r[i]=1;
  }
  for (i=1; i<=mx; i++) for (j=1; j<i; j++) if (gcd(i,j)==1 && (i&1)!=(j&1)) {
    d=2*i*j;
    e=i*i+j*j;
    f=i*i-j*j;
    if (e>mx && d>mx) break;
    if (e<=mx && b[e]>0) {
      if (d<=mx && b[d]>0) un(findset(b[d]),findset(b[e]));
      if (f<=mx && b[f]>0) un(findset(b[f]),findset(b[e]));
    }
    if (d<=mx && b[d]>0 && f<=mx && b[f]>0) un(findset(b[d]),findset(b[f]));
  }
  for (i=1; i<=n; i++) if (i==findset(i)) s++;
  printf("%d\n",s);
  return 0;
}