#include<bits/stdc++.h>
using namespace std;
int n,m,tar[100010],f[100010],sta;
vector<int> edge[100010],res;
int get(int x){
	if (f[x]==x) return x;
	f[x]=get(f[x]);
	return f[x];
}
void dfs(int x,int y){
	for (int i=0;i<edge[x].size();i++)
	if (edge[x][i]!=y){
		res.push_back(x);
		tar[x]^=1;
		dfs(edge[x][i],x);
		if (tar[edge[x][i]]){
			res.push_back(x);
			res.push_back(edge[x][i]);
			tar[x]^=1;
			tar[edge[x][i]]^=1;
		}
	}
	if (y||tar[x]) res.push_back(x),tar[x]^=1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=0;i<m;i++){
		int o,p;
		scanf("%d%d",&o,&p);
		if (get(o)!=get(p)){
			edge[o].push_back(p);
			edge[p].push_back(o);
			f[get(p)]=o;
		}
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&tar[i]);
		if (tar[i]) sta=i;
	}
	if (sta) dfs(sta,0);
	for (int i=1;i<=n;i++)
	if (tar[i]){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",res.size());
	for (int i=0;i<res.size();i++) printf("%d ",res[i]);
}