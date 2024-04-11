#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n,k;
const ll mod=1e9+7;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2==1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
int np[maxn*2];
vector<int> p;
ll mu[maxn*2];
vector<int> fac[maxn*2];
ll pw[maxn*2];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	mu[1]=1;
	for(int i=2;i<=n*2-2;i++){
		if(!np[i]){
			p.push_back(i);
			mu[i]=mod-1;
		}
		for(int j:p){
			if(1ll*i*j>n*2-2) break;
			np[i*j]=1;
			if(i%j==0) break;
			else mu[i*j]=(mod-mu[i])%mod;
		}
	}
	for(int i=1;i<=n*2-2;i++)
		for(int j=1;i*j<=n*2-2;j++) fac[i*j].push_back(i);
	pw[0]=1;
	for(int i=1;i<=n*2-2;i++) pw[i]=pw[i-1]*k%mod;
	ll ans=0;
	for(int i=2;i<=n*2-2;i++) for(int j:fac[i]){
		ll s=0;
		int l=max(i/j-(n-1)/j,1),r=min((n-1)/j,i/j-1);
		for(int k:fac[i/j])
			s=(s+(r/k-(l-1)/k+mod)%mod*mu[k]%mod)%mod;
		ans=(ans+pw[max(i-n,j)]*s%mod)%mod;
	}
	printf("%lld\n",ans*ksm(pw[n],mod-2)%mod);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}