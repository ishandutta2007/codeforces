#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m,u[maxn],v[maxn],fa[maxn],ch[maxn][2],tag[maxn],cnd[maxn],sz[maxn],siz[maxn];
bool rev[maxn];
ll ans;
inline void pushup(int x){
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+(cnd[x] && x>n);
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+(x>n);
}
inline void setrev(int x){
	rev[x]^=1;
	swap(ch[x][0],ch[x][1]);
}
inline void settag(int x,int y){
	cnd[x]=tag[x]=y;
	sz[x]=y?siz[x]:0;
}
inline void pushdown(int x){
	if(rev[x]){
		if(ch[x][0]) setrev(ch[x][0]);
		if(ch[x][1]) setrev(ch[x][1]);
		rev[x]=0;
	}
	if(~tag[x]){
//		printf("pushdown(%d)\n",x);
		if(ch[x][0]) settag(ch[x][0],tag[x]);
		if(ch[x][1]) settag(ch[x][1],tag[x]);
		tag[x]=-1;
	}
}
inline bool nroot(int x){
	return ch[fa[x]][0]==x || ch[fa[x]][1]==x;
}
inline void pushall(int x){
//	printf("pushall(%d)\n",x);
	if(nroot(x)) pushall(fa[x]);
	pushdown(x);
}
inline void rotate(int x){
	int y=fa[x],z=fa[y],t=ch[y][1]==x,tt=ch[z][1]==y,w=ch[x][t^1];
	fa[x]=z;if(nroot(y)) ch[z][tt]=x;
	if(w) fa[w]=y;ch[y][t]=w;
	fa[y]=x;ch[x][t^1]=y;
	pushup(y);pushup(x);
}
inline void splay(int x){
	pushall(x);
	while(nroot(x)){
		int y=fa[x],z=fa[y],t=ch[y][1]==x,tt=ch[z][1]==y;
		if(nroot(y)) rotate(t^tt?x:y);
		rotate(x);
	}
}
void access(int x){
	for(int y=0;x;x=fa[y=x]) splay(x),ch[x][1]=y,pushup(x);
}
void makert(int x){
	access(x);splay(x);setrev(x);
}
int findrt(int x){
	access(x);splay(x);
	while(ch[x][0]) x=ch[x][0];
	splay(x);
	return x;
}
void split(int x,int y){
	makert(x);access(y);splay(y);
}
void link(int x,int y){
	makert(x);fa[x]=y;
}
void cut(int x,int y){
	split(x,y);fa[x]=ch[y][0]=0;pushup(y);
}
int main(){
	n=read();m=read();
	FOR(i,1,m) u[i]=read(),v[i]=read();
	FOR(i,1,n+m) tag[i]=-1,siz[i]=i>n;
	int j=1;
	FOR(i,1,m){
		while(j<=m){
			int x=u[j],y=v[j];
			makert(x);
			if(findrt(y)==x){
				if(sz[x]) break;
				splay(x);settag(x,j);
			}
			else link(x,j+n),link(y,j+n);
			j++;
		}
		ans+=j-i;
		int x=u[i],y=v[i];
		split(x,y);
		if(fa[i+n]){
			splay(i+n);int c=cnd[i+n];
			if(c){
				int xx=u[c],yy=v[c];
				split(xx,yy);settag(yy,0);
			}
			cut(x,i+n);cut(y,i+n);
			if(c) link(u[c],c+n),link(v[c],c+n);
		}
		else splay(y),settag(y,0);
	}
	printf("%lld\n",ans);
}