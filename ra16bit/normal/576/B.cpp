#include <stdio.h>
int n,m,i,j,best,w,cur,c,a[100100],b[100100],st[100100];
bool u[100100];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) if (!u[i]) {
    st[c++]=m;
    for (j=i; !u[j]; j=a[j]) {
      u[j]=true;
      b[m++]=j;
    }
  }
  st[c]=m; best=st[1]-st[0];
  for (i=0; i<c; i++) if (st[i+1]-st[i]<best) { best=st[i+1]-st[i]; w=i; }
  if (best>2) { puts("NO"); return 0; }
  for (i=0; i<c; i++) if ((st[i+1]-st[i])%best) { puts("NO"); return 0; }
  puts("YES");
  if (best==2) printf("%d %d\n",b[st[w]],b[st[w]+1]);
  for (i=0; i<c; i++) if (i!=w) {
    cur=st[i+1]-st[i];
    for (j=0; j<cur; j++) printf("%d %d\n",b[st[i]+j],b[st[w]+j%best]);
  }
  return 0;
}