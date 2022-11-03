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
int a[100010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int T=gi();
	while(T--){
		int n=gi(),l=gi();
		for(int i=1;i<=n;++i)a[i]=gi();
		double P1=0,P2=l,ans=0;
		int p1=0,p2=n+1;
		while(p2-p1>1){
			double t1=(a[p1+1]-P1)/(p1+1),t2=(P2-a[p2-1])/(n-p2+2),t=std::min(t1,t2);
			P1+=(p1+1)*t,P2-=(n-p2+2)*t;ans+=t;
			if(t1<t2)++p1;else--p2;
		}
		printf("%.10lf\n",ans+(P2-P1)*1./(2+n));
	}
	return 0;
}