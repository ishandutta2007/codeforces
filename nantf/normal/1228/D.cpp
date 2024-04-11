#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=600060;
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
int n,m,el,head[maxn],to[maxn],nxt[maxn],u_fa[maxn],dep[maxn],fa[maxn],ans[maxn],q[maxn],h,r,cnt=0;
bool flag,nnn[4],vis[maxn],use[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
int getfa(int x){
	return x==u_fa[x]?x:u_fa[x]=getfa(u_fa[x]);
}
void dfs(int u,int f){
	dep[u]=dep[f]+1;fa[u]=f;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		if(dep[v]){
			if(fa[fa[u]]==v && !flag){
				ans[u]=1;ans[fa[u]]=2;ans[fa[fa[u]]]=3;
				flag=true;
			}
		}
		else dfs(v,u);
	}
}
void dfs2(int u,int f,int x,int y){
	vis[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f || (ans[v]!=x && ans[v]!=y)) continue;
		if(!use[(i+1)/2]) cnt++,use[(i+1)/2]=true;
		if(!vis[v]) dfs2(v,u,x,y);
	}
}
bool check(int x,int y){
	MEM(vis,0);
	int cnt1=0,cnt2=0;
	FOR(i,1,n){
		if(ans[i]==x) cnt1++;
		if(ans[i]==y) cnt2++;
	}
	cnt=0;
	FOR(i,1,n) if(ans[i]==x){dfs2(i,0,x,y);break;}
	return 1ll*cnt1*cnt2==cnt;
}
int main(){
	n=read();m=read();
	FOR(i,1,n) u_fa[i]=i;
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v);add(v,u);
		u=getfa(u);v=getfa(v);
		u_fa[u]=v;
	}
	FOR(i,1,n) if(getfa(i)!=getfa(1)) return puts("-1"),0;
	dfs(1,0);
	if(!flag) return puts("-1"),0;
	FOR(u,1,n){
		if(ans[u]) continue;
		nnn[1]=nnn[2]=nnn[3]=false;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(ans[v]) nnn[ans[v]]=true;
		}
		FOR(i,1,3) if(!nnn[i]){
			if(ans[u]) return puts("-1"),0;
			ans[u]=i;
		}
		if(!ans[u]) return puts("-1"),0;
	}
	if(!check(1,2) || !check(1,3) || !check(2,3)) return puts("-1"),0;
	FOR(i,1,n) printf("%d ",ans[i]);
}