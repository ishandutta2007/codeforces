#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=998244353;
#define fi first
#define se second
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
int n,el,head[maxn],to[maxn],nxt[maxn],w1[maxn],w2[maxn],v1[maxn],v2[maxn];
int cnt[maxn],ans[maxn];
int pr[maxn/10],pl,mn[maxn],tp;
PII stk[maxn*20];
bool vis[maxn];
void clear(){
	pl=0;
	FOR(i,1,n) cnt[i]=ans[i]=mn[i]=pr[i]=vis[i]=head[i]=v1[i]=v2[i]=0;
	FOR(i,1,el) to[i]=nxt[i]=w1[i]=w2[i]=0;
	el=0;
}
inline void add(int u,int v,int ww1,int ww2){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w1[el]=ww1;w2[el]=ww2;
}
inline void upd(int x,int y){
	ans[x]=max(ans[x],cnt[x]+=y);
	stk[++tp]=MP(x,y);
}
inline void undo(){
	int x=stk[tp].first,y=stk[tp].second;
	tp--;
	cnt[x]-=y;
}
void dfs(int u,int f){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		v1[v]=1ll*v1[u]*w2[i]%mod;
		v2[v]=1ll*v2[u]*w1[i]%mod;
		int tmp=tp;
		while(w2[i]!=1) upd(mn[w2[i]],-1),w2[i]/=mn[w2[i]];
		while(w1[i]!=1) upd(mn[w1[i]],1),w1[i]/=mn[w1[i]];
		dfs(v,u);
		while(tp>tmp) undo();
	}
}
void init(){
	mn[1]=1;
	FOR(i,2,n){
		if(!vis[i]) pr[++pl]=i,mn[i]=i;
		FOR(j,1,pl){
			int k=i*pr[j];
			if(k>n) break;
			vis[k]=true;
			mn[k]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
}
void solve(){
	n=read();
	init();
	FOR(i,1,n-1){
		int u=read(),v=read(),x=read(),y=read();
		add(u,v,x,y);add(v,u,y,x);
	}
	v1[1]=v2[1]=1;
	dfs(1,0);
	int s=1,sum=0;
	FOR(i,1,n) s=1ll*s*qpow(i,ans[i])%mod;
	FOR(i,1,n) sum=(sum+1ll*v1[i]*qpow(v2[i],mod-2))%mod;
	printf("%lld\n",1ll*s*sum%mod);
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}