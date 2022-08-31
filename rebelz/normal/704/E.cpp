// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	ll x,y;
	node(ll x=0,ll y=1):x(x),y(y){}
	bool operator<(const node c)const{return (__int128)x*c.y<(__int128)y*c.x;}
	bool operator<=(const node c)const{return (__int128)x*c.y<=(__int128)y*c.x;}
	bool operator>(const node c)const{return (__int128)x*c.y>(__int128)y*c.x;}
	bool operator>=(const node c)const{return (__int128)x*c.y>=(__int128)y*c.x;}
	bool operator==(const node c)const{return (__int128)x*c.y==(__int128)y*c.x;}
	node operator+(const node c)const{return node(c.y*x+y*c.x,y*c.y);}
	node operator-(const node c)const{return node(c.y*x-y*c.x,y*c.y);}
	node operator*(const node c)const{return node(x*c.x,y*c.y);}
	node operator/(const node c)const{return node(x*c.y,y*c.x);}
	node operator*(const ll c)const{return node(x*c,y);}
}p[200005];

struct line{
	node x1,y1,x2,y2;
	line(node x1=node(0,1),node y1=node(0,1),node x2=node(0,1),node y2=node(0,1)):x1(x1),y1(y1),x2(x2),y2(y2){}
	node getval(node x){
		if(x1==x2) return y1;
		node t=(y2-y1)/(x2-x1);
		return (x-x1)*(t.x/t.y)+y1;
	}
}val[100005];

int n,m,k,rt,tot,ncnt,mcnt; double res,inf=1e9;
int f[100005],dep[100005],v[200005],nxt[200005],h[100005],son[100005],dfn[100005],siz[100005],top[100005],ch[100005][2];
vector<line> vec[100005],add[200005],del[200005];
mt19937 mrand(19260817);

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u]) continue;
		f[v[p]]=u,dep[v[p]]=dep[u]+1;
		dfs1(v[p]);
		siz[u]+=siz[v[p]];
		if(siz[v[p]]>siz[son[u]]) son[u]=v[p];
	}
}

void dfs2(int u){
	dfn[u]=++ncnt;
	if(son[u]) top[son[u]]=top[u],dfs2(son[u]);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u]||v[p]==son[u]) continue;
		top[v[p]]=v[p];
		dfs2(v[p]);
	}
}

