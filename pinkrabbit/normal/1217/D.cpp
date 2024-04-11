#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,q,k;
int a[MN],b[MN],u[MN],v[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int vis[MN],ok;
void dfs(int u){
	vis[u]=1;
	for(int i=h[u];i;i=nxt[i]){
		if(!vis[to[i]])dfs(to[i]);
		else if(vis[to[i]]==1)ok=1;
	}
	vis[u]=2;
}
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,m)scanf("%d%d",&u[i],&v[i]),ins(u[i],v[i]);
	F(i,1,n)if(!vis[i])dfs(i);
	if(!ok){puts("1");F(i,1,m)printf("%d%c",1," \n"[i==m]);}
	else{puts("2");F(i,1,m)printf("%d%c",u[i]<v[i]?1:2," \n"[i==m]);}
	return 0;
}