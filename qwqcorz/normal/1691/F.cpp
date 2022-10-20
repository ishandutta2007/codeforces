#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;

int power(int a,int b) {
	int ret=1;
	for (;b;b/=2) {
		if (b&1) {
			ret=1LL*ret*a%mod;
		}
		a=1LL*a*a%mod;
	}
	return ret;
}
int fact[N],inv[N];
void ysgs(int n) {
	for (int i=fact[0]=1;i<=n;i++) {
		fact[i]=1LL*fact[i-1]*i%mod;
	}
	inv[n]=power(fact[n],mod-2);
	for (int i=n;i>=1;i--) {
		inv[i-1]=1LL*inv[i]*i%mod;
	}
}
int C(int n,int m) {
	if (n<m||m<0) {
		return 0;
	}
	return 1LL*fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int n,k,fa[N],siz[N];
vector<int>e[N];
void dfs(int now,int father) {
	fa[now]=father;
	siz[now]=1;
	for (int to:e[now]) {
		if (to==father) {
			continue;
		}
		dfs(to,now);
		siz[now]+=siz[to];
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ysgs(2e5);
	cin>>n>>k;
	for (int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfs(1,0);
	int ans=0;
	for (int i=1;i<=n;i++) {
		vector<int>a;
		a.emplace_back(n-siz[i]);
		int sum=C(n-siz[i],k);
		for (int to:e[i]) {
			if (to==fa[i]) {
				continue;
			}
			a.emplace_back(siz[to]);
			sum=(sum+C(siz[to],k))%mod;
		}
		for (int i:a) {
			int now=n-i;
			ans=(ans+1LL*i*now%mod*(C(now,k)-(sum-C(i,k)+mod)%mod+mod))%mod;
		}
		ans=(ans+1LL*n*(C(n,k)-sum+mod))%mod;
	}
	cout<<ans<<"\n";
	
	return 0;
}