int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=f[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

double cross(line a,line b){
	node L=max(a.x1,b.x1);
	node R=min(a.x2,b.x2);
	if(L>R) return inf;
	node aL=a.getval(L);
	node aR=a.getval(R);
	node bL=b.getval(L);
	node bR=b.getval(R);
//	cout<<"??? "<<1.0*L.x/L.y<<' '<<1.0*R.x/R.y<<' '<<1.0*aL.x/aL.y<<' '<<1.0*bL.x/bL.y<<endl;
	if(aL==bL) return 1.0*L.x/L.y;
	if(aR==bR) return 1.0*R.x/R.y;
	if((aL<bL)==(aR<bR)) return inf;
//	cout<<"cross "<<1.0*a.x1.x/a.x1.y<<' '<<1.0*a.y1.x/a.y1.y<<' '<<1.0*b.x1.x/b.x1.y<<' '<<1.0*b.y1.x/b.y1.y<<endl;
	if(aL>bL) swap(aL,bL),swap(aR,bR);
	double l=1.0*L.x/L.y,r=1.0*R.x/R.y;
	double al=1.0*aL.x/aL.y,ar=1.0*aR.x/aR.y;
	double bl=1.0*bL.x/bL.y,br=1.0*bR.x/bR.y;
	return l+(r-l)/(bl-al+ar-br)*(bl-al);
}

void change(int t,int v,int x,int y,int l){
	ll now=1ll*t*v,tmp=1ll*t*v+dep[x]+dep[y]-2*dep[l];
	while(top[x]!=top[l]){
		vec[top[x]].pb(line(node(now,v),node(dep[x],1),node(now+dep[x]-dep[top[x]]+1,v),node(dep[top[x]]-1,1)));
		now+=dep[x]-dep[top[x]]+1;
		x=f[top[x]];
	}
	now=tmp;
	while(top[y]!=top[l]){
		vec[top[y]].pb(line(node(now-dep[y]+dep[top[y]]-1,v),node(dep[top[y]]-1,1),node(now,v),node(dep[y],1)));
		now-=dep[y]-dep[top[y]]+1;
		y=f[top[y]];
	}
	vec[top[l]].pb(line(node(now-abs(dep[x]-dep[y]),v),node(dep[x],1),node(now,v),node(dep[y],1)));
}

void update(int u){siz[u]=1+siz[ch[u][0]]+siz[ch[u][1]];}

void split(int u,node k,node v,int &x,int &y){
	if(!u) return (void)(x=y=0);
	if(val[u].getval(k)<=v) x=u,split(ch[u][1],k,v,ch[x][1],y);
	else y=u,split(ch[u][0],k,v,x,ch[y][0]);
	update(u);
}

void split1(int u,node k,node v,int &x,int &y){
	if(!u) return (void)(x=y=0);
	if(val[u].getval(k)<v) x=u,split1(ch[u][1],k,v,ch[x][1],y);
	else y=u,split1(ch[u][0],k,v,x,ch[y][0]);
	update(u);
}

int merge(int x,int y){
	if(!x||!y) return x+y;
	if(mrand()%(siz[x]+siz[y])<siz[x]){
		ch[x][1]=merge(ch[x][1],y); update(x);
		return x;
	}
	else{
		ch[y][0]=merge(x,ch[y][0]); update(y);
		return y;
	}
}

void adds(line r){
	int a,b;
	split(rt,r.x1,r.y1,a,b);
	int rg=a,lf=b;
	while(ch[rg][1]) rg=ch[rg][1];
	while(ch[lf][0]) lf=ch[lf][0];
	if(rg) chkmin(res,cross(val[rg],r));
	if(lf) chkmin(res,cross(r,val[lf]));
	mcnt++;
	val[mcnt]=r,ch[mcnt][0]=ch[mcnt][1]=0,siz[mcnt]=1;
	rt=merge(merge(a,mcnt),b);
}

void dels(line r){
	int a,b,x;
	split(rt,r.x2,r.y2,a,b);
	split1(a,r.x2,r.y2,a,x);
	int rg=a,lf=b;
	while(ch[rg][1]) rg=ch[rg][1];
	while(ch[lf][0]) lf=ch[lf][0];
	if(lf&&rg) chkmin(res,cross(val[rg],val[lf]));
	rt=merge(a,b);
}

double solve(int u){
//	cout<<"solve "<<u<<endl;
//	for(auto r:vec[u]) cout<<1.0*r.x1.x/r.x1.y<<' '<<1.0*r.y1.x/r.y1.y<<' '<<1.0*r.x2.x/r.x2.y<<' '<<1.0*r.y2.x/r.y2.y<<endl;
	k=0;
	for(auto r:vec[u]) p[++k]=r.x1,p[++k]=r.x2;
	sort(p+1,p+k+1);
	k=unique(p+1,p+k+1)-p-1;
	for(int i=1;i<=k;i++) add[i].clear(),del[i].clear();
	for(auto r:vec[u]){
		add[lower_bound(p+1,p+k+1,r.x1)-p].pb(r);
		del[lower_bound(p+1,p+k+1,r.x2)-p].pb(r);
	}
	rt=mcnt=0;
	res=inf;
	for(int i=1;i<=k;i++){
		if(1.0*p[i].x/p[i].y>=res) break;
		for(auto r:add[i]) adds(r);
		for(auto r:del[i]) dels(r);
	}
	return res;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dep[1]=1; dfs1(1);
	top[1]=1; dfs2(1);
	int x,y,a,b;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); a=readint(); b=readint();
		change(x,y,a,b,lca(a,b));
	}
	double ans=inf;
	for(int i=1;i<=n;i++) if(top[i]==i) chkmin(ans,solve(i));
	if(ans>inf/10) printf("-1\n");
	else printf("%.10lf\n",ans);
	return 0;
}