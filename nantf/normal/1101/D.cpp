#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200020;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn],el,head[maxn],to[maxn*2],nxt[maxn*2],ans;
vector<int> pr[maxn],len[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int f){
	for(int i=2;i*i<=a[u];i++)
		if(a[u]%i==0){
			pr[u].push_back(i);
			len[u].push_back(1);
			ans=max(ans,1);
			while(a[u]%i==0) a[u]/=i;
		}
	if(a[u]>1) pr[u].push_back(a[u]),len[u].push_back(1),ans=max(ans,1);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
		FOR(x,0,(int)pr[u].size()-1) FOR(y,0,(int)pr[v].size()-1){
			if(pr[u][x]!=pr[v][y]) continue;
			ans=max(ans,len[u][x]+len[v][y]);
			len[u][x]=max(len[u][x],len[v][y]+1);
		}
	}
}
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	printf("%d\n",ans);
}