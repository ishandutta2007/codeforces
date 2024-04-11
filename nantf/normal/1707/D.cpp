#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2222;
#define sz(v) int(v.size())
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0;
	bool f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,mod,el,head[maxn],to[maxn*2],nxt[maxn*2],f[maxn][maxn],C[maxn][maxn],ans[maxn];
int pre[maxn][maxn],suf[maxn][maxn],tmp[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int fa){
	vector<int> vec;
	vec.PB(0);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue;
		dfs(v,u);
		vec.PB(v);
	}
	FOR(i,0,n) pre[0][i]=suf[sz(vec)][i]=1;
	FOR(i,1,sz(vec)-1){
		int s=0;
		FOR(j,0,n){
			s=(s+f[vec[i]][j])%mod;
			pre[i][j]=1ll*pre[i-1][j]*s%mod;
		}
	}
	ROF(i,sz(vec)-1,1){
		int s=0;
		FOR(j,0,n){
			s=(s+f[vec[i]][j])%mod;
			suf[i][j]=1ll*suf[i+1][j]*s%mod;
		}
	}
	if(!fa){
		FOR(i,1,n) f[u][i]=suf[1][i-1];
		return;
	}
	FOR(i,0,n) f[u][i]=(f[u][i]+suf[1][i])%mod;
	FOR(i,1,sz(vec)-1){
		FOR(j,0,n) tmp[j]=1ll*pre[i-1][j]*suf[i+1][j]%mod;
		FOR(j,1,n) tmp[j]=(tmp[j]+tmp[j-1])%mod;
		FOR(j,1,n) f[u][j]=(f[u][j]+1ll*tmp[j-1]*f[vec[i]][j])%mod;
	}
}
int main(){
	n=read();mod=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	FOR(i,0,n) ans[i]=f[1][i];
	FOR(i,0,n) C[i][0]=C[i][i]=1;
	FOR(i,1,n) FOR(j,1,i-1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	ROF(i,n,1) FOR(j,0,i-1){
		int p=1ll*ans[j]*C[i][j]%mod;
		if((i-j)&1) ans[i]=(ans[i]-p+mod)%mod;
		else ans[i]=(ans[i]+p)%mod;
	}
	FOR(i,1,n-1) printf("%d ",ans[i]);
}