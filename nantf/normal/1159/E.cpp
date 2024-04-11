#include<bits/stdc++.h>
using namespace std;
const int maxn=500050,mod=998244353;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int t,n,rt,cnt,el,head[maxn*2],to[maxn*30],nxt[maxn*30],ch[maxn*2][2],p[maxn*2],deg[maxn*2],q[maxn*2],h,r;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;deg[v]++;
}
void build(int &x,int l,int r){
	if(l==r) return void(x=l);
	x=++cnt;
	int mid=(l+r)>>1;
	build(ch[x][0],l,mid);
	build(ch[x][1],mid+1,r);
	add(ch[x][0],x);
	add(ch[x][1],x);
}
void link(int x,int l,int r,int ql,int qr,int v){
	if(l>=ql && r<=qr) return add(x,v);
	int mid=(l+r)>>1;
	if(mid>=ql) link(ch[x][0],l,mid,ql,qr,v);
	if(mid<qr) link(ch[x][1],mid+1,r,ql,qr,v);
}
bool topo(){
	h=1;r=0;
	int mx=0;
	FOR(i,1,cnt) if(!deg[i]) p[q[++r]=i]=0;
	while(h<=r){
		int u=q[h++];
		p[u]=max(p[u],mx);
		if(u<=n) p[u]++;
		mx=max(mx,p[u]);
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			deg[v]--;
			if(!deg[v]){
				p[v]=max(p[v],p[u]);
				q[++r]=v;
			}
		}
	}
	FOR(i,1,cnt) if(deg[i]) return false;
	return true;
}
int main(){
	t=read();
	while(t--){
		FOR(i,1,cnt) head[i]=deg[i]=p[i]=0;
		FOR(i,1,el) to[i]=nxt[i]=0;
		el=0;
		cnt=n=read();
		build(rt,1,n);
		FOR(i,1,n){
			int x=read();
			if(x==-1) continue;
			link(rt,1,n,i+1,x-1,i);
			if(x<=n) add(i,x);
		}
		if(topo()) FOR(i,1,n) printf("%d ",p[i]);
		else printf("-1");
		puts("");
	}
}