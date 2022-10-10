#include <cstdio>
#include <algorithm>
using namespace std;
int all,m,n,x,i,j,k,mn,mx,a,b,c,MN[111],MX[111];
bool good[111];
char s[111];
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d%d",&all,&m);
  for (i=0; i<m; i++) {
    scanf("%d",&x);
	good[x]=true;
  }
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",s);
	scanf("%d",&k);
	for (a=b=c=j=0; j<k; j++) {
	  scanf("%d",&x);
	  if (x==0) b++; else if (good[x]) a++; else c++;
	}
	MN[i]=k-min(all-m,b+c);
	MX[i]=min(m,a+b);
	mn=max(mn,MN[i]);
	mx=max(mx,MX[i]);
  }
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) if (i!=j && MX[j]>MN[i]) break;
	if (j>=n) puts("0"); else if (MX[i]>=mn) puts("2"); else puts("1");
  }
  return 0;
}