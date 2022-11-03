#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
//#define pr std::pair<int,int>
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
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
#endif
ll a[200010],ans=1145141919810;
int yes[1000010],pr[1000010],P,n;
void fuck(ll x){
	ll res=0;
	for(int i=1;i<=n;++i)res+=(a[i]<=x?x-a[i]:std::min(a[i]%x,x-a[i]%x));
	ans=std::min(ans,res);
}
std::mt19937 rnd(time(NULL));
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	n=gi();
	int lim;
	for(int i=1;i<=n;++i)a[i]=gi();
	for(int i=2;i<=1000000;++i){
		if(!yes[i])pr[++P]=i;
		for(int j=1;j<=P&&i*pr[j]<=1000000;++j){
			yes[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}
	for(int i=1;i<=P;++i)if(pr[i]<=1000)lim=i;
	for(int i=1;i<=lim;++i)fuck(pr[i]);
	srand(time(NULL));
	int t=20,p;
	while(t--){
		p=rnd()%n+1;
		for(ll x=a[p]-1;x<=a[p]+1;++x)
			if(x){
				ll X=x;
				for(int i=1;i<=lim;++i)while(X%pr[i]==0)X/=pr[i];
				for(int i=lim+1;i<=P;++i)if(X%pr[i]==0){while(X%pr[i]==0)X/=pr[i];fuck(pr[i]);}
				if(X>1)fuck(X);
			}
	}
	printf("%lld\n",ans);
	return 0;
}