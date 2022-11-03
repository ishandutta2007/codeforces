// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,mod;
il int _mod(ll x,int mo){return x<mo?x:x%mo+mo;}
il int pow(int x,int y,int mo){
	int ret=1;
	while(y){
		if(y&1)ret=_mod(1ll*ret*x,mo);
		x=_mod(1ll*x*x,mo);y>>=1;
	}
	return ret;
}
il int phi(int x){
	if(x==1)return 0;
	int ret=x;
	for(int i=2;i*i<=x;++i)
		if(x%i==0){
			ret=ret/i*(i-1);
			while(x%i==0)x/=i;
		}
	if(x>1)ret=ret/x*(x-1);
	return ret;
}
int Mod[233],m,w[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),mod=gi();
	while(mod)Mod[++m]=mod,mod=phi(mod);
	for(int i=1;i<=n;++i)w[i]=gi();
	int q=gi(),l,r;
	while(q--){
		l=gi(),r=gi(),r=std::min(l+m-1,r);
		int p=r-l+1,lst=_mod(w[r],Mod[p--]);
		for(int i=r-1;i>=l;--i)
			lst=pow(w[i],lst,Mod[p--]);
		printf("%d\n",lst%Mod[1]);
	}
	return 0;
}