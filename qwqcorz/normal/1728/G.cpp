#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int M=20;
const int mod=998244353;

int d,n,m,l[N],p[M],e[M][M],f[1<<16],g[1<<16];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>d>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>l[i];
	}
	for (int i=1;i<=m;i++) {
		cin>>p[i];
	}
	sort(p+1,p+1+m);
	p[0]=-1e9,p[m+1]=1e9;
	for (int i=0;i<=m+1;i++) {
		for (int j=0;j<=m+1;j++) {
			e[i][j]=1;
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=m&&p[j]<l[i];j++) {
			for (int k=m+1;k>=1&&p[k]>l[i];k--) {
				e[j][k]=1LL*e[j][k]*min({l[i]-p[j],p[k]-l[i],d+1})%mod;
			}
		}
	}
	for (int S=0;S<(1<<m);S++) {
		vector<int>pos({0});
		for (int i=0;i<m;i++) {
			if (S>>i&1) {
				pos.push_back(i+1);
			}
		}
		pos.push_back(m+1);
		f[S]=__builtin_popcount(S)%2?mod-1:1;
		for (int i=0;i+1<(int)pos.size();i++) {
			f[S]=1LL*f[S]*e[pos[i]][pos[i+1]]%mod;
		}
		g[S]=f[S];
	}
	for (int i=0;i<m;i++) {
		for (int S=(1<<m)-1;S>=0;S--) {
			if (S>>i&1) {
				g[S]=(g[S]+g[S^(1<<i)])%mod;
			}
		}
	}
	int Q;
	cin>>Q;
	while (Q--) {
		int x,ans=1LL*f[0]*(d+1)%mod;
		cin>>x;
		pair<int,int>a[M];
		for (int i=1;i<=m;i++) {
			a[i]={abs(p[i]-x),i};
		}
		sort(a+1,a+1+m);
		for (int i=m,j=m,S=0;i>=1;i--) {
			if (i==1||a[i].first!=a[i-1].first) {
				int d=a[i].first,now=g[S];
				for (int k=i;k<=j;k++) {
					S|=1<<(a[k].second-1);
				}
				now=(g[S]-now+mod)%mod;
				ans=(ans+1LL*now*d)%mod;
				j=i-1;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}