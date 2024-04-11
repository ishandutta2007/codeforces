#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e6+5;

bool vis[N];
int n,m,cnt[N],dp[N];
void work() {
	cin>>n>>m;
	int mn=m,ans=m;
	for (int i=1;i<=n;i++) {
		int x;
		cin>>x;
		vis[x]=1;
		mn=min(mn,x);
	}
	for (int i=1;i<=m;i++) {
		dp[i]=m+1;
		if (vis[i]) {
			cnt[dp[i]]++;
		}
	}
	int mx=m;
	for (int i=m;i>=1;i--) {
		if (vis[i]) {
			cnt[dp[i]]--;
		}
		dp[i]=i;
		if (vis[i]) {
			cnt[dp[i]]++;
		}
		if (1LL*i*i<=m) {
			for (int j=i*i;j<=m;j+=i) {
				if (vis[j]) {
					cnt[dp[j]]--;
				}
				dp[j]=min(dp[j],dp[j/i]);
				if (vis[j]) {
					cnt[dp[j]]++;
				}
			}
		}
		if (i<=mn) {
			while (!cnt[mx]) {
				mx--;
			}
			ans=min(ans,mx-i);
		}
	}
	cout<<ans<<"\n";
	for (int i=1;i<=m+1;i++) {
		dp[i]=cnt[i]=vis[i]=0;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}