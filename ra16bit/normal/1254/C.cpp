#include <bits/stdc++.h>
using namespace std;
int n,m,i,cur,z,k[1010],c[1010];
long long r[1010];
bool cmp(int i, int j) { return r[i]>r[j]; }
int main() {
  scanf("%d",&n);
  cur=2;
  for (i=3; i<=n; i++) {
    printf("2 1 %d %d\n",cur,i);
    fflush(stdout);
    scanf("%d",&z);
    if (z<0) cur=i;
  }
  for (i=2; i<=n; i++) if (i!=cur) {
    printf("1 1 %d %d\n",cur,i);
    fflush(stdout);
    scanf("%I64d",&r[i]);
    k[m++]=i;
  }
  sort(k,k+m,cmp);
  for (i=1; i<m; i++) {
    printf("2 1 %d %d\n",k[0],k[i]);
    fflush(stdout);
    scanf("%d",&c[i]);
  }
  printf("0 %d %d ",1,cur);
  for (i=m-1; i>0; i--) if (c[i]<0) printf(" %d",k[i]);
  printf(" %d",k[0]);
  for (i=1; i<m; i++) if (c[i]>0) printf(" %d",k[i]);
  puts("");
  fflush(stdout);
  return 0;
}