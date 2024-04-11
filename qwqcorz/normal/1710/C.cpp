#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int mod=998244353;

void add(int &x,int y) {
	x+=y;
	if (x>=mod) {
		x-=mod;
	}
}
int a[N],dp[N][8][2][2][2];
void work() {
	string s;
	cin>>s;
	int n=s.size();
	for (int i=1;i<=n;i++) {
		a[i]=s[i-1]-'0';
	}
	dp[0][0][1][1][1]=1;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<8;j++) {
			for (int x=0;x<=1;x++) {
				for (int y=0;y<=1;y++) {
					for (int z=0;z<=1;z++) {
						int now=dp[i-1][j][x][y][z];
						if (!now) {
							continue;
						}
						for (int u=0;u<=(x?a[i]:1);u++) {
							for (int v=0;v<=(y?a[i]:1);v++) {
								for (int w=0;w<=(z?a[i]:1);w++) {
									int nx=x&(u==a[i]),ny=y&(v==a[i]),nz=z&(w==a[i]);
									if (u==v&&v==w) {
										add(dp[i][j][nx][ny][nz],now);
									} else {
										int k=j;
										if (u==v) {
											k|=1;
										}
										if (u==w) {
											k|=2;
										}
										if (v==w) {
											k|=4;
										}
										add(dp[i][k][nx][ny][nz],now);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int ans=0;
	for (int x=0;x<=1;x++) {
		for (int y=0;y<=1;y++) {
			for (int z=0;z<=1;z++) {
				add(ans,dp[n][7][x][y][z]);
			}
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