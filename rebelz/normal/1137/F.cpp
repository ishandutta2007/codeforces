#include<bits/stdc++.h>

using namespace std;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q,m,tot=0;
int ch[200005][2],fa[200005],siz[200005],rev[200005],col[200005],cc[400005],v[400005],nxt[400005],h[200005],maxd[200005];

int lowbit(int x){return x&(-x);}
void add(int x,int g){for(;x<=n+q;x+=lowbit(x))cc[x]+=g;}
int ask(int x){int ret=0;for(;x;x-=lowbit(x))ret+=cc[x];return ret;}
bool nroot(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
bool son(int x){return ch[fa[x]][1]==x;}
void reverse(int x){rev[x]^=1,swap(ch[x][0],ch[x][1]);}
void pushdown(int x){if(rev[x])reverse(ch[x][0]),reverse(ch[x][1]),rev[x]=0;}
void update(int x){siz[x]=1+siz[ch[x][0]]+siz[ch[x][1]];}

void rotate(int x){
	int y=fa[x],z=fa[y],k=son(x),w=ch[x][!k];
	if(nroot(y)) ch[z][son(y)]=x;
	ch[x][!k]=y,ch[y][k]=w;
	if(w) fa[w]=y;
	fa[y]=x,fa[x]=z;
	update(y),update(x);
}

void pushall(int x){
	if(nroot(x)) pushall(fa[x]);
	pushdown(x);
}

void splay(int x){
	pushall(x);
	while(nroot(x)){
		int y=fa[x];
		if(nroot(y)) rotate(son(x)==son(y)?y:x);
		rotate(x);
	}
}

int find(int x){
	if(ch[x][0]||ch[x][1]) pushdown(x);
	return ch[x][1]?find(ch[x][1]):x;
}

void access(int x){
	int tmp,z=x;
	m++;
	for(int y=0;x;x=fa[y=x]){
		splay(x);
		tmp=col[find(x)];
//		cout<<"TEST "<<x<<' '<<y<<' '<<tmp<<' '<<m<<' '<<siz[ch[x][0]]<<' '<<siz[ch[x][1]]<<' '<<siz[x]<<endl;
		if(tmp) add(tmp,-siz[ch[x][0]]-1),add(m-1,siz[ch[x][0]]+1);
		ch[x][1]=y,update(x);
	}
	col[z]=m;
}

void getf(int x){for(int y=0;x;x=fa[y=x]) splay(x),ch[x][1]=y,update(x);}

void makeroot(int x){
	access(x); splay(x); reverse(x);
	col[find(x)]=m-1,ch[x][1]=0; update(x);
	add(m-1,-1),add(m,1);
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int ff){
	maxd[u]=u;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==ff) continue;
		fa[v[p]]=u;
		dfs(v[p],u);
		maxd[u]=max(maxd[u],maxd[v[p]]);
	}
	add(maxd[u],1);
	if(maxd[u]==u) col[u]=u;
}

int when(int x){
	splay(x);
	return ask(col[find(x)]-1)+siz[ch[x][1]]+1;
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	m=n;
	dfs(n,-1);
	for(int i=1;i<=n;i++) siz[i]=1;
	for(int i=1;i<=n;i++) getf(i);
	char opt[10]; int x,y;
	for(int ts=1;ts<=q;ts++){
//		for(int i=1;i<=n+q;i++) cout<<ask(i)-ask(i-1)<<' ';
//		cout<<endl;
		scanf("%s",opt); x=readint();
		if(opt[0]=='u'){
			if(!fa[x]) continue;
			makeroot(x);
		}
		else if(opt[0]=='w') printf("%d\n",when(x));
		else{
			y=readint();
			printf("%d\n",when(x)>when(y)?y:x);
		}
	}
	return 0;
}