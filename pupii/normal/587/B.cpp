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
int a[1000010],c[1000010],d[1000010];
std::map<int,int>M1,M2;
std::vector<int>_;
std::vector<std::vector<int>>f;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	ll n=gi(),l=gi(),k=gi(),m=l%n,N=n,K=std::min(k,l/N);
	for(int i=1;i<=n;++i){
		int a=gi();
		++M1[a];if(i<=m)++M2[a];
	}
	n=0;
	for(auto[x,C]:M1)a[++n]=x,c[n]=C,d[n]=M2[x];
	_.resize(n+1);f.resize(K+1);
	for(auto&s:f)s=_;
	for(int i=1;i<=n;++i)f[0][i]=1;
	for(int i=1;i<=K;++i)
		for(int j=1;j<=n;++j)
			f[i][j]=(f[i][j-1]+1ll*f[i-1][j]*c[j])%mod;
	int ans=m;
	for(int i=1;i<=K;++i)ans=(ans+1ll*(l/N%mod-i+1+mod)%mod*f[i][n])%mod;
	for(int i=1;i<=K;++i){
		if(i==k)continue;
		for(int j=1;j<=n;++j)
			ans=(ans+1ll*f[i][j]*d[j])%mod;
	}
	printf("%d\n",ans);
	return 0;
}