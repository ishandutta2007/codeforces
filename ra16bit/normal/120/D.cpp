#include <stdio.h>
int n,m,r,i,j,it,x,y,a[55][55],b[55],c[3],u[3];
void add(int x) {
  for (i=0; i<3; i++) if (c[i]==x && u[i]!=it) { u[i]=it; break; }
}
void solve(int n) {
  ++it;
  for (x=1; x<n; x++) b[x]+=b[x-1];
  for (x=0; x<n-1; x++) for (y=x+1; y<n-1; y++) {
    ++it;
    add(b[x]);
    add(b[y]-b[x]);
    add(b[n-1]-b[y]);
    if (u[0]==it && u[1]==it && u[2]==it) r++;
  }
}
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) for (j=0; j<m; j++) scanf("%d",&a[i][j]);
  for (i=0; i<3; i++) scanf("%d",&c[i]);
  if (n>=3) {
    for (i=0; i<n; i++) for (b[i]=j=0; j<m; j++) b[i]+=a[i][j];
    solve(n);
  }
  if (m>=3) {
    for (i=0; i<m; i++) for (b[i]=j=0; j<n; j++) b[i]+=a[j][i];
    solve(m);
  }
  printf("%d\n",r);
  return 0;
}