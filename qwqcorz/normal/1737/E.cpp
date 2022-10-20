#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
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
int pw[N];
void ysgs(int n) {
	for (int i=pw[0]=1;i<=n;i++) {
		pw[i]=pw[i-1]*2%mod;
	}
}
int f[N],s[N];
void work() {
	int n;
	cin>>n;
	int iv=power(pw[n],mod-2),ansn=1;
	f[n]=s[n]=1,s[n+1]=0;
	for (int i=n-1;i>=1;i--) {
		f[i]=(s[i+1]-s[min(i*2,n+1)]+mod+(i*2>n))%mod;
		s[i]=(s[i+1]+f[i])%mod;
	}
	for (int k=1;k<n;k++) {
		int ans=1LL*f[k]*pw[k/2]%mod*iv%mod;
		ansn=(ansn-ans+mod)%mod;
		cout<<ans<<"\n";
	}
	cout<<ansn<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ysgs(1e6);
	int T;
	cin>>T;
	while (T--) {
		work();
	} 
	
	return 0;
}