#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=300030,mod=998244353;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
inline int read(){	// warning: ll
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,ans;
struct graph{
	int el,head[maxn],to[maxn],nxt[maxn],deg[maxn],q[maxn],h,r,id[maxn],at[maxn],cnt,tot1,tot2,pre[maxn];
	bool f1[maxn],f2[maxn];
	inline void add(int u,int v){
		to[++el]=v;nxt[el]=head[u];head[u]=el;
	}
	void topo(){
		FOR(u,1,n) for(int i=head[u];i;i=nxt[i]) deg[to[i]]++;
		h=1;r=0;
		FOR(i,1,n) if(!deg[i]) q[++r]=i;
		while(h<=r){
			int u=q[h++];
			at[id[u]=++cnt]=u;
			for(int i=head[u];i;i=nxt[i]){
				int v=to[i];
				if(!--deg[v]) q[++r]=v;
			}
		}
	}
	void work(graph &G){
		FOR(t,1,n){
			int u=at[t];
			for(int i=G.head[u];i;i=G.nxt[i]){
				int v=G.to[i];
				deg[v]++;
				if(deg[v]==1){
					tot1--;
					if(pre[v]) tot2--;
					for(int j=head[v];j;j=nxt[j]){
						int w=to[j];
						pre[w]++;
						if(pre[w]==1 && !deg[w] && id[w]<id[u]) tot2++;
					}
				}
				if(deg[v]==2){
					for(int j=head[v];j;j=nxt[j]){
						int w=to[j];
						pre[w]--;
						if(!pre[w] && !deg[w] && id[w]<id[u]) tot2--;
					}
				}
			}
			if(!tot1) f1[u]=true;
			if(tot1==1 && !tot2) f2[u]=true;
			tot1++;
			if(pre[u]) tot2++;
		}
	}
}G1,G2;
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		G1.add(u,v);
		G2.add(v,u);
	}
	G1.topo();
	G1.work(G2);
	FOR(i,1,n) G2.at[i]=G1.at[n-i+1];
	FOR(i,1,n) G2.id[G2.at[i]]=i;
	G2.work(G1);
	FOR(i,1,n) if((G1.f1[i] && (G2.f1[i] || G2.f2[i])) || (G1.f2[i] && G2.f1[i])) ans++;
	printf("%d\n",ans);
} // orz djq