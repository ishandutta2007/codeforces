#include <cstdio>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
typedef long long ll;
const int Mod=1000000007;
const int Maxn=100000;
const int Maxm=60000;
int n;
int m;
int p[Maxm+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int sz[Maxn+5];
ll lis[Maxn+5],len;
void init_dfs(int u,int fa){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
		lis[++len]=1ll*(n-sz[v])*sz[v];
		sz[u]+=sz[v];
	}
}
int main(){
	int T;
	read(T);
	while(T--){
		read(n);
		for(int i=1;i<=n;i++){
			head[i]=0;
		}
		tot=0;
		for(int i=1;i<n;i++){
			int u,v;
			read(u),read(v);
			add_edge(u,v);
			add_edge(v,u);
		}
		read(m);
		for(int i=1;i<=m;i++){
			read(p[i]);
		}
		sort(p+1,p+1+m);
		len=0;
		init_dfs(1,0);
		sort(lis+1,lis+1+len);
		int ans=0;
		if(len<=m){
			for(int i=1;i<len;i++){
				ans=(ans+lis[i]*p[i])%Mod;
			}
			int all=1;
			for(int i=len;i<=m;i++){
				all=1ll*all*p[i]%Mod;
			}
			ans=(ans+lis[len]*all)%Mod;
		}
		else{
			for(int i=1;i<=m;i++){
				ans=(ans+lis[len-(m-i+1)+1]*p[i])%Mod;
			}
			for(int i=1;i<=len-m;i++){
				ans=(ans+lis[i])%Mod;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}