#include <stdio.h>
#define MN 3000
typedef long long LL;

int n,a[MN+5];
int f[MN+5][MN+5],g[MN+5][MN+5];
LL ans;
//f[i][j] : >=ja[i]
//g[i][j] : \sum (k : i+1 ~ j-1) f[k][j] 

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int c=0;
		for(int j=n;j>i;j--){
			if(a[j]==a[i]) c++;
			f[i][j] = c;
		}
	}
	for(int j=1;j<=n;j++){
		int c=0;
		for(int i=j-2;i>=1;i--){
			c += f[i+1][j+1];
			g[i][j] = c;
		}
	}
	ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i]==a[j]) ans += g[i][j];
	printf("%lld\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}