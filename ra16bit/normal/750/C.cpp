#include <bits/stdc++.h>
using namespace std;
const int inf=2000000000;
int n,le,ri,i,c,d;
int main() {
  scanf("%d",&n);
  le=-inf; ri=inf;
  for (i=0; i<n; i++) {
    scanf("%d%d",&c,&d);
	if (d==1) le=max(le,1900); else ri=min(ri,1899);
	if (le>ri) break;
	if (le!=-inf) le+=c;
	if (ri!=inf) ri+=c;
	if (le>ri) break;
  }
  if (i<n) puts("Impossible"); else if (ri==inf) puts("Infinity"); else printf("%d\n",ri);
  return 0;
}