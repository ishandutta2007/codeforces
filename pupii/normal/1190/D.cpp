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
#ifdef mod
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
struct point{int x,y;}s[200010];
int ux[200010],m;
int t[200010];
il vd update(int p){while(p<=m)++t[p],p+=p&-p;}
il int query(int p){int r=0;while(p)r+=t[p],p-=p&-p;return r;}
il ll c2(int n){return 1ll*n*(n+1)/2;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)s[i].x=gi(),s[i].y=gi(),ux[++m]=s[i].x;
	std::sort(ux+1,ux+n+1);m=std::unique(ux+1,ux+n+1)-ux-1;
	for(int i=1;i<=n;++i)s[i].x=std::lower_bound(ux+1,ux+m+1,s[i].x)-ux;
	std::sort(s+1,s+n+1,[](point a,point b){return a.y==b.y?a.x<b.x:a.y>b.y;});
	ll ans=0;
	for(int l=1,r;l<=n;l=r+1){
		r=l;while(r<n&&s[r+1].y==s[l].y)++r;
		int lst=0;
		for(int i=l;i<=r;++i){
			int qi=query(s[i].x-1);
			ans-=c2(qi-lst);
			lst=query(s[i].x);
		}
		ans-=c2(query(m)-lst);
		for(int i=l;i<=r;++i)if(query(s[i].x)==query(s[i].x-1))update(s[i].x);
		ans+=c2(query(m));
	}
	printf("%lld\n",ans);
	return 0;
}