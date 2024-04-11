#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define MP make_pair
#define PB push_back
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
namespace MXF{
	int s,t,el=1,head[maxn],to[maxn],nxt[maxn],flw[maxn],cur[maxn],dis[maxn],q[maxn],h,r,mt[maxn];
	void clear(){
		FOR(i,1,t) head[i]=cur[i]=dis[i]=mt[i]=0;
		FOR(i,1,el) to[i]=nxt[i]=flw[i]=0;
		s=t=0;el=1;
	}
	inline void add(int u,int v,int w){
		to[++el]=v;nxt[el]=head[u];head[u]=el;flw[el]=w;
		to[++el]=u;nxt[el]=head[v];head[v]=el;flw[el]=0;
	}
	bool bfs(){
		FOR(i,1,t) dis[i]=-1,cur[i]=head[i];
		dis[q[h=r=1]=s]=0;
		while(h<=r){
			int u=q[h++];
			for(int i=head[u];i;i=nxt[i]){
				int v=to[i];
				if(dis[v]==-1 && flw[i]) dis[q[++r]=v]=dis[u]+1;
			}
		}
		return ~dis[t];
	}
	int dfs(int u,int res){
		if(u==t || !res) return res;
		int f=0,tot=0;
		for(int &i=cur[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]==dis[u]+1 && (f=dfs(v,min(res,flw[i])))){
				tot+=f;res-=f;
				flw[i]-=f;flw[i^1]+=f;
				if(!res) break;
			}
		}
		return tot;
	}
	int dinic(){
		int tot=0;
		while(bfs()) tot+=dfs(s,1e9);
		FOR(u,1,t) for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(flw[i^1] && v!=s && v!=t) mt[u]=v;
		}
//		printf("tot=%d\n",tot);
		return tot;
	}
}
int n,m,B,p[maxn],a[maxn],b[maxn],T,x[maxn],wtf,id[maxn],at[maxn],sum,t[44][22];
bool vis[maxn];
inline bool cmp(const int x,const int y){return b[x]<b[y];}
int main(){
	n=read();m=read();B=read();
	FOR(i,1,m) p[i]=read();
	FOR(i,1,n){
		int k=read();
		while(k--){
			int x=read(),y=read();
			t[i][x]=y;
			a[i]+=y;b[x]+=y;sum+=y;
		}
	}
	FOR(i,1,m) x[i]=i;
	sort(x+1,x+m+1,cmp);
	ROF(ii,m,1){
		int i=x[ii];
		if(B<p[i]) continue;
		B-=p[i];
		id[i]=++wtf;at[wtf]=i;
	}
	FOR(i,1,n) T=max(T,a[i]);
	FOR(i,1,m){
		if(id[i]) b[id[i]+m]=b[i]/2,T=max(T,b[i]=(b[i]+1)/2);
		else T=max(T,b[i]);
	}
	int cnt=0;
	printf("%d\n",T);
	FOR(i,1,m){
		if(id[i]) putchar('1'),cnt++;
		else putchar('0');
	}
	printf("\n%d\n",sum);
	int tot=n+m+cnt;
	FOR(i,1,n){
		FOR(j,1,m) if(id[j]){
			int x=t[i][j];
			t[i][id[j]+m]=(x+vis[j])/2;
			if(x&1) vis[j]^=1;
			t[i][j]=(x+vis[j])/2;
		}
	}
	while(T){
		FOR(i,1,n){
			FOR(j,1,m+cnt){
				int x=t[i][j];
				MXF::add(i,j+tot,x);MXF::add(j+n,i+tot+m+cnt,x);
			}
		}
		FOR(i,1,n) MXF::add(i,i+tot+m+cnt,T-a[i]);
		FOR(i,1,m+cnt) MXF::add(i+n,i+tot,T-b[i]);
		MXF::s=2*tot+1;MXF::t=2*tot+2;
		FOR(i,1,tot) MXF::add(MXF::s,i,1),MXF::add(i+tot,MXF::t,1);
		MXF::dinic();
		FOR(i,1,n){
			int j=MXF::mt[i]-tot;
			if(j<1 || j>m+cnt) continue;
			a[i]--;b[j]--;t[i][j]--;
			printf("%d %d %d %d\n",i,j<=m?j:at[j-m],T-1,1);
		}
		T--;
		MXF::clear();
	}
}