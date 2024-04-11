#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 1000000007
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int l[200010],r[200010],v[200010],iv[200010],res[200010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),ans=1;
	for(int i=1;i<=n;++i)l[i]=gi();
	for(int i=1;i<=n;++i)r[i]=gi();
	for(int i=1;i<=n;++i)v[i]=r[i]-l[i]+1,iv[i]=pow(v[i],mod-2);
	int sum=0;
	for(int i=1;i<n;++i){
		int len=std::max(0,std::min(r[i],r[i+1])-std::max(l[i],l[i+1])+1);
		sum=(sum+(res[i]=(1ll*v[i]*v[i+1]%mod-len+mod)*iv[i]%mod*iv[i+1]%mod))%mod;
		ans=(ans+res[i]*3ll)%mod;
	}
	for(int i=1;i<=n;++i)ans=(ans+1ll*res[i]*(0ll+sum-res[i]+mod-res[i-1]+mod-res[i+1]+mod))%mod;
	for(int i=1;i<n-1;++i){
		int len1=std::max(0,std::min(r[i],r[i+1])-std::max(l[i],l[i+1])+1);
		int len2=std::max(0,std::min(r[i+2],r[i+1])-std::max(l[i+2],l[i+1])+1);
		int len3=std::max(0,std::min(std::min(r[i],r[i+1]),r[i+2])-std::max(std::max(l[i],l[i+1]),l[i+2])+1);
		int qaq=((1ll*v[i]*v[i+1]%mod-len1+mod)*v[i+2]%mod+(1ll*v[i+2]*v[i+1]%mod-len2+mod)*v[i]%mod-(1ll*v[i]*v[i+1]%mod*v[i+2]%mod-len3+mod)%mod);
		ans=(ans+(2ll*qaq*iv[i]%mod*iv[i+1]%mod*iv[i+2]))%mod;
	}
	printf("%d\n",ans);
	return 0;
}