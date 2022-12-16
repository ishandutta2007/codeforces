#include <stdio.h>
#define MN 2000
#define MM 2000

using ll = long long;

const int mod = 1000000007;

int n,m,k;
int f[MN+5][MM+5];

void solve(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0) f[i][j] = 0;
			else if(j==i) f[i][j] = (ll)i*k%mod;
			else f[i][j] = (ll)(f[i-1][j-1]+f[i-1][j])*500000004%mod;
		}
	}
	printf("%d\n",f[n][m]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}