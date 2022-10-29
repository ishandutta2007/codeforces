#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e6+50;
const int S=24;
int n,tot,ans,ra,rb;
int fa[maxn][S],dep[maxn];
void jump(int &b,int step){for(int i=0;i<S;i++)if((1<<i)&step)b=fa[b][i];}
int lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	jump(v,dep[v]-dep[u]);
	if(u==v)return v;
	for(int i=S-1;i>=0;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int dist(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
int main(){
	scanf("%d",&n);
	tot=4,ans=2,ra=2,rb=3;
	dep[1]=0;dep[2]=dep[3]=dep[4]=1;
	fa[2][0]=fa[3][0]=fa[4][0]=1;
	while(n--){
		int x,u,v;
		scanf("%d",&x);
		fa[u=(++tot)][0]=x,fa[v=(++tot)][0]=x;
		dep[u]=dep[v]=dep[x]+1;
		for(int i=1;i<S;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
		for(int i=1;i<S;i++)fa[v][i]=fa[fa[v][i-1]][i-1];
		//printf("u=%d v=%d\n",u,v);
		int dis_ura=dist(u,ra),dis_urb=dist(u,rb);
		//printf("ra=%d rb=%d dis_ura=%d dis_urb=%d\n",ra,rb,dis_ura,dis_urb);
		if(dis_ura<dis_urb)swap(ra,rb),swap(dis_ura,dis_urb);
		if(dis_ura>ans)rb=u,ans=dis_ura;
		printf("%d\n",ans);
	}
	return 0;
}