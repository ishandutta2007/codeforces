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
int L[100010],ans[100010];
ll sufL[100010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=1;i<=m;++i)L[i]=gi();
	for(int i=m;i;--i)sufL[i]=sufL[i+1]+L[i];
	L[0]=1;
	for(int i=1;i<=m;++i){
		ans[i]=std::max(ans[i-1]+1ll,n-sufL[i]+1);
		if(ans[i]>ans[i-1]+L[i-1]||ans[i]>n-L[i]+1)puts("-1"),exit(0);
	}
	for(int i=1;i<=m;++i)printf("%d ",ans[i]);
	return 0;
}