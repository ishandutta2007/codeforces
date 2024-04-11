#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e6+5;
int n;
const ll mod=1e9+7,inv2=5e8+4;
ll ipw[maxn],f[maxn],ans[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		if(n==1){
			printf("1\n");
			continue;
		}
		ipw[0]=1;
		for(int i=1;i<=n;i++) ipw[i]=ipw[i-1]*inv2%mod;
		f[n]=1;
		for(int i=n-1;i>1;i--){
			ll r=i*2<=n?ipw[i]*f[i*2]%mod:0;
			f[i]=(f[i+1]-r+mod)%mod;
			ans[i]=(f[i+1]-r*2%mod+mod)%mod*ipw[(i+1)/2]%mod;
		}
		ans[n]=1;
		for(int i=1;i<n;i++) ans[n]=(ans[n]-ans[i]+mod)%mod;
		for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}