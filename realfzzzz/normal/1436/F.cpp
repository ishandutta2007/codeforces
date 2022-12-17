#include<vector>
#include<cstdio>
#include<cctype>
using namespace std;
inline int readint(){
	int x=0;
	char c=getchar();
	bool f=0;
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
const int maxm=1e5+5;
int c[maxm];
typedef long long ll;
const ll mod=998244353;
const int S=4e4;
ll pw1[maxm],pw2[maxm];
ll ksm(ll b){
	b=(b%(mod-1)+mod-1)%(mod-1);
	return pw1[b%S]*pw2[b/S]%mod;
}
int mf[maxm];
vector<int> p;
ll mu[maxm];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	for(int i=2;i<maxm;i++){
		if(!mf[i]) p.push_back(i);
		for(int j=0;j<(int)p.size()&&1ll*i*p[j]<maxm;j++){
			mf[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
	mu[1]=1;
	for(int i=2;i<maxm;i++)
		if(!mf[i]) mu[i]=mod-1;
		else{
			if(i/mf[i]%mf[i]==0) mu[i]=0;
			else mu[i]=mu[mf[i]]*mu[i/mf[i]]%mod;
		}
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=S;i++) pw1[i]=pw1[i-1]*2%mod;
	for(int i=1;i<=S;i++) pw2[i]=pw2[i-1]*pw1[S]%mod;
	int m=readint();
	while(m--){
		int a=readint();
		c[a]=readint();
	}
	ll ans=0;
	for(int i=1;i<maxm;i++) if(mu[i]){
		ll tot=0;
		for(int j=i;j<maxm;j+=i) tot+=c[j];
		ll res=0,s=0;
		for(int j=i;j<maxm;j+=i){
			res=(res+(tot-1+mod)%mod*ksm(tot-2)%mod*j%mod*j%mod*c[j]%mod)%mod;
			res=(res+tot%mod*ksm(tot-2)%mod*j%mod*s%mod*c[j]%mod)%mod;
			res=(res+tot%mod*ksm(tot-3)%mod*j%mod*j%mod*c[j]%mod*(c[j]-1)%mod)%mod;
			s=(s+1ll*j*c[j]%mod)%mod;
		}
		ans=(ans+res*mu[i]%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}