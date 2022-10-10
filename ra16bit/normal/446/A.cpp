#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,r,cur,a[100100],b[100100];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    if (a[i]>a[i-1]) b[i]=b[i-1]+1; else b[i]=1;
  }
  for (i=n; i>0; i--) {
    r=max(r,b[i-1]+1);
    r=max(r,cur+1);
    if (i==1 || i==n || a[i-1]+1<a[i+1]) r=max(r,b[i-1]+cur+1);
    if (a[i]<a[i+1]) cur++; else cur=1;
  }
  printf("%d\n",r);
  return 0;
}