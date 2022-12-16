#include <stdio.h>
#include <string.h>
#define MN 1000
typedef long long LL;
const int mod = 998244353;

char s[MN+5],t[MN+5];
int f[MN+5][MN+5][2];

int C2(int x){
	return 1ll*x*(x+1)/2%mod;
}

int main(){
	scanf("%s%s",&s[1],&t[1]);
	int n = strlen(&s[1]);
	int m = strlen(&t[1]);
	LL ans = 0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			ans = (ans+f[i][j][0]+f[i][j][1])%mod;
			if(i+1<=n&&s[i+1]!=s[i])
				f[i+1][j][0] = (f[i+1][j][0]+f[i][j][0])%mod;
			if(i+1<=n&&s[i+1]!=t[j])
				f[i+1][j][0] = (f[i+1][j][0]+f[i][j][1])%mod;
			if(j+1<=m&&t[j+1]!=s[i])
				f[i][j+1][1] = (f[i][j+1][1]+f[i][j][0])%mod;
			if(j+1<=m&&t[j+1]!=t[j])
				f[i][j+1][1] = (f[i][j+1][1]+f[i][j][1])%mod;
			if(i+1<=n)
				f[i+1][j][0]++;
			if(j+1<=m)
				f[i][j+1][1]++;
		}
	}
	for(int i=1;i<=n;i++){
		int l=i,r=i;
		while(r+1<=n&&s[r]!=s[r+1]) r++;
		ans = (ans-1ll*C2(r-l+1)*(m+1))%mod;
		i = r;
	}
	for(int i=1;i<=m;i++){
		int l=i,r=i;
		while(r+1<=m&&t[r]!=t[r+1]) r++;
		ans = (ans-1ll*C2(r-l+1)*(n+1))%mod;
		i = r;
	}
	ans = (ans%mod+mod)%mod;
	printf("%lld\n",ans);
}