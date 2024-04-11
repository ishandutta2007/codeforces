#include<bits/stdc++.h>
using namespace std;
int t,n,m,vis[1000010];
vector<int> edge[1000010],redge[1000010];
queue<int> q;
int bfs(int x,const vector<int> e[]){
	for (int i=1;i<=n;i++) vis[i]=0;
	int res=1;
	q.push(x);
	vis[x]=1;
	while (!q.empty()){
		int now=q.front();
		q.pop();
		for (int i=0;i<e[now].size();i++)
		if (!vis[e[now][i]]){
			vis[e[now][i]]=1;
			q.push(e[now][i]);
			res++;
		}
	}
	return res;
}
int main(){
	//freopen("D.in","r",stdin);
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) edge[i].clear(),redge[i].clear(),vis[i]=0;
		for (int i=0;i<m;i++){
			int o,p;
			scanf("%d%d",&o,&p);
			if (o!=p){
				edge[o].push_back(p);
				redge[p].push_back(o);
			}
		}
		int f=0;
		if (n>1){
			for (int i=1;i<=n;i++)
			if (edge[i].size()==0){
				printf("Yes\n");
				printf("1 %d\n",n-1);
				printf("%d\n",i);
				for (int j=1;j<=n;j++)
				if (i!=j) printf("%d ",j);
				printf("\n");
				f=1;
				break;
			}
		}
		if (!f){
			int tmp=bfs(1,edge);
			if (tmp!=n){
				printf("Yes\n");
				printf("%d %d\n",tmp,n-tmp);
				for (int i=1;i<=n;i++)
				if (vis[i]==1) printf("%d ",i);
				printf("\n");
				for (int i=1;i<=n;i++)
				if (vis[i]==0) printf("%d ",i);
				printf("\n");
			}
			else{
				tmp=bfs(1,redge);
				if (tmp!=n){
					printf("Yes\n");
					printf("%d %d\n",n-tmp,tmp);
					for (int i=1;i<=n;i++)
					if (vis[i]==0) printf("%d ",i);
					printf("\n");
					for (int i=1;i<=n;i++)
					if (vis[i]==1) printf("%d ",i);
					printf("\n");
				}
				else printf("No\n");
			}
		}
	}
}