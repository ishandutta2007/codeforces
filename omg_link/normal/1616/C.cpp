#include <stdio.h>
#include <algorithm>
#define MN 70

const int INF = 0x7fffffff;

using std::min;

int n,a[MN+5];

int solve(int p1,int p2){
	static int b[MN+5];
	for(int i=1;i<=n;i++)
		b[i] = a[i]*(p2-p1);
	int d = (b[p2]-b[p1])/(p2-p1);
	int b0 = b[p1]-p1*d;
	int ans = 0;
	for(int i=1;i<=n;i++)
		if(b[i]!=b0+i*d) ans++;
	return ans;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==1){
		puts("0");
		return;
	}
	int ans = INF;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans = min(ans,solve(i,j));
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}