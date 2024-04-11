#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
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
int n,a[N],b[N],cnt[N*2][2];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	ysgs(n);
	int mx=0,mn=1e9;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	for (int i=1;i<=n;i++) {
		cin>>b[i];
		cnt[a[i]][b[i]]++;
	}
	int T=mn+n-1;
	if (T<mx) {
		cout<<"0\n";
		return 0;
	}
	if (mn==mx) {
		cout<<fact[n]<<"\n";
		return 0;
	}
	int tot=0,ans=1LL*fact[n]*inv[n-cnt[T][1]]%mod;
	for (int i=mn;i<=mx;i++) {
		if (cnt[i][0]&&tot<T-i) {
			ans=0;
			break;
		}
		tot+=cnt[i][0];
		ans=1LL*ans*fact[cnt[i][0]]%mod;
		if (i<T&&cnt[i][1]&&(cnt[i][1]>1||tot<i-mn)) {
			ans=0;
			break;
		}
		tot+=cnt[i][1];
	}
	cout<<ans<<"\n";
	
	return 0;
}