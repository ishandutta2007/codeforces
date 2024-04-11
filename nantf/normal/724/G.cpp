#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=400040,mod=1000000007;
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
int n,m,el,head[maxn],to[maxn],nxt[maxn],ans,rk,fa[maxn],tu[maxn],tv[maxn],tl,cnt[60][2],tot,p[maxn];
ll w[maxn],lb[60],dis[maxn],tw[maxn];
bool vis[maxn],in[60];
inline void add(int u,int v,ll w_){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=w_;
}
void insert(ll x){
	ROF(i,59,0) if((x>>i)&1){
		if(!lb[i]){
			lb[i]=x;
			rk++;
			FOR(j,0,59) if((x>>j)&1) in[j]=true;
			break;
		}
		x^=lb[i];
	}
}
void dfs(int u){
	vis[u]=true;
	p[++tot]=u;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		if(vis[v]){
			tu[++tl]=u;
			tv[tl]=v;
			tw[tl]=w[i];
			continue;
		}
		dis[v]=dis[u]^w[i];
		fa[v]=u;
		dfs(v);
	}
}
void solve(int u){
	dfs(u);
	FOR(i,1,tl) insert(dis[tu[i]]^dis[tv[i]]^tw[i]);
	FOR(i,0,59){
		int sum=0;
		FOR(j,1,tot) if((dis[p[j]]>>i)&1) sum++;
		cnt[i][1]=(1ll*sum*(tot-sum))%mod;
		cnt[i][0]=(1ll*tot*(tot-1)/2-cnt[i][1])%mod;
	}
	int x=(1ll<<rk)%mod;
	FOR(i,0,59) if(in[i]){
		int y=(1ll<<(rk-1))%mod;
		ans=(ans+(1ll<<i)%mod*y%mod*(cnt[i][0]+cnt[i][1]))%mod;
	}
	else ans=(ans+(1ll<<i)%mod*x%mod*cnt[i][1])%mod;
	FOR(i,0,59) cnt[i][0]=cnt[i][1]=lb[i]=in[i]=0;
	tl=tot=rk=0;
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		ll w=read();
		add(u,v,w);add(v,u,w);
	}
	FOR(i,1,n) if(!vis[i]) solve(i);
	printf("%d\n",ans);
}