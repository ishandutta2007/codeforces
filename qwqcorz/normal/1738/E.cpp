#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
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
	return 1LL*fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int n,a[N];
ll pre[N],suf[N];
void work() {
	int ans=1;
	cin>>n;
	for (int i=0;i<=n+1;i++) {
		pre[i]=suf[i]=0;
	}
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	for (int i=n;i>=1;i--) {
		suf[i]=suf[i+1]+a[i];
	}
	for (int i=1,j=n;i<=n;) {
		ll col=pre[i];
		while (j>=1&&suf[j]<col) {
			j--;
		}
		int t1=0,t2=0,len=j-i+1;
		while (i<=n&&pre[i]==col) {
			i++,t1++;
		}
		while (j>=1&&suf[j]==col) {
			j--,t2++;
		}
//		cerr<<t1<<','<<t2<<endl;
		if (i>j) {
			for (int k=1;k<len;k++) {
				ans=ans*2%mod;
			}
			break;
		}
		if (t1&&t2) {
			int now=0;
			for (int k=0;k<=t1&&k<=t2;k++) {
				now=(now+1LL*C(t1,k)*C(t2,k))%mod;
			}
			ans=1LL*ans*now%mod;
		}
	}
	cout<<ans<<"\n";
} 

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ysgs(1e5);
	int T;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}