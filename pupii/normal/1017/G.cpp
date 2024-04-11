#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,q;
int fir[100010],dis[100010],nxt[100010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
struct node{int sum,sufmx;node(int _sum=-1,int _sufmx=-1){sum=_sum,sufmx=_sufmx;}};
il node operator +(const node&a,const node&b){return (node){a.sum+b.sum,std::max(b.sufmx,b.sum+a.sufmx)};}
int siz[100010],son[100010],top[100010],fa[100010],dfn[100010];
il vd dfs(int x){
	siz[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		fa[dis[i]]=x;
		dfs(dis[i]);
		siz[x]+=siz[dis[i]];
		if(siz[son[x]]<siz[dis[i]])son[x]=dis[i];
	}
}
il vd dfs(int x,int tp){
	dfn[x]=++dfn[0];top[x]=tp;
	if(son[x])dfs(son[x],tp);
	for(int i=fir[x];i;i=nxt[i])if(fa[x]!=dis[i]&&son[x]!=dis[i])dfs(dis[i],dis[i]);
}
node S[400010];bool LZ[400010];
#define mid ((l+r)>>1)
il vd updc(int x,int l,int r){LZ[x]=1,S[x]=(node){-(r-l+1),-1};}
il vd down(int x,int l,int r){if(LZ[x])LZ[x]=0,updc(x<<1,l,mid),updc(x<<1|1,mid+1,r);}
il vd build(int x,int l,int r){
	if(l==r)return;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	S[x]=S[x<<1]+S[x<<1|1];
}
il vd update_d(int x,int l,int r,const int&p,const int&d){
	if(l==r){S[x].sum+=d,S[x].sufmx+=d;return;}
	down(x,l,r);
	if(p<=mid)update_d(x<<1,l,mid,p,d);
	else update_d(x<<1|1,mid+1,r,p,d);
	S[x]=S[x<<1]+S[x<<1|1];
}
il vd update_c(int x,int l,int r,const int&L,const int&R){
	if(L<=l&&r<=R)return updc(x,l,r);
	down(x,l,r);
	if(L<=mid)update_c(x<<1,l,mid,L,R);
	if(mid<R)update_c(x<<1|1,mid+1,r,L,R);
	S[x]=S[x<<1]+S[x<<1|1];
}
il node query(int x,int l,int r,const int&L,const int&R){
	if(L<=l&&r<=R)return S[x];
	down(x,l,r);
	if(L<=mid)
		if(mid<R)return query(x<<1,l,mid,L,R)+query(x<<1|1,mid+1,r,L,R);
		else return query(x<<1,l,mid,L,R);
	else return query(x<<1|1,mid+1,r,L,R);
}
il int query(int x){
	node ret(0,-1e9);
	while(x){
		ret=query(1,1,n,dfn[top[x]],dfn[x])+ret;
		x=fa[top[x]];
	}
	return ret.sufmx;
}
#undef mid
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),q=gi();
	for(int i=2;i<=n;++i)link(gi(),i);
	build(1,1,n);
	dfs(1),dfs(1,1);
	int opt,x;
	while(q--){
		opt=gi(),x=gi();
		if(opt==1)update_d(1,1,n,dfn[x],1);
		else if(opt==2)update_c(1,1,n,dfn[x],dfn[x]+siz[x]-1),update_d(1,1,n,dfn[x],-1-query(x));
		else if(query(x)<0)puts("white");
		else puts("black");
	}
	return 0;
}