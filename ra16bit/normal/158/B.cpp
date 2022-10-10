#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,a,b[5],d,r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&a); b[a]++; }
  r=b[4]; b[4]=0;
  d=min(b[1],b[3]);
  r+=b[3]; b[1]-=d; b[3]=0;
  d=b[2]/2;
  r+=d; b[2]-=2*d;
  if (b[2]>0) {
    b[2]=0; r++;
    if (b[1]>0) b[1]--;
    if (b[1]>0) b[1]--;
  }
  r+=(b[1]+3)/4;
  printf("%d\n",r);
  return 0;
}