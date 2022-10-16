#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100;
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
int t,n,m,a,b,el,u[maxn],v[maxn],head[maxn],to[maxn],nxt[maxn],cnt,q[maxn],h,r;
bool vis[maxn],on[maxn];
ll ans,sum1,sum2;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u){
	vis[u]=true;
	cnt++;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]) continue;
		dfs(v);
	}
}
bool dfs2(int u){
	if(vis[u]) return on[u];
	vis[u]=true;
	if(u==b) return on[u]=true; 
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==a) continue;
		if(dfs2(v)) on[u]=true;
	}
	return on[u];
}
int main(){
	t=read();
	while(t--){
		n=read();m=read();a=read();b=read();
		FOR(i,1,m) u[i]=read(),v[i]=read();
		FOR(i,1,m) add(u[i],v[i]),add(v[i],u[i]);
		dfs2(a);
		h=1;r=0;
		FOR(i,1,n) vis[i]=0;
		FOR(i,1,n) if(on[i] && i!=a && i!=b) q[++r]=i,vis[i]=1;
		while(h<=r){
			int u=q[h++];
			for(int i=head[u];i;i=nxt[i]){
				int v=to[i];
				if(vis[v] || v==a || v==b) continue;
				vis[v]=1;
				q[++r]=v;
				on[v]=true;
			}
		}
		FOR(i,1,n) head[i]=vis[i]=0;
		FOR(i,1,el) to[i]=nxt[i]=0;
		el=sum1=sum2=0;
		on[a]=on[b]=false;
		FOR(i,1,m) if(!on[u[i]] && !on[v[i]] && !(u[i]==a && v[i]==b || u[i]==b && v[i]==a)) add(u[i],v[i]),add(v[i],u[i]);
		FOR(i,1,n) vis[i]=0;
		FOR(i,1,n) if(!vis[i] && !on[i]){
			cnt=0;
			dfs(i);
			cnt--;
			sum1+=cnt;sum2+=1ll*cnt*cnt;
		}
		ans=sum1*sum1-sum2;
		printf("%lld\n",ans/2);
		FOR(i,1,n) head[i]=vis[i]=on[i]=0;
		FOR(i,1,el) to[i]=nxt[i]=0;
		el=ans=sum1=sum2=0;
	}
}