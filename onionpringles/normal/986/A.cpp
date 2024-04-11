#include <bits/stdc++.h>
using namespace std;
const int N=101010;
vector<int> adj[N];
int dist[N][100];
int q[N],qs,qe,chk[N];
int main(){
	int n,m,k,s;scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);x--;
		adj[n+x].push_back(i);
	}
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n+k;j++)chk[j]=0;
		qs=qe=0;
		chk[n+i]=1;
		q[qe++]=n+i;
		dist[n+i][i]=0;
		while(qs<qe){
			int u=q[qs++];
			for(auto &x:adj[u]){
				if(chk[x])continue;
				chk[x]=1;
				dist[x][i]=dist[u][i]+1;
				q[qe++]=x;
			}
		}
	}
	for(int i=0;i<n;i++){
		sort(dist[i],dist[i]+k);
		int ans=0;
		for(int j=0;j<s;j++)ans+=dist[i][j]-1;
		printf("%d ",ans);
	}
	puts("");
}