//bear and paradox
#include<bits/stdc++.h>
typedef long long ll;
#define all(x) (x).begin(),(x).end()
#define pr std::pair<int,int>
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
ll gi(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct qwq{int a,t;}s[200010];
double fmx[200010],fmn[200010],uf[400010];
int n,N,st[200010];
int main(){
	n=gi();N=n+n;
	for(int i=1;i<=n;++i)s[i].a=gi();
	ll T=0;
	for(int i=1;i<=n;++i)T+=s[i].t=gi();
	std::sort(s+1,s+n+1,[](const qwq&a,const qwq&b){
		if(1ll*a.a*b.t!=1ll*b.a*a.t)return 1ll*a.a*b.t>1ll*b.a*a.t;
		return a.a<b.a;
	});
	for(int i=1;i<=n;++i)st[i]=i;std::sort(st+1,st+n+1,[](int a,int b){return s[a].a<s[b].a;});
	double l=0,r=1,mid;
	while(r-l>1e-8){
		mid=(l+r)*0.5;
		ll now=0,S;
		for(int l=1,r;l<=n;l=r+1){
			r=l;while(r<n&&1ll*s[r+1].a*s[r].t==1ll*s[r+1].t*s[r].a)++r;
			S=0;for(int i=l;i<=r;++i)S+=s[i].t;
			for(int i=l;i<=r;++i)fmx[i]=s[i].a*(1-mid*(now+s[i].t)/T),fmn[i]=s[i].a*(1-mid*(now+S)/T);
			now+=S;
		}
		for(int i=1;i<=n;++i)uf[i]=fmx[i],uf[i+n]=fmn[i];
		std::sort(uf+1,uf+n+n+1);
		bool flg=1;double MX=-1e18;
		now=0;
		for(int l=1,r;l<=n;l=r+1){
			r=l;while(r<n&&s[st[r+1]].a==s[st[r]].a)++r;
			for(int i=l;i<=r;++i)if(fmn[st[i]]<MX)flg=0;
			for(int i=l;i<=r;++i)cxk(MX,fmx[st[i]]);
		}
		if(flg)l=mid;else r=mid;
	}
	printf("%.8lf\n",l);
	return 0;
}