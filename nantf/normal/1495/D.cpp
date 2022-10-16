#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444,mod=998244353;
#define MP make_pair
#define PB push_back
#define ls o<<1
#define rs o<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
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
inline int qmo(int x){return x+((x>>31)&mod);}
int n,m,w[maxn][maxn],el,head[maxn],to[maxn*3],nxt[maxn*3];
bool vis[maxn],in[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
int calc(int a,int b){
	FOR(i,0,n) in[i]=0;
	FOR(i,0,n) vis[i]=0;
	if(a==b){
		int ans=1;
		FOR(u,1,n) if(u!=a){
			int cnt=0;
			for(int k=head[u];k;k=nxt[k]){
				int v=to[k];
				if(w[a][v]==w[a][u]-1) cnt++;
			}
			ans=1ll*ans*cnt%mod;
		}
		return ans;
	}
	else{
		int d=w[a][b];
		FOR(i,1,n){
			int x=w[a][i],y=w[b][i];
			if(x+y==d){
				if(vis[x]) return 0;
				vis[x]=true;
			}
			else{
				if(x-y==d) in[i]=true;
			}
		}
		int ans=1;
		FOR(u,1,n) if(u!=a && u!=b && in[u]){
			int cnt=0;
			for(int k=head[u];k;k=nxt[k]){
				int v=to[k];
				if(w[a][v]==w[a][u]-1 && w[b][v]==w[b][u]-1) cnt++;
			}
			ans=1ll*ans*cnt%mod;
		}
		FOR(i,0,n) in[i]=0;
		FOR(i,1,n){
			int x=w[a][i],y=w[b][i];
			if(y-x==d) in[i]=true;
		}
		FOR(u,1,n) if(u!=a && u!=b && in[u]){
			int cnt=0;
			for(int k=head[u];k;k=nxt[k]){
				int v=to[k];
				if(w[a][v]==w[a][u]-1 && w[b][v]==w[b][u]-1) cnt++;
			}
			ans=1ll*ans*cnt%mod;
		}
		FOR(i,0,n) in[i]=0;
		FOR(i,1,n){
			int x=w[a][i],y=w[b][i];
			if(x+y!=d && x-y!=d && y-x!=d) in[i]=true;
		}
		FOR(u,1,n) if(u!=a && u!=b && in[u]){
			int cnt=0;
			for(int k=head[u];k;k=nxt[k]){
				int v=to[k];
				if(w[a][v]==w[a][u]-1 && w[b][v]==w[b][u]-1) cnt++;
			}
			ans=1ll*ans*cnt%mod;
		}
		return ans;
	}
}
int main(){
	n=read();m=read();
	MEM(w,0x3f);
	FOR(i,1,n) w[i][i]=0;
	FOR(i,1,m){
		int u=read(),v=read();
		w[u][v]=w[v][u]=1;
		add(u,v);add(v,u);
	}
	FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
	FOR(i,1,n){
		FOR(j,1,n) printf("%d ",calc(i,j));
		puts("");
	}
}