#include <cstdio>
#include <vector>
using namespace std;
int n,m,i,j,k,w,l,r,cnt,a[100100],c[100100],o[100100],d[100100][452];
vector <int> b;
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    if (a[i]<=n) c[a[i]]++;
  }
  for (i=1; i<=n; i++) if (c[i]>=i) {
    b.push_back(i);
    o[i]=b.size();
  }
  k=b.size();
  for (i=1; i<=n; i++) {
    for (j=0; j<k; j++) d[i][j]=d[i-1][j];
    if (a[i]<=n) {
      w=o[a[i]]-1;
      if (w>=0) d[i][w]++;
    }
  }
  while (m--) {
    scanf("%d%d",&l,&r); l--;
    for (cnt=i=0; i<k; i++) if (d[r][i]-d[l][i]==b[i]) cnt++;
    printf("%d\n",cnt);
  }
  return 0;
}