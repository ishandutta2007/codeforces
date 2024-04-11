#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct intv{int l,r;bool contain(int x){return l<=x&&x<r;}}tc[100010],A[100010][2],last[100010];
intv operator&(const intv&a,const intv&b){return{std::max(a.l,b.l),std::min(a.r,b.r)};}
int u[200010],U,N;
intv F(intv x){return{u[x.l],u[x.r]};}
int fir[100010],dis[200010],nxt[200010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int bel[100010],col[100010],swp[100010];
void dfs(int x){
	for(int i=fir[x];i;i=nxt[i])
		if(!bel[dis[i]])bel[dis[i]]=bel[x],col[dis[i]]=!col[x],dfs(dis[i]);
		else if(col[x]==col[dis[i]])puts("IMPOSSIBLE"),exit(0);
}
std::vector<int>vec[200010];
#define mid ((l+r)>>1)
struct data{int x,l,r;}seg[800010];
data operator+(const data&a,const data&b){
	if(a.x>b.x)return a;
	else if(a.x<b.x)return b;
	return{a.x,a.l,b.r};
}
int tag[800010];
void build(int x,int l,int r){
	seg[x]={0,l,r};if(l==r)return;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
}
void update(int x,int d){tag[x]+=d,seg[x].x+=d;}
void down(int x){if(tag[x])update(x<<1,tag[x]),update(x<<1|1,tag[x]),tag[x]=0;}
void update(int x,int l,int r,int L,int R,int d){
	if(L<=l&&r<=R)return update(x,d);
	down(x);
	if(L<=mid)update(x<<1,l,mid,L,R,d);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,d);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
#undef mid
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int TL=gi(),TR=gi(),n=gi(),m=gi();
	for(int i=1;i<=n;++i)u[++U]=tc[i].l=gi(),u[++U]=tc[i].r=gi()+1;
	while(m--){
		int a=gi(),b=gi();
		link(a,b),link(b,a);
	}
	u[++U]=-1,u[++U]=0,u[++U]=1e9+10;
	std::sort(u+1,u+U+1);U=std::unique(u+1,u+U+1)-u-1;
	for(int i=1;i<=n;++i)tc[i].l=std::lower_bound(u+1,u+U+1,tc[i].l)-u;
	for(int i=1;i<=n;++i)tc[i].r=std::lower_bound(u+1,u+U+1,tc[i].r)-u;
	for(int i=1;i<=n;++i)if(!bel[i])bel[i]=++N,dfs(i);
	for(int i=1;i<=N;++i)A[i][0]=A[i][1]={1,U};
	for(int i=1;i<=n;++i)A[bel[i]][col[i]]=A[bel[i]][col[i]]&tc[i];
	for(int i=1;i<=N;++i)if(A[i][0].l>=A[i][0].r||A[i][1].l>=A[i][1].r)puts("IMPOSSIBLE"),exit(0);
	for(int i=1;i<=N;++i){
		if(A[i][0].l>A[i][1].l)std::swap(A[i][0],A[i][1]),swp[i]=1;
		vec[A[i][0].l].push_back(i);
		vec[A[i][0].r].push_back(i);
		vec[A[i][1].l].push_back(i);
		vec[A[i][1].r].push_back(i);
	}
	build(1,1,U);
	for(int i=U;i>1;--i){
		if(i<U&&seg[1].x==N){
			do{
				int l1=u[i],r1=u[i+1]-1,l2=std::max(l1,u[seg[1].l]),r2=u[seg[1].r+1]-1;
				if(l2>r2)break;
				int a=l1,b=l2;
				if(a+b<TL)b+=std::min(r2-l2,TL-a-b);
				if(a+b<TL)a+=std::min(r1-l1,TL-a-b);
				if(TL<=a+b&&a+b<=TR){
					puts("POSSIBLE");
					printf("%d %d\n",a,b);
					for(int i=1;i<=n;++i)putchar('1'+(swp[bel[i]]^col[i]^(!F(A[bel[i]][0]).contain(a)||!F(A[bel[i]][1]).contain(b))));
					return 0;
				}
			}while(0);
		}
		int ni=i-1;
		for(int x:vec[i]){
			if(last[x].l<last[x].r)update(1,1,U,last[x].l,last[x].r-1,-1);
			if(A[x][0].contain(ni))
				if(A[x][1].contain(ni))last[x]={1,std::max(A[x][0].r,A[x][1].r)};
				else last[x]=A[x][1];
			else last[x]={0,0};
			if(last[x].l<last[x].r)update(1,1,U,last[x].l,last[x].r-1,1);
		}
	}
	puts("IMPOSSIBLE");return 0;
}