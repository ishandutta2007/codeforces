#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,fa[100010][22],ans;
LL a[100010],g[100010][22];
vector<int> edge[100010];
const int mo=1000000007;
int get(int x){
	LL now=a[x];
	int res=0,len;
	//printf("%d %d\n",x,res);
	while (x){
		len=1;
		//printf("gg\n");
		for (int i=20;i>=0;i--)
		if (fa[x][i]&&__gcd(now,g[x][i])==now){
			x=fa[x][i];
			len=len+(1<<i);
		}
		//printf("gg2\n");
		res=(res+1ll*now*len)%mo;
		x=fa[x][0];
		now=__gcd(now,a[x]);
		//printf("%d\n",x);
	}
	//printf("%d %d\n",x,res);
	return res;
}
void dfs(int x,int y){
	fa[x][0]=y;
	for (int i=0;i<20;i++) fa[x][i+1]=fa[fa[x][i]][i];
	g[x][0]=a[fa[x][0]];
	for (int i=0;i<20;i++) 
	if (fa[x][i]) g[x][i+1]=__gcd(g[x][i],g[fa[x][i]][i]);
	ans=(ans+get(x))%mo;
	for (int i=0;i<edge[x].size();i++)
	if (edge[x][i]!=y)
		dfs(edge[x][i],x);
}
int main(){
	//freopen("A.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<n;i++){
		int o,p;
		scanf("%d%d",&o,&p);
		edge[o].push_back(p);
		edge[p].push_back(o);
	}
	dfs(1,0);
	printf("%d\n",ans);
}