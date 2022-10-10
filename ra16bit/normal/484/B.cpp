#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=2100000;
int n,i,j,r,x,last[MX];
bool u[MX];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    u[x]=true;
  }
  for (i=1; i<MX; i++) last[i]=u[i-1]?(i-1):last[i-1];
  for (i=1; i<MX; i++) if (u[i])
    for (j=i+i; j<MX; j+=i) r=max(r,last[j]-j+i);
  printf("%d\n",r);
  return 0;
}