#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,a[100100],b[100100];
long long c,m;
bool q,v,w;
int main() {
  scanf("%d%I64d\n",&n,&m);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); b[i+1]=a[i]; }
  sort(b,b+n+1);
  for (i=1; i<=n; i++) if (b[i]!=b[i-1]) {
    c=b[i]-b[i-1];
    if (m<=c*(n-i+1)) {
      q=(m<=(c-1)*(n-i+1));
      v=(m!=c*(n-i+1));
      m%=n-i+1;
      for (j=k=0; j<n && k<m; j++) if (a[j]>=b[i]) k++;
      for (k=j; k<n; k++) if (a[k]>b[i] || (v && a[k]==b[i])) {
        if (w) putchar(' ');
        printf("%d",k+1); w=true;
      }
      for (k=0; k<j; k++) if (a[k]>b[i] || (q && a[k]==b[i])) {
        if (w) putchar(' ');
        printf("%d",k+1); w=true;
      }
      return 0;
    } else m-=c*(n-i+1);
  }
  puts("-1");
  return 0;
}