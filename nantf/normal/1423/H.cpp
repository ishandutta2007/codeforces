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
int n,k,q,tot,curt=1,at;
int stk[maxn],tp;
int fa[maxn],ch[maxn][2],w[maxn],u[maxn],v[maxn],sz[maxn],siz[maxn],mnid[maxn];
bool rev[maxn],vis[maxn];
inline void pushup(int x){
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+siz[x]+1;
	mnid[x]=x<=n?0:x;
	if(w[mnid[x]]>w[mnid[ch[x][0]]]) mnid[x]=mnid[ch[x][0]];
	if(w[mnid[x]]>w[mnid[ch[x][1]]]) mnid[x]=mnid[ch[x][1]];
}
inline void reverse(int x){
	rev[x]^=1;swap(ch[x][0],ch[x][1]);
}
inline void pushdown(int x){
	if(rev[x]){
		if(ch[x][0]) reverse(ch[x][0]);
		if(ch[x][1]) reverse(ch[x][1]);
		rev[x]=0;
	}
}
inline bool nroot(int x){
	return ch[fa[x]][0]==x || ch[fa[x]][1]==x;
}
void rotate(int x){
	int y=fa[x],z=fa[y],t=ch[y][1]==x,tt=ch[z][1]==y,b=ch[x][t^1];
	fa[x]=z;if(nroot(y)) ch[z][tt]=x;
	fa[y]=x;ch[x][t^1]=y;
	ch[y][t]=b;if(b) fa[b]=y;
	pushup(y);pushup(x);
}
void splay(int x){
	stk[tp=1]=x;
	for(int y=x;nroot(y);y=fa[y]) stk[++tp]=fa[y];
	for(;tp;tp--) pushdown(stk[tp]);
	while(nroot(x)){
		int y=fa[x],z=fa[y],t=ch[y][1]==x,tt=ch[z][1]==y;
		if(nroot(y)) rotate(t^tt?x:y);
		rotate(x);
	}
	pushup(x);
}
void access(int x){
	for(int y=0;x;x=fa[y=x]){
		splay(x);
		if(ch[x][1]!=y){
			siz[x]+=sz[ch[x][1]]; 
			ch[x][1]=y;
			siz[x]-=sz[y];
			pushup(x);
		}
	}
}
void makeroot(int x){
	access(x);splay(x);reverse(x);
}
int findroot(int x){
	access(x);splay(x);pushdown(x);
	for(;ch[x][0];x=ch[x][0]) pushdown(x);
	splay(x);
	return x;
}
void split(int x,int y){
	makeroot(x);access(y);splay(y);
}
void link(int x,int y){
	makeroot(x);
	fa[x]=y;
	siz[y]+=sz[x];
	pushup(y); 
}
void cut(int x,int y){
	split(x,y);
	fa[x]=ch[y][0]=0;
	pushup(y);
}
int main(){
	tot=n=read();q=read();k=read();
	w[0]=1e9;
	FOR(i,1,n) pushup(i);
	at=n+1;
	while(q--){
		int op=read();
		if(op==1){
			int x=read(),y=read();
			makeroot(x);
			if(findroot(y)==x){
				int id=mnid[findroot(y)];
				cut(u[id],id);cut(v[id],id);
				vis[id]=true;
			}
			++tot;
			u[tot]=x;v[tot]=y;w[tot]=curt;
			pushup(tot); 
			link(x,tot);link(y,tot);
		}
		else if(op==2){
			int x=read(),tmp=findroot(x);
			printf("%d\n",(sz[tmp]+1)/2);
		}
		else{
			curt++;
			while(at<=tot && w[at]<=curt-k){
				if(!vis[at]) cut(at,u[at]),cut(at,v[at]);
				at++;
			}
		}
	}
}