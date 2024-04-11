#include <stdio.h>
int n,m,k,i,j,r,p[2020],d[2020],md=1000000007;
bool a[2020];
long long pwm(int b) {
  if (b==0) return 1;
  if (b&1) return (pwm(b-1)*m)%md;
  long long x=pwm(b/2);
  return (x*x)%md;
}
int findset(int x) {
  if (x!=p[x]) p[x]=findset(p[x]);
  return p[x];
}
void un(int a, int b) {
  if (a==b) return;
  if (d[a]<d[b]) p[a]=b; else {
    p[b]=a;
    if (d[a]==d[b]) d[a]++;
  }
}
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=1; i<=n; i++) p[i]=i;
  for (i=1; i+k-1<=n; i++) for (j=0; j<k-1-j; j++) un(findset(i+j),findset(i+k-1-j));
  for (i=1; i<=n; i++) {
    j=findset(i);
    if (!a[j]) { r++; a[j]=true; }
  }
  printf("%d\n",int(pwm(r)));
  return 0;
}