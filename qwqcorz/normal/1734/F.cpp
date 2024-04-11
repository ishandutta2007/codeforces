#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=64;

ll n,m,dp[N][2][2][2];
void work() {
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	dp[61][0][0][1]=1;
	for (int i=60;i>=0;i--) {
		for (int x=0;x<=1;x++) {
			for (int y=0;y<=1;y++) {
				for (int z=0;z<=1;z++) {
					ll now=dp[i+1][x][y][z];
					if (!now) {
						continue;
					}
					for (int t=0;t<=(z?(m>>i&1):1);t++) {
						int tmp=t+(n>>i&1),nz=z&&t==(m>>i&1);
						if (tmp>1) {
							dp[i][0][!y^x][nz]+=now;
						}
						if (tmp==1) {
							dp[i][!x][y][nz]+=now;
						}
						if (tmp==0) {
							dp[i][0][y][nz]+=now;
						}
					}
				}
			}
		}
	}
	ll ans=0;
	for (int i=0;i<=1;i++) {
		ans+=dp[0][i][!(__builtin_popcountll(n)&1)][0];
	}
	cout<<ans<<"\n";
} 

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}
/*
5
1 1
5 10
34 211
73 34
19124639 56348772

*/