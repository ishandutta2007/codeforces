#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,a[100100],b[100100];
long long ca,cb,sa,sb,best,bb;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); sa+=a[i]; }
  for (i=0; i<m; i++) { scanf("%d",&b[i]); sb+=b[i]; }
  sort(a,a+n);
  sort(b,b+m);
  best=sa+sb;
  for (ca=sa, cb=0, i=n-1; i>=0; i--) {
    ca-=a[i];
    cb+=sb;
    if (ca+cb<=best) best=ca+cb; else break;
  }
  bb=sa+sb;
  for (ca=0, cb=sb, i=m-1; i>=0; i--) {
    ca+=sa;
    cb-=b[i];
    if (ca+cb<=bb) bb=ca+cb; else break;
  }
  printf("%I64d\n",min(best,bb));
  return 0;
}