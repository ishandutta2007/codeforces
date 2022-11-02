#include<bits/stdc++.h>
using namespace std;
int n,k,deg[100010],son[100010];
vector<int> edge[100010];
vector<int> que[2];
int get_edgehog(){
	int now=0,cs=0;
	for (int i=1;i<=n;i++)
	if (deg[i]==1) que[now].push_back(i);
    while (que[now].size()>0){
		for (int i=0;i<que[now].size();i++){
			int tmp=que[now][i];
			for (int j=0;j<edge[tmp].size();j++)
			if (deg[edge[tmp][j]]>0) son[edge[tmp][j]]++;
		}
		for (int i=0;i<que[now].size();i++){
			int tmp=que[now][i];
			for (int j=0;j<edge[tmp].size();j++)
			if (deg[edge[tmp][j]]>0){
				if (son[edge[tmp][j]]<3) return -1;
				if (son[edge[tmp][j]]+1<deg[edge[tmp][j]]) return -1;
			}
		}
		for (int i=0;i<que[now].size();i++){
			int tmp=que[now][i];
			deg[tmp]=0;
			for (int j=0;j<edge[tmp].size();j++)
			if (deg[edge[tmp][j]]>0){
				son[edge[tmp][j]]=0;
				deg[edge[tmp][j]]--;
				if (deg[edge[tmp][j]]==1) que[now^1].push_back(edge[tmp][j]);
			}
		}
		que[now].clear();
		now=now^1;
		cs++;
    }
	return cs-1;
}
int main(){
	//freopen("B.in","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++){
		int o,p;
		scanf("%d%d",&o,&p);
		edge[o].push_back(p);
		edge[p].push_back(o);
		deg[o]++;
		deg[p]++;
	}
	int tmp=get_edgehog();
	//printf("%d",tmp);
	if (tmp==k) printf("Yes\n");
	else printf("No\n");
}