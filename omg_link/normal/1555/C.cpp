#include <stdio.h>
#include <algorithm>
#define MM 100000

using std::max;
using std::min;

int m,a[2][MM+5];

void solve(){
	scanf("%d",&m);
	for(int i=0;i<2;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	a[0][m+1] = a[1][0] = 0;
	for(int j=m;j>=1;j--)
		a[0][j] += a[0][j+1];
	for(int j=1;j<=m;j++)
		a[1][j] += a[1][j-1];
	int ans = 0x7fffffff;
	for(int j=1;j<=m;j++)
		ans = min(ans,max(a[0][j+1],a[1][j-1]));
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}