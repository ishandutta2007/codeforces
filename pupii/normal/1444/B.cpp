#include<bits/stdc++.h>
typedef long long ll;
#define mod 998244353
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
int fact[300010],ifact[300010],a[300010];
int C(int n,int m){return 1ll*fact[n]*ifact[m]%mod*ifact[n-m]%mod;}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),N=n+n;
	fact[0]=1;for(int i=1;i<=N;++i)fact[i]=1ll*fact[i-1]*i%mod;
	ifact[N]=pow(fact[N],mod-2);for(int i=N;i;--i)ifact[i-1]=1ll*ifact[i]*i%mod;
	for(int i=1;i<=N;++i)a[i]=gi();
	std::sort(a+1,a+N+1);
	int ans=0;
	for(int i=1;i<=n;++i)dec(ans,1ll*a[i]*C(2*n-1,n-1)%mod);
	for(int i=n+1;i<=N;++i)inc(ans,1ll*a[i]*C(2*n-1,n-1)%mod);
	printf("%d\n",ans*2%mod);
	return 0;
}