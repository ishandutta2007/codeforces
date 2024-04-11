#include<bits/stdc++.h>

using namespace std;

#define N 300000
#define F(x,y) (((x)-1)*m+(y))
#define ls (x<<1)
#define rs (x<<1|1)
#define INF 0x3f3f3f3f

const int D[4][2]={-1,0,0,-1,1,0,0,1};
int n,m,p,fa[N],c[N][2],stk[N],rev[N],T[N<<2],a[1200][1200];
long long ans;
bool b[1200][1200];
struct cdt{
	int x,y;
	cdt(int x=0,int y=0):x(x),y(y){}
}pos[N];
struct seg{
	int x,y;
	seg(int x=0,int y=0):x(x),y(y){}
	seg operator ^ (const seg &p) const{
		return x==p.x?seg(x,y+p.y):x<p.x?(*this):p;
	}
}s[N<<2];

bool isrt(int x){return x!=c[fa[x]][0]&&x!=c[fa[x]][1];}

bool dic(int x){return x==c[fa[x]][1];}

void rtt(int x){
	int y=fa[x],dx=dic(x),dy=dic(y);
	c[y][dx]=c[x][dx^1]; fa[c[x][dx^1]]=y;
	fa[x]=fa[y]; if (!isrt(y)) c[fa[y]][dy]=x;
	c[x][dx^1]=y; fa[y]=x;
}

void psd(int x){
	if (rev[x]){
		rev[c[x][0]]^=1; rev[c[x][1]]^=1;
		swap(c[x][0],c[x][1]);
		rev[x]=0;
	}
}

void splay(int x){
	int tp; stk[tp=1]=x;
	for (int t=x;!isrt(t);t=fa[t]) stk[++tp]=fa[t];
	for (;tp;--tp) psd(stk[tp]);
	for (int y;!isrt(x);rtt(x))
		if (!isrt(y=fa[x])) rtt(dic(x)^dic(y)?x:y);
}

void acs(int x){for (int t=0;x;t=x,x=fa[x]){splay(x); c[x][1]=t;}}

int fdrt(int x){
	acs(x); splay(x);
	for (psd(x);c[x][0];x=c[x][0],psd(x));
	splay(x);
	return x;
}

void mrt(int x){acs(x); splay(x); rev[x]^=1;}

void link(int x,int y){mrt(x); fa[x]=y;}

void cut(int x,int y){mrt(x); acs(y); splay(y); c[y][0]=fa[x]=0;}

void build(int x,int l,int r){
	if (l==r){s[x]=seg(l,1); return;}
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	s[x]=s[ls]^s[rs];
}

void pushdown(int x){
	s[ls].x+=T[x]; s[rs].x+=T[x];
	T[ls]+=T[x]; T[rs]+=T[x];
	T[x]=0;
}

void add(int x,int l,int r,int L,int k){
	if (l>=L){s[x].x+=k; T[x]+=k; return;}
	int mid=(l+r)>>1;
	pushdown(x);
	if (L<=mid) add(ls,l,mid,L,k);
	add(rs,mid+1,r,L,k);
	s[x]=s[ls]^s[rs];
}

seg qry(int x,int l,int r,int L,int R){
	if (l>=L&&r<=R) return s[x];
	int mid=(l+r)>>1; seg ret=seg(INF,0);
	pushdown(x);
	if (L<=mid) ret=ret^qry(ls,l,mid,L,R);
	if (R>mid) ret=ret^qry(rs,mid+1,r,L,R);
	return ret;
}

void LINK(cdt P){
	int x=P.x,y=P.y;
	b[x][y]=1;
	for (int i=0;i<4;++i){
		int nx=x+D[i][0],ny=y+D[i][1];
		if (b[nx][ny]){
			add(1,1,p,a[x][y],-1);
			link(F(x,y),F(nx,ny));
		}
	}
}

void CUT(cdt P){
	int x=P.x,y=P.y;
	b[x][y]=0;
	for (int i=0;i<4;++i){
		int nx=x+D[i][0],ny=y+D[i][1];
		if (b[nx][ny]){
			add(1,1,p,a[nx][ny],1);
			cut(F(x,y),F(nx,ny));
		}
	}
}

bool ok(cdt P){
	int fl[4]={};
	int x=P.x,y=P.y;
	for (int i=0;i<4;++i){
		int nx=x+D[i][0],ny=y+D[i][1];
		if (b[nx][ny]) fl[i]=fdrt(F(nx,ny));
	}
	for (int i=0;i<4;++i) if (fl[i])
		for (int j=0;j<i;++j) if (fl[j])
			if (fl[i]==fl[j]) return 0;
	return 1;
}

int main(){
	scanf("%d%d",&n,&m); p=n*m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			scanf("%d",a[i]+j);
			pos[a[i][j]]=cdt(i,j);
		}
	build(1,1,p);
	for (int l=1,r=1;l<=p;++l){
		for (;r<=p&&ok(pos[r]);++r) LINK(pos[r]);
		seg t=qry(1,1,p,l,r-1);
		if (t.x==l) ans+=t.y;
		CUT(pos[l]);
	}
	printf("%lld\n",ans);
	
	return 0;
}