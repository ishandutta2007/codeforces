#include<bits/stdc++.h>
#define il inline
#define vd void
#define inf 100000000000000000ll
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,k;
ll w[100010],g[100010];
int nxt[100010],stk[100010],tp,ANS=1;
std::vector<int>G[100010];
ll pres[100010],sufs[100010];
ll maxp[400010],maxsuf[400010],tag[400010],ans[400010];
#define mid ((l+r)>>1)
il vd upd(int x,ll d){tag[x]+=d,maxsuf[x]+=d,ans[x]+=d;}
il vd down(int x){if(tag[x])upd(x<<1,tag[x]),upd(x<<1|1,tag[x]),tag[x]=0;}
il ll solveans(int x,int l,int r,ll mxl){
	if(l==r)return mxl+maxp[x];
	down(x);
	if(maxsuf[x<<1]>=mxl)return std::min(solveans(x<<1,l,mid,mxl),ans[x]);
	else return std::min(mxl+maxp[x<<1],solveans(x<<1|1,mid+1,r,mxl));
}
il vd pushup(int x,int l,int r){
	maxsuf[x]=std::max(maxsuf[x<<1],maxsuf[x<<1|1]);
	ans[x]=solveans(x<<1|1,mid+1,r,maxsuf[x<<1]);
}
il vd build(int x,int l,int r){
	if(l==r){maxsuf[x]=sufs[l];maxp[x]=-sufs[l];return;}
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	maxsuf[x]=std::max(maxsuf[x<<1],maxsuf[x<<1|1]);
	maxp[x]=-maxsuf[x];
	ans[x]=solveans(x<<1|1,mid+1,r,maxsuf[x<<1]);
}
il vd update(int x,int l,int r,const int&L,const int&R,const ll&d){
	if(L<=l&&r<=R)return upd(x,d);
	down(x);
	if(L<=mid)update(x<<1,l,mid,L,R,d);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,d);
	pushup(x,l,r);
}
il int _query(int x,int l,int r,ll mxl){
	if(l==r)return mxl+maxp[x]<=k?l:0;
	down(x);
	if(mxl+maxp[x<<1|1]<=k)return _query(x<<1|1,mid+1,r,mxl);
	else return _query(x<<1,l,mid,mxl);
}
il int query(int x,int l,int r,ll mxl){
	if(l==r)return mxl+maxp[x]<=k?l:0;
	down(x);
	if(maxsuf[x<<1]>=mxl){
		if(ans[x]<=k)return query(x<<1|1,mid+1,r,maxsuf[x<<1]);
		else return query(x<<1,l,mid,mxl);
	}else return std::max(_query(x<<1,l,mid,mxl),query(x<<1|1,mid+1,r,mxl));
}
#undef mid
il vd dfs(int x){
	stk[++tp]=x;
	if(x!=n+1){
		update(1,1,n,nxt[x]-1,n,pres[x-1]-pres[nxt[x]-1]);
		int l=1,r=tp,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(pres[x-1]-pres[stk[mid]-1]<=k)r=mid;
			else l=mid+1;
		}
		if(1<=x-1)update(1,1,n,1,x-1,-inf);
		if(stk[l-1]<=n)update(1,1,n,stk[l-1],n,inf);
		ANS=std::max(ANS,query(1,1,n,-inf)-x+1);
		if(1<=x-1)update(1,1,n,1,x-1,inf);
		if(stk[l-1]<=n)update(1,1,n,stk[l-1],n,-inf);
	}
	for(int i:G[x])dfs(i);
	if(x!=n+1)update(1,1,n,nxt[x]-1,n,-(pres[x-1]-pres[nxt[x]-1]));
	--tp;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();k=gi();
	for(int i=1;i<n;++i)w[i]=gi();w[n]=inf;
	for(int i=1;i<=n;++i)g[i]=gi();
	for(int i=1;i<=n;++i)pres[i]=pres[i-1]-w[i]+g[i];
	for(int i=1;i<=n;++i)sufs[i]=sufs[i-1]-w[i-1]+g[i];
	build(1,1,n);
	stk[0]=n;
	for(int i=n-1;~i;--i){
		while(tp&&pres[stk[tp]]>=pres[i])--tp;
		nxt[i+1]=stk[tp]+1;stk[++tp]=i;
	}
	for(int i=1;i<=n;++i)G[nxt[i]].push_back(i);
	tp=0;dfs(n+1);
	printf("%d\n",ANS);
	return 0;
}