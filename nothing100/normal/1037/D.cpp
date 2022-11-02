#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,fa[200020],dfn[200020],a[200020];
vector<int> edge[200020]; 
void dfs(int x){
	for (int i=0;i<edge[x].size();i++)
	if (edge[x][i]!=fa[x]){
		fa[edge[x][i]]=x;
		dfs(edge[x][i]);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int o,p;
		scanf("%d%d",&o,&p);
		edge[o].push_back(p);
		edge[p].push_back(o);
	}
	dfs(1);
	int bo=1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (a[1]!=1) bo=0;
	dfn[1]=1;
	for (int i=2;i<=n;i++){
		if (!dfn[fa[a[i]]]) bo=0;
		if (dfn[fa[a[i]]]<dfn[fa[a[i-1]]]) bo=0;
		dfn[a[i]]=i;
	}
	if (bo) printf("Yes\n");
	else printf("No\n");
	return 0;
}