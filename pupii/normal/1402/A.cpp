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
int a[111],b[111],c[111];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int T=gi();
	while(T--){
		int n=gi();
		for(int i=1;i<=n;++i)a[i]=gi();
		for(int i=1;i<=n;++i)b[i]=gi();
		for(int i=1;i<=n;++i)c[i]=gi();
		int lst=0,qwq;
		for(int i=1;i<=n;++i){
			if(lst==a[i])lst=b[i];else lst=a[i];
			if(i==n&&lst==a[1])
				if(c[i]!=qwq)lst=c[i];
				else lst=a[i]+b[i]+c[i]-qwq-a[1];
			printf("%d ",lst);qwq=lst;
		}
		puts("");
	}
	return 0;
}