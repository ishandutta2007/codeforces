#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,k,r,cur,z[1000100],a[1000100];
char s[1000100];
int main() {
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  for (i=1; i<n; i++) {
    if (r>i) z[i]=min(r-i,z[i-k]);
    if (i+z[i]>=r) {
      while (i+z[i]<n && s[i+z[i]]==s[z[i]]) z[i]++;
      k=i; r=i+z[i];
    }
  }
  for (i=1; i*m<=n; i++) {
    for (j=i, k=1; k<m; k++, j+=i) if (z[j]<i) break;
    if (k==m) {
      a[j-1]++;
      a[j+min(z[j],i)]--;
    }
  }
  for (i=0; i<n; i++) {
    cur+=a[i];
    putchar(cur?'1':'0');
  }
  return 0;
}