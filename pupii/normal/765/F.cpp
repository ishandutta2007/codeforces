#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m,a[200010],ua[200010],s[200010],rt[200010],u;
#define mid ((l+r)>>1)
int ls[10000010],rs[10000010],sum[10000010],cnt;
void update(int&x,int l,int r,const int&p){
	++cnt;ls[cnt]=ls[x],rs[cnt]=rs[x],sum[cnt]=sum[x];
	++sum[x=cnt];if(l==r)return;
	if(p<=mid)update(ls[x],l,mid,p);
	else update(rs[x],mid+1,r,p);
}
int query(int x,int y,int l,int r,const int&p){
	if(!(sum[y]-sum[x])||r<=p)return 0;
	if(l==r)return l;
	if(p<=mid){
		int o=query(ls[x],ls[y],l,mid,p);
		return o?o:query(rs[x],rs[y],mid+1,r,p);
	}else return query(rs[x],rs[y],mid+1,r,p);
}
namespace S{
	int mn[800010],mx[800010],tag[800010];
	void Upd(int x,int y){tag[x]=y,mn[x]=mx[x]=y;}
	void down(int x){if(~tag[x])Upd(x<<1,tag[x]),Upd(x<<1|1,tag[x]),tag[x]=-1;}
	void update(int x,int l,int r,const int&L,const int&d){
		if(l^r)down(x);
		if(L<=l){
			if(mn[x]>=d)return Upd(x,d);
			if(mx[x]<=d)return;
		}
		if(L<=mid)update(x<<1,l,mid,L,d);
		update(x<<1|1,mid+1,r,L,d);
		mn[x]=std::min(mn[x<<1],mn[x<<1|1]);
		mx[x]=std::max(mx[x<<1],mx[x<<1|1]);
	}
	int	query(int x,int l,int r,const int&p){
		if(l==r)return mn[x];
		down(x);
		if(p<=mid)return query(x<<1,l,mid,p);
		else return query(x<<1|1,mid+1,r,p);
	}
	void build(int x,int l,int r){
		mn[x]=mx[x]=2e9;tag[x]=-1;if(l==r)return;
		build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	}
}
#undef mid
int getl(int x){return std::lower_bound(ua+1,ua+u+1,x)-ua-1;}
int getr(int x){return std::upper_bound(ua+1,ua+u+1,x)-ua-1;}
int qr[300010],ans[300010];std::vector<int>Q[200010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();
	for(int i=1;i<=n;++i)a[i]=ua[i]=gi();
	std::sort(ua+1,ua+n+1);u=std::unique(ua+1,ua+n+1)-ua-1;
	for(int i=1;i<=n;++i)a[i]=std::lower_bound(ua+1,ua+u+1,a[i])-ua;
	for(int i=1;i<=n;++i)s[i]=i;
	std::sort(s+1,s+n+1,[](int x,int y){return a[x]<a[y];});
	s[0]=-1;
	for(int i=1,j;i<=n;++i){
		j=s[i];
		if(a[j]!=a[s[i-1]])rt[a[j]]=rt[a[j]-1];
		update(rt[a[j]],1,n,j);
	}
	m=gi();
	for(int i=1;i<=m;++i){
		int l=gi();qr[i]=gi();
		Q[l].push_back(i);
	}
	S::build(1,1,n);
	for(int i=n;i;--i){
		int p=i,lst=2e9,o;
		while(lst){
			lst>>=1;
			o=p;p=query(rt[a[i]-1],rt[getr(ua[a[i]]+lst)],1,n,p);
			if(!p)break;
			S::update(1,1,n,p,lst=ua[a[p]]-ua[a[i]]);
		}
		p=i,lst=2e9;
		while(lst){
			lst>>=1;
			o=p;p=query(rt[getl(ua[a[i]]-lst)],rt[a[i]],1,n,p);
			if(!p)break;
			S::update(1,1,n,p,lst=ua[a[i]]-ua[a[p]]);
		}
		for(int j:Q[i])ans[j]=S::query(1,1,n,qr[j]);
	}
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}