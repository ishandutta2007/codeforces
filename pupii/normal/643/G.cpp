#include<bits/stdc++.h>
#define pr std::pair<int,int>
#define fi first
#define se second
#define data std::vector<pr>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m,p,k;
bool cmp(const pr&a,const pr&b){return a.se>b.se;}
data operator+(const data&a,const data&b){
	data c;int i=0,j=0;
	while(i<a.size()||j<b.size())
		if(i<a.size()&&j<b.size()&&a[i].fi==b[j].fi)c.push_back({a[i].fi,a[i].se+b[j].se}),++i,++j;
		else if(i<a.size()&&(j==b.size()||a[i].fi<b[j].fi))c.push_back(a[i++]);
		else c.push_back(b[j++]);
	if(c.size()>k){
		std::sort(c.begin(),c.end(),cmp);
		for(int i=c.size()-1;i>=k;--i)
			for(int j=i-k;j<i;++j)
				c[j].se-=c[i].se;
		c.resize(k),std::sort(c.begin(),c.end());
	}
	return c;
}
int a[150010];
data seg[600010];
#define mid ((l+r)>>1)
void build(int x,int l,int r){
	if(l==r){seg[x].push_back({a[l],1});return;}
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
int tag[600010];
void upd(int x,int l,int r,int t){
	tag[x]=t;
	seg[x].clear();
	seg[x].push_back({t,r-l+1});
}
void down(int x,int l,int r){if(tag[x])upd(x<<1,l,mid,tag[x]),upd(x<<1|1,mid+1,r,tag[x]),tag[x]=0;}
void update(int x,int l,int r,int L,int R,int d){
	if(L<=l&&r<=R)return upd(x,l,r,d);
	down(x,l,r);
	if(L<=mid)update(x<<1,l,mid,L,R,d);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,d);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
data query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R)return seg[x];
	down(x,l,r);
	if(L<=mid)
		if(mid<R)return query(x<<1,l,mid,L,R)+query(x<<1|1,mid+1,r,L,R);
		else return query(x<<1,l,mid,L,R);
	else return query(x<<1|1,mid+1,r,L,R);
}
#undef mid
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi(),p=gi(),k=100/p;
	for(int i=1;i<=n;++i)a[i]=gi();
	build(1,1,n);
	int o,l,r,d;
	while(m--){
		o=gi();l=gi(),r=gi();
		if(o==1)d=gi(),update(1,1,n,l,r,d);
		else{
			data x=query(1,1,n,l,r);
			printf("%d ",x.size());
			for(auto i:x)printf("%d ",i.fi);
			puts("");
		}
	}
	return 0;
}