#include <stdio.h>
#define MN 2000
const int mod = 1000000007;

char c[MN+5][MN+5];

void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",&c[i][1]);
	int cnt = 0;
	int ans = 1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(c[i][j]=='#'){
				cnt++;
				ans = ans*2%mod;
			}
	if(cnt==n*m) ans--;
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}