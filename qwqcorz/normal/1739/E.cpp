#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

template<typename T>
void ckmx(T &x,T y) {
	if (x<y) {
		x=y;
	}
}
int n,a[N][2],dp[N][2][4];
void work() {
	cin>>n;
	for (int j=0;j<=1;j++) {
		string s;
		cin>>s;
		for (int i=1;i<=n;i++) {
			a[i][j]=s[i-1]-'0';
		}
	}
	memset(dp,0xc0,sizeof(dp));
	for (int i=0;i<4;i++) {
		dp[1][0][i]=(a[1][0]&(i&1))+(a[1][1]&((i>>1)&1));
	}
	for (int i=1;i<n;i++) {
		for (int j=0;j<=1;j++) {
			for (int k=0;k<4;k++) {
				if (dp[i][j][k]<0) {
					continue;
				}
//				cerr<<i<<' '<<j<<' '<<k<<':'<<dp[i][j][k]<<"\n";
				for (int t=0;t<4;t++) {
					int b[2][2]={};
					b[0][0]=a[i][0]&(k&1);
					b[0][1]=a[i][1]&((k>>1)&1);
					b[1][0]=a[i+1][0]&(t&1);
					b[1][1]=a[i+1][1]&((t>>1)&1);
					b[0][j]=0;
					int now=j;
					if (b[0][!j]) {
						if (b[1][j]) {
							continue;
						}
						now=!j;
					}
					ckmx(dp[i+1][now][t],dp[i][j][k]+b[1][0]+b[1][1]);
				}
			}
		}
	}
	int ans=0;
	for (int j=0;j<=1;j++) {
		for (int k=0;k<4;k++) {
			ckmx(ans,dp[n][j][k]);
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