#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;
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
int S[N][N];
void ysgs(int n) {
	for (int i=S[0][0]=1;i<=n;i++) {
		for (int j=1;j<=i;j++) {
			S[i][j]=(S[i-1][j-1]+1LL*S[i-1][j]*j)%mod;
		}
	}
}
int n,m,k;
void work() {
	int ans=0;
	cin>>n>>m>>k;
	int t=1LL*(m-m/2)*power(m,mod-2)%mod;
	for (int i=0,mul=power(m,n);i<=min(k,n);i++) {
		ans=(ans+1LL*S[k][i]*mul%mod)%mod;
		mul=1LL*mul*(n-i)%mod*t%mod;
	}
	cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ysgs(2e3);
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}