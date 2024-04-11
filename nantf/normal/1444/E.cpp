#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<int,int> PII;
typedef pair<lll,int> PIL;
const int maxn=222,mod=998244353;
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
int n,el=1,head[maxn],to[maxn],nxt[maxn],w[maxn],ww[maxn];
lll f[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
int h[66666];
void init(){
	FOR(i,0,65535) ROF(j,15,0) if((i>>j)&1){h[i]=j;break;}
	h[0]=-1;
}
inline int hb(lll x){
	ROF(i,7,0) if((x>>(i*16))&65535) return i*16+h[(x>>(i*16))&65535];
	return -1;
}
void output(lll x){
	FOR(i,1,n-1) printf("%d",int((x>>i)&1));
}
void dfs(int u,int F){
	vector<lll> vec;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==F) continue;
		dfs(v,u);
		vec.PB(v);
	}
	FOR(i,1,n-1) f[u]|=(__int128)1<<i;
	ROF(i,n-1,1){
		f[u]^=(__int128)1<<i;
		bool flag=true;
		priority_queue<PIL> pq;
		FOR(j,0,(int)vec.size()-1) pq.push(MP(f[vec[j]]+2,vec[j]));
		ROF(j,n-1,1) if((f[u]>>j)&1){
			if(pq.empty()) break;
			PIL p=pq.top();pq.pop();
			int x=hb(p.first);
			if(x>j){flag=false;break;}
			if(x==j) p.first^=(__int128)1<<j,pq.push(p);
		}
		if(!pq.empty() && hb(pq.top().first)!=-1) flag=false;
		if(!flag) f[u]^=(__int128)1<<i;
	}
//	printf("f[%d]=",u);
//	output(f[u]);
//	puts("");
	priority_queue<PIL> pq;
	FOR(j,0,(int)vec.size()-1) pq.push(MP(f[vec[j]]+2,vec[j]));
	ROF(j,n-1,1) if((f[u]>>j)&1){
		if(pq.empty()) break;
		PIL p=pq.top();pq.pop();
		int x=hb(p.first);
//		printf("x=%d,j=%d\n",x,j);
		if(x==j){
			p.first^=(__int128)1<<j,pq.push(p);
			if(!p.first) ww[p.second]=j;
		}
		else ww[p.second]=j;
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==F) continue;
		w[i]=w[i^1]=ww[v];
//		printf("w(%d,%d)=%d\n",u,v,w[i]);
	}
}
int ans,rt,upr;
void dfs1(int u,int f,int upr){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f || w[i]>=upr) continue;
		if(w[i]>w[ans]) ans=i;
		dfs1(v,u,upr);
	}
}
int main(){
	init();
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	rt=1,upr=1e9;
	while(true){
		ans=0;
		dfs1(rt,0,upr);
		if(!ans) return printf("! %d\n",rt),fflush(stdout),0;
		int u=to[ans],v=to[ans^1];
		upr=w[ans];
		printf("? %d %d\n",u,v);
		fflush(stdout);
		rt=read();
	}
}