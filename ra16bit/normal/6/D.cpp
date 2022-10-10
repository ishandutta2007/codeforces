#include <cstdio>
using namespace std;
int n,i,j,a,b,r=1000000000,h[15],z[15],c[15];
void rec(int l,int s) {
  if (s>=r) return;
  int aa=h[l-1],bb=h[l],cc=h[l+1];
  if (l==n-2) {
   while (h[l-1]>=0 || h[l]>=0 || h[l+1]>=0) { h[l-1]-=b; h[l]-=a; h[l+1]-=b; z[l]++; s++;}
   if (s<r) {
     r=s;
     for (int i=0; i<n; i++) c[i]=z[i];
   }
   h[l-1]=aa; h[l]=bb; h[l+1]=cc; z[l]=0;
   return;
  }
  if (h[l-1]<0) rec(l+1,s);
  while (h[l-1]>=0 || h[l]>=0 || h[l+1]>=0) {
    h[l-1]-=b; h[l]-=a; h[l+1]-=b; z[l]++;
    if (h[l-1]<0) rec(l+1,s+z[l]);
  }
  h[l-1]=aa; h[l]=bb; h[l+1]=cc; z[l]=0;
}
int main() {
  scanf("%d%d%d",&n,&a,&b);
  for (i=0; i<n; i++) scanf("%d",&h[i]);
  rec(1,0);
  printf("%d\n",r);
  for (i=1; i<n-2; i++) for (j=0; j<c[i]; j++) printf("%d ",i+1);
  for (j=1; j<c[n-2]; j++) printf("%d ",n-1);
  printf("%d\n",n-1);
  return 0;
}