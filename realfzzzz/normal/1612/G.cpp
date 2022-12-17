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
const int maxm=5e5+5,maxc=1e6+5;
int cnt[maxc];
const ll mod=1e9+7;
ll fac[maxm];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	fac[0]=1;
	for(int i=1;i<maxm;i++) fac[i]=fac[i-1]*i%mod;
	int m=readint();
	ll n=0;
	while(m--){
		int c=readint();
		cnt[c]++;
		n+=c;
	}
	ll ans1=0,ans2=1;
	for(int i=maxc-1;i>1;i--){
		ans1=(ans1+(n-cnt[i])%mod*cnt[i]%mod*(i-1)%mod)%mod;
		ans2=fac[cnt[i]]*fac[cnt[i]]%mod*ans2%mod;
		cnt[i-2]+=cnt[i];
		n-=cnt[i]*2;
	}
	printf("%lld %lld\n",ans1,ans2*fac[cnt[1]]%mod);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}