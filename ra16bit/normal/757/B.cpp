#include <cstdio>
#include <algorithm>
using namespace std;
int n,x,i,j,cur,r=1,c[100100];
bool a[100100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    c[x]++;
  }
  for (i=2; i<100100; i++) if (!a[i]) {
    for (cur=0, j=i; j<100100; j+=i) { a[j]=true; cur+=c[j]; }
    r=max(r,cur);
  }
  printf("%d\n",r);
  return 0;
}