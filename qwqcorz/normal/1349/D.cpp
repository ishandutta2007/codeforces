#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const int mod=998244353;

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
int inv(int a) {
	if (a>=mod) a%=mod;
	return power(a,mod-2);
}
int n,a[N],f[N],g[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int m=0;
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		m+=a[i];
	}
	g[0]=n-1;
	for (int i=1;i<m;i++) {
		g[i]=(1LL*m*(n-1)+1LL*i*(n-1)%mod*g[i-1])%mod*inv(m-i)%mod;
	}
	for (int i=m-1;i>=0;i--) {
		f[i]=(f[i+1]+g[i])%mod;
	}
	int ans=0;
	for (int i=1;i<=n;i++) {
		ans=(ans+f[a[i]])%mod;
	}
	ans=1LL*(ans-1LL*(n-1)*f[0]%mod+mod)*inv(n)%mod;
	cout<<ans<<"\n";
	
	return 0;
}