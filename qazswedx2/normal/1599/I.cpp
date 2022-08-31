#include<bits/stdc++.h>
using namespace std;
#define lc son[x][0]
#define rc son[x][1]

int read(){
	int x=0;char ch=getchar();
	while (ch>'9'||ch<'0') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}

const int N=2e6+10;
int n,m,id,son[N][2],fa[N],cir[N][2],len[N],sum[N];
bool ise[N],square[N],rev[N],iscir[N];

bool isroot(int x){
	return x!=son[fa[x]][0]&&x!=son[fa[x]][1];
}

void update(int x){
	iscir[x]=square[x];
	sum[x]=len[x];
	if (lc) sum[x]+=sum[lc],iscir[x]|=iscir[lc];
	if (rc) sum[x]+=sum[rc],iscir[x]|=iscir[rc];
}

void rot(int x){
	int y=fa[x],z=fa[y];
	bool b=(x==son[y][1]);
	fa[son[y][b]=son[x][!b]]=y;
	fa[son[x][!b]=y]=x;
	fa[x]=z;
	if (y==son[z][0]) son[z][0]=x;
	if (y==son[z][1]) son[z][1]=x;
	if (y==cir[z][0]) cir[z][0]=x;
	if (y==cir[z][1]) cir[z][1]=x;
	update(y);update(x);
}

void flip(int x){
	if (!x) return;
	swap(lc,rc);rev[x]^=1;
}

void pushdown(int x){
	if (!x) return;
	if (rev[x]){
		flip(lc);flip(rc);
		if (square[x]) swap(cir[x][0],cir[x][1]);
		rev[x]=0;
	}
}

void splay(int x){
	pushdown(x);
	for (;!isroot(x);rot(x)){
		int y=fa[x],z=fa[y];
		pushdown(z);pushdown(y);pushdown(x);
		if (!isroot(y)) rot((x==son[y][0])==(y==son[z][0])?y:x);
	}
}

void reset(int z,int x){
	splay(x);
	len[z]=min(sum[lc],sum[rc]);
	fa[cir[z][0]=lc]=z;
	fa[cir[z][1]=rc]=z;
	lc=rc=0;
	update(x);
	fa[son[z][1]=x]=z;
	update(z);
}

void access(int x){
	int p=x;
	for (int y=0;x;y=x,x=fa[x]){
		splay(x);
		int z=fa[x];
		if (square[z]){
			splay(z);
			int cp=son[z][1];
			son[z][1]=0;
			update(z);
			for (pushdown(cp);son[cp][0];pushdown(cp=son[cp][0]));
			splay(cp);
			fa[son[cp][0]=cir[z][0]]=cp;
			fa[son[cp][1]=cir[z][1]]=cp;
			cir[z][0]=cir[z][1]=0;
			update(cp);
			reset(z,x);
		}
		rc=y;
		update(x);
	}
	splay(p);
}

void makeroot(int x){
	access(x);flip(x);
}
int getroot(int x){
	int y=x;
	while (fa[y]) y=fa[y];
	access(x);
	return y;
}

int newnode(int l,bool tp){
	int x=++id;
	ise[x]=1;
	square[x]=tp;
	len[x]=sum[x]=l;
	return x;
}

map<pair<pair<int,int>,int>,int> M;
#define mp make_pair
bool link(int x,int y,int l){
	if (x==y) return 0;
	makeroot(x);
	if (getroot(y)==x){
		if (iscir[y]) return 0;
		fa[son[y][1]=newnode(l,0)]=y;
		update(y);
		splay(x);
		fa[rc]=0;rc=0;
		update(x);
		fa[++id]=x;square[id]=1;
		reset(id,y);
	}
	else fa[fa[x]=newnode(l,0)]=y;
	M[mp(mp(x,y),l)]++;
	return 1;
}

bool cut(int x,int y,int l){
	if (!M[mp(mp(x,y),l)]) return 0;
	M[mp(mp(x,y),l)]--;
	makeroot(y);
	access(x);
	if (iscir[x]){
		pushdown(lc);
		int z;
		if (lc!=y) z=lc;else z=son[y][1];
		splay(z);
		fa[x]=fa[y]=lc=rc=son[y][0]=son[y][1]=0;
		rev[x]=rev[y]=0;
		int lz=cir[z][0],rz=cir[z][1],path;
		if (len[lz]==l&&!son[lz][0]&&!son[lz][1]) path=rz;else flip(path=lz);
		fa[son[y][0]=path]=y;
		update(y);
		fa[son[x][1]=y]=x;
		update(x);
	}
	else fa[lc]=0,lc=0,update(x);
	return 1;
}

int dis(int x,int y){
	makeroot(x);
	return getroot(y)!=x?-1:sum[y];
}

struct Egeg{int x,y;}bn[N];
int main()
{
	scanf("%d%d",&n,&m);id=n;
	for(int i=1;i<=m;i++)
		bn[i].x=read(),bn[i].y=read();
	int l=1; long long ans=0;
	for(int r=1;r<=m;r++){
		while(!link(bn[r].x,bn[r].y,1) && l<r)
			cut(bn[l].x,bn[l].y,1),++l;
//		cerr<<"l="<<l<<" r="<<r<<endl;
		ans+=r-l+1;
	}
	cout<<ans<<endl;
	return 0;
}