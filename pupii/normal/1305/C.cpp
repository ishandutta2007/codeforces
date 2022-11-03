#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#define pr std::pair<int,int>
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
//#ifdef mod
int mod;
int pow(int x,ll y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
//#endif
ll a[200010],t[1010],T[1010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi();mod=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int x=a[i]%mod;
		for(int j=0;j<mod;++j,x=x?x-1:mod-1)T[x]+=t[j];
		++t[a[i]%mod];
	}
	int ans=1;for(int i=0;i<mod;++i)ans=1ll*ans*pow(i,T[i])%mod;
	printf("%d\n",ans%mod);
	return 0;
}