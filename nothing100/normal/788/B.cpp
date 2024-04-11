#include<bits/stdc++.h>
#define LL long long
using namespace std;
vector<int> g[1000100];
int n,m,vis[1000100],cnt,que[1000100],zh[1000100],nzh;
LL ans;
int bfs(int x){
	vis[x]=1;
	que[1]=x;
	int tail=1;
	for (int head=1;head<=tail;head++){
		for (int i=0;i<g[que[head]].size();i++)
		if (!vis[g[que[head]][i]]){
			que[++tail]=g[que[head]][i];
			vis[g[que[head]][i]]=1;
		}
	}
	return tail;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++){
		int o,p;
		scanf("%d%d",&o,&p);
		if (o!=p) g[o].push_back(p);
		else{
			zh[o]=1;
			nzh++;
		}
		g[p].push_back(o);
	}
	for (int i=1;i<=n;i++)
	if (!vis[i]&&g[i].size()!=0){
		bfs(i);
		cnt++;
	}
	if (cnt!=1) printf("0\n");
	else{
		for (int i=1;i<=n;i++) ans+=((LL)g[i].size()*(g[i].size()-1)/2);
		for (int i=1;i<=n;i++)
		if (zh[i]) ans+=m-g[i].size()-nzh+1;
		ans+=(LL)nzh*(nzh-1)/2;
		printf("%lld\n",ans);
	}
}