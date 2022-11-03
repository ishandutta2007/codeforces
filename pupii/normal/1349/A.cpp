#include<bits/stdc++.h>
typedef long long ll;
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
int s[200010],cs[200010],c[200010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=200000;++i)cs[i]=s[i]=1e9;
	for(int _=0;_<n;++_){
		int x=gi();
		for(int i=2;i*i<=x;++i)
			if(x%i==0){
				int e=0;
				while(x%i==0)++e,x/=i;
				++c[i];
				if(e<s[i])cs[i]=s[i],s[i]=e;
				else cnk(cs[i],e);
			}
		if(x>1){
			++c[x];
			if(1<s[x])cs[x]=s[x],s[x]=1;
			else cnk(cs[x],1);
		}
	}
	ll ans=1;
	for(int i=1;i<=200000;++i)
		if(c[i]==n)for(int j=0;j<cs[i];++j)ans*=i;
		else if(c[i]==n-1)for(int j=0;j<s[i];++j)ans*=i;
	printf("%lld\n",ans);
	return 0;
}