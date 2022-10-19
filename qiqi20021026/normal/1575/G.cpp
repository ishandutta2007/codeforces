#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y)	for(ll i=(ll)(x);i<=(ll)(y);++i)
#define rep(i,x,y)	for(ll i=(ll)(x);i<(ll)(y);++i)
ll read(){
	ll x;scanf("%lld",&x);
	return x;
}
const ll mod=1000000007;
const ll N=100010,p=100000,K=150;
ll n,a[N],c[N],w[N],mu[N],pr[N],tot,q[N],ans;
bool vis[N];
inline ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}

ll calc(){
	ll ret=0;
	for (ll i=1;i<=p;++i){
		ll sum=0;
		for (ll j=i;j<=p;j+=i) sum+=c[j];
		sum*=sum;
		ret+=sum%mod*w[i]%mod;
	}
	return ret%mod;
}

int main(){
	n=read();
	For(i,1,n)a[i]=read();
//	n=100000;
//	For(i,1,n)a[i]=n-i+1;
	mu[1]=1;
	for (ll i=2;i<=p;++i){
		if (!vis[i]){
			pr[++tot]=i;
			mu[i]=-1;
		}
		for (ll j=1;j<=tot;++j){
			if (i*pr[j]>p) break;
			vis[i*pr[j]]=1;
			if (i%pr[j]==0) mu[i*pr[j]]=0;
			else mu[i*pr[j]]=-mu[i];
			if (i%pr[j]==0) break;
		}
	}
	for (ll i=1;i<=p;++i){
		for (ll j=1;i*j<=p;++j){
			w[i*j]+=mu[i]*j;
		}
	}
	For(i,1,n){
		ll m=0;
		for(ll j=i;j<=n;j+=i){
			q[++m]=a[j];
		}
		if (m<=K){
			ll sum=0;
			for (ll x=1;x<=m;++x)
				for (ll y=1;y<=m;++y) sum+=gcd(q[x],q[y]);
			ans+=sum%mod*w[i]%mod;
		}
		else{
			memset(c,0,sizeof c);
			for (ll x=1;x<=m;++x) ++c[q[x]];
			ans+=calc()*w[i]%mod;
		}
	}
	printf("%lld\n",(ans%mod+mod)%mod);
	
	return 0;
}