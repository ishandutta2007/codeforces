#include <cstdio>
#include <iostream>
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
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=200000;
typedef long long ll;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int n;
int a[Maxn+5],b[Maxn+5],c[Maxn+5],d[Maxn+5];
int sz[2][Maxn+5];
ll ans;
void work_dfs(int u,int fa){
	d[u]=min(a[u],d[fa]);
	if(b[u]!=c[u]){
		sz[c[u]][u]++;
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		work_dfs(v,u);
		sz[0][u]+=sz[0][v];
		sz[1][u]+=sz[1][v];
	}
	int tmp=min(sz[0][u],sz[1][u]);
	ans+=2ll*tmp*d[u];
	sz[0][u]-=tmp;
	sz[1][u]-=tmp;
}
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]),read(b[i]),read(c[i]);
	}
	for(int i=1;i<n;i++){
		int u,v;
		read(u),read(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	d[0]=(1<<30);
	work_dfs(1,0);
	if(sz[0][1]!=0||sz[1][1]!=0){
		puts("-1");
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}