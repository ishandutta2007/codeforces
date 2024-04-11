#include<bits/stdc++.h>
typedef long long ll;
#define db long double
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
struct line{db k,b;int p;};
db crx(const line&a,const line&b){return(a.b-b.b)/(b.k-a.k);}
double a[1000010],S[1000010];
line stk[1000010];
int nxt[1000010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)S[i]=(a[i]=gi())+S[i-1];
	int tp=0;
	stk[tp=1]={-n,S[n],n};
	for(int i=n-1;~i;--i){
		line now={-i,S[i],i};
		while(tp>1&&crx(now,stk[tp])+1e-14>crx(now,stk[tp-1]))--tp;
		if(i==n)nxt[i]=n;
		else nxt[i+1]=stk[tp].p;
		stk[++tp]=now;
	}
	for(int l=1,r;l<=n;l=r+1){
		r=nxt[l];
		db s=(S[r]-S[l-1])/(r-l+1);
		for(int i=l;i<=r;++i)printf("%.12lf\n",(double)s);
	}
	return 0;
}