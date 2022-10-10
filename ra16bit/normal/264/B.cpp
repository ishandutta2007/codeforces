#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=100000;
int n,i,j,a[MX+10],r[MX+10],b,x,res=1;
int main() {
  for (i=2; i<=MX; i++) if (a[i]==0) for (j=i; j<=MX; j+=i) a[j]=i;
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&b);
    for (x=0, j=b; j>1; j/=a[j]) x=max(x,r[a[j]]);
    for (j=b; j>1; j/=a[j]) r[a[j]]=max(r[a[j]],x+1);
    res=max(res,x+1);
  }
  printf("%d\n",res);
  return 0;
}