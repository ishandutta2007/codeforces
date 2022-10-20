#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int B=6;

void ckmx(int &x,int y) {
	if (x<y) {
		x=y;
	}
}
int n,a[N],pre[N],dp[N][N][B];
int calc(int l,int r) {
	if (l<=r) {
		return pre[r]-pre[l-1];
	}
	return 0;
}
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	memset(dp,0xc0,sizeof(dp));
	const int inf=dp[0][0][0];
	dp[0][0][0]=0;
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=n;j++) {
			for (int t=0;t<B;t++) {
				if (dp[i][j][t]==inf) {
					continue;
				}
				ckmx(dp[i+1][j][t],dp[i][j][t]+a[j]);
				if (j<=i&&t+1<B) {
					ckmx(dp[i+1][i+1][t],dp[i][j][t+1]+a[i+1]);
				}
				for (int k=max(i+1,j+1);k<=n;k++) {
					int len=k-i-1,tmp=min(len,t);
					len-=tmp;
					int step=len/2;
					if (len&1) {
						if (t-tmp>=B) {
							continue;
						}
						ckmx(dp[i+step+1][k][t-tmp],dp[i][j][t]+calc(max(j+1,i+1),i+step)+a[k]);
					} else {
						if (t-tmp+1>=B) {
							continue;
						}
						ckmx(dp[i+step+1][k][t-tmp+1],dp[i][j][t]+calc(max(j+1,i+1),i+step)+a[k]);
					}
				}
			}
		}
	}
	int ans=0;
	for (int i=0;i<=n;i++) {
		for (int j=0;j<B;j++) {
			ans=max(ans,dp[n][i][j]);
		}
	}
	cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
//	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}