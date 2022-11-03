#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char op[500010];
int n,m,a[500010],b[500010],c[500010];
struct RebuildTree{
	int fa[1000010];
	int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
	int ls[1000010],rs[1000010],cnt,from[1000010];
	void Union(int a,int b){
		a=hd(a),b=hd(b);
		++cnt;ls[cnt]=a,rs[cnt]=b;from[cnt]=from[a];
		fa[a]=fa[b]=cnt;
	}
	void pre(){
		for(int i=1;i<=n<<1;++i)fa[i]=i;
		for(int i=1;i<=n;++i)from[i]=i;
		cnt=n;
	}
	int dfn[1000010],end[1000010];
	void dfs(int x){
		if(!x)return;
		dfn[x]=dfn[0]+1;
		if(x<=n)++dfn[0];
		fa[ls[x]]=fa[rs[x]]=x;
		dfs(ls[x]),dfs(rs[x]);
		end[x]=dfn[0];
	}
	void work(){for(int i=cnt;i;--i)if(!dfn[i])dfs(i);}
}A,B;
#define mid ((l+r)>>1)
ll seg[2000010],tag[2000010];
bool ovw;
void upd(int x,int l,int r,ll d){if(ovw)seg[x]=tag[x]=d;else seg[x]+=d*(r-l+1),tag[x]+=d;}
void down(int x,int l,int r){if(tag[x])upd(x<<1,l,mid,tag[x]),upd(x<<1|1,mid+1,r,tag[x]),tag[x]=0;}
ll calc(ll a,ll b){if(ovw)return std::max(a,b);else return a+b;}
void update(int x,int l,int r,int L,int R,ll d){
	if(L<=l&&r<=R)return upd(x,l,r,d);
	down(x,l,r);
	if(L<=mid)update(x<<1,l,mid,L,R,d);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,d);
	seg[x]=calc(seg[x<<1],seg[x<<1|1]);
}
ll query(int x,int l,int r,int p){
	if(l==r)return seg[x];
	down(x,l,r);
	if(p<=mid)return query(x<<1,l,mid,p);
	else return query(x<<1|1,mid+1,r,p);
}
#undef mid
std::vector<int>fuck[500010];
ll ans[500010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi();
	A.pre(),B.pre();
	for(int i=1;i<=m;++i){
		scanf("%s",op+i);
		a[i]=gi();if(op[i]=='U'||op[i]=='M')b[i]=gi();
		if(op[i]=='U')A.Union(a[i],b[i]);
		else if(op[i]=='M')B.Union(a[i],b[i]);
		else if(op[i]=='Z')c[i]=B.hd(a[i]);
		else c[i]=A.hd(a[i]);
	}
	A.work(),B.work();
	ovw=1;
	for(int i=1;i<=m;++i){
		if(op[i]=='Z')update(1,1,n,B.dfn[c[i]],B.end[c[i]],i);
		else if(op[i]=='Q')fuck[query(1,1,n,B.dfn[a[i]])].push_back(i);
	}
	memset(seg,0,sizeof seg);
	memset(tag,0,sizeof tag);
	ovw=0;
	for(int i=1;i<=m;++i){
		if(op[i]=='A')update(1,1,n,A.dfn[c[i]],A.end[c[i]],A.end[c[i]]-A.dfn[c[i]]+1);
		else if(op[i]=='Q')ans[i]+=query(1,1,n,A.dfn[a[i]]);
		for(int j:fuck[i]) ans[j]-=query(1,1,n,A.dfn[a[j]]);
	}
	for(int i=1;i<=m;++i)if(op[i]=='Q')printf("%lld\n",ans[i]);
	return 0;
}