#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 220
#define M 1200

const LL mod=1000000007;
int n,m,ans,a[N],f[N][N][M];

void upd(int &x,LL y){x=(x+y)%mod;}

int main(){
	scanf("%d%d",&n,&m);
	for (LL i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	f[1][1][0]=f[1][0][0]=1;
	for (LL i=1;i<n;++i)
		for (LL j=0;j<=n;++j){
			LL t=a[i+1]-a[i]; t*=j;
			for (LL k=0;k<=m-t;++k){
				upd(f[i+1][j][k+t],(LL)f[i][j][k]*(j+1)%mod);
				upd(f[i+1][j+1][k+t],f[i][j][k]);
				if (j) upd(f[i+1][j-1][k+t],(LL)f[i][j][k]*j%mod);
			}
		}
	for (LL i=0;i<=m;++i) upd(ans,f[n][0][i]);
	printf("%d\n",ans);
	
	return 0;
}