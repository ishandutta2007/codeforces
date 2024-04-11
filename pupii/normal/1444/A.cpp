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
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int t=gi();
	while(t--){
		ll p=gi(),q=gi(),ans=1;
		auto check=[&](int i){
			ll res=p,_p=p;
			int eq=0,ep=0;
			while(_p%i==0)_p/=i,++ep;
			while(q%i==0)q/=i,++eq;
			if(ep<eq)cxk(ans,res);
			else{
				for(int j=0;j<ep-eq+1;++j)res/=i;
				cxk(ans,res);
			}
		};
		for(int i=2;i*i<=q;++i)if(q%i==0)check(i);
		if(q>1)check(q);
		printf("%lld\n",ans);
	}
	return 0;
}