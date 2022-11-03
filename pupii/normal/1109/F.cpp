#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m,N;
int get(int i,int j){return m*(i-1)+j;}
int f[1010][1010],px[200010],py[200010],_[5],__[5],o;
int fa[200010],ch[200010][2];
bool rev[200010];
bool isrt(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
void Rev(int x){if(x)rev[x]^=1,std::swap(ch[x][0],ch[x][1]);}
void down(int x){
	if(!isrt(x))down(fa[x]);
	if(rev[x])Rev(ch[x][0]),Rev(ch[x][1]),rev[x]=0;
}
void rotate(int x){
	int y=fa[x],z=fa[y],o=x==ch[y][1];
	if(!isrt(y))ch[z][y==ch[z][1]]=x;fa[x]=z;
	ch[y][o]=ch[x][!o];fa[ch[x][!o]]=y;
	ch[x][!o]=y;fa[y]=x;
}
void splay(int x){
	down(x);
	int y,z;
	while(!isrt(x)){
		y=fa[x],z=fa[y];
		if(!isrt(y))rotate(((x==ch[y][0])^(y==ch[z][0]))?x:y);
		rotate(x);
	}
}
void access(int x){for(int y=0;x;x=fa[y=x])splay(x),ch[x][1]=y;}
void makert(int x){access(x),splay(x),Rev(x);}
void link(int x,int y){makert(x),fa[x]=y;}
void cut(int x,int y){makert(x),access(y),splay(y);fa[x]=ch[y][0]=0;}
int find(int x){access(x),splay(x);while(ch[x][0])x=ch[x][0];splay(x);return x;}
struct data{int mn,cnt;};
data operator+(data a,data b){
	if(a.mn<b.mn)return a;
	else if(a.mn>b.mn)return b;
	else return{a.mn,a.cnt+b.cnt};
}
data operator+(data a,int b){return{a.mn+b,a.cnt};}
data seg[800010];int lz[800010];
void Upd(int x,int d){lz[x]+=d,seg[x]=seg[x]+d;}
void sdown(int x){if(lz[x])Upd(x<<1,lz[x]),Upd(x<<1|1,lz[x]),lz[x]=0;}
#define mid ((l+r)>>1)
void update(int x,int l,int r,const int&L,const int&R,const int&d){
	if(L<=l&&r<=R)return Upd(x,d);
	sdown(x);
	if(L<=mid)update(x<<1,l,mid,L,R,d);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,d);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
void build(int x,int l,int r){
	seg[x].cnt=r-l+1;seg[x].mn=l;if(l==r)return;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
}
int get(int x,int l,int r,int p){
	if(l==r)return seg[x].mn;
	sdown(x);
	if(p<=mid)return get(x<<1,l,mid,p);
	else return get(x<<1|1,mid+1,r,p);
}
#undef mid
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi(),N=n*m;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)f[i][j]=gi(),px[f[i][j]]=i,py[f[i][j]]=j;
	ll ans=0;
	build(1,1,N);
	for(int i=2;i<=N;++i)update(1,1,N,i,i,10000000);
	for(int i=1,j=1;i<=N;++i){
		while(j<N){
			o=0;++j;
			if(px[j]>1)_[++o]=f[px[j]-1][py[j]];
			if(px[j]<n)_[++o]=f[px[j]+1][py[j]];
			if(py[j]>1)_[++o]=f[px[j]][py[j]-1];
			if(py[j]<m)_[++o]=f[px[j]][py[j]+1];
			for(int p=1;p<=o;++p)
				if(i<=_[p]&&_[p]<j)__[p]=find(_[p]);
				else _[p]=_[o],--o,--p;
			std::sort(__+1,__+o+1);
			for(int p=1;p<o;++p)if(__[p]==__[p+1])o=-1;
			if(o==-1){--j;break;}
			for(int p=1;p<=o;++p)link(j,_[p]);
			update(1,1,N,j,N,-o);
			update(1,1,N,j,j,-10000000);
		}
		if(seg[1].mn==1)ans+=seg[1].cnt;
		o=0;
		if(px[i]>1)_[++o]=f[px[i]-1][py[i]];
		if(px[i]<n)_[++o]=f[px[i]+1][py[i]];
		if(py[i]>1)_[++o]=f[px[i]][py[i]-1];
		if(py[i]<m)_[++o]=f[px[i]][py[i]+1];
		for(int p=1;p<=o;++p)if(i<_[p]&&_[p]<=j)cut(i,_[p]),update(1,1,N,_[p],N,1);
		update(1,1,N,i,i,10000000);
		Upd(1,-1);
	}
	printf("%lld\n",ans);
	return 0;
}