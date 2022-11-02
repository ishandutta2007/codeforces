#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
using namespace std;
LL f[3030][3030],ans;
int n,cnt[3030][3030],g[3030][3030],sum[3030][3030],tot;
vector<int> edge[3030];
queue<pair<int,int> > q;
void dfs(int root,int x,int y){
	sum[root][x]=1;
	for (int i=0;i<edge[x].size();i++)
	if (edge[x][i]!=y){
		dfs(root,edge[x][i],x);
		sum[root][x]+=sum[root][edge[x][i]];
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) cnt[i][i]=-1;
	for (int i=1;i<n;i++){
		int o,p;
		scanf("%d%d",&o,&p);
		cnt[o][p]=++tot;
		q.push(mp(o,p));
		cnt[p][o]=++tot;
		q.push(mp(p,o));
		edge[o].push_back(p);
		edge[p].push_back(o);
	}
	for (int i=1;i<=n;i++) dfs(i,i,0);
	for (int i=1;i<=n;i++)
	for (int j=0;j<edge[i].size();j++){
		f[i][edge[i][j]]=1ll*sum[i][edge[i][j]]*sum[edge[i][j]][i];
	}
	while (!q.empty()){
		pair<int,int> now=q.front();
		q.pop();
		int o,p;
		o=now.first;
		p=now.second;
		ans=max(ans,f[o][p]);
		//printf("%d %d %d\n",o,p,f[o][p]);
		if (o<p){
			for (int k=0;k<2;k++){
				swap(o,p);
				for (int i=0;i<edge[o].size();i++){
					if (cnt[edge[o][i]][p]==0){
						cnt[edge[o][i]][p]=++tot;
						q.push(mp(edge[o][i],p));
						cnt[p][edge[o][i]]=++tot;
						q.push(mp(p,edge[o][i]));
					}
					if (cnt[edge[o][i]][p]<cnt[o][p]) continue;
					f[edge[o][i]][p]=max(f[edge[o][i]][p],f[o][p]+1ll*sum[edge[o][i]][p]*sum[p][edge[o][i]]);
					f[p][edge[o][i]]=f[edge[o][i]][p];
				}
			}
		}
	}
	printf("%lld\n",ans);
}