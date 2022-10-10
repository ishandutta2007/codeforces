#include <cstdio>
#include <vector>
using namespace std;
const int MX=100010;
int n,m,i,j,k,x,y,all,sbn,a[MX],p[MX],last[MX],cnt[MX],sb[MX],bad[MX],r[MX];
vector<int> b[MX],c[MX];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
	b[y].push_back(x);
	c[y].push_back(i);
  }
  for (i=1; i<=n; i++) {
    if (last[a[i]]>0) {
	  for (k=last[a[i]]; k<MX; k=(k<<1)-(k&(k-1))) cnt[k]--;
      if (i-last[a[i]]!=last[a[i]]-p[last[a[i]]]) {
	    if (sb[a[i]]>0) {
		  for (k=sb[a[i]]; k<MX; k=(k<<1)-(k&(k-1))) bad[k]--;
		} else if (p[last[a[i]]]>0) sbn++;
		sb[a[i]]=p[last[a[i]]];
		if (sb[a[i]]>0) for (k=sb[a[i]]; k<MX; k=(k<<1)-(k&(k-1))) bad[k]++;
	  }
	} else all++;
	p[i]=last[a[i]];
	last[a[i]]=i;
	for (k=i; k<MX; k=(k<<1)-(k&(k-1))) cnt[k]++;
	for (j=0; j<b[i].size(); j++) {
	  int diff=all,scur=sbn;
	  for (k=b[i][j]-1; k>0; k&=k-1) {
	    diff-=cnt[k];
		scur-=bad[k];
	  }
	  r[c[i][j]]=diff+int(scur==diff);
	}
  }
  for (i=0; i<m; i++) printf("%d\n",r[i]);
  return 0;
}