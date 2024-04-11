#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
using namespace std;
const int N=(int)1e5+9;
set<int> G[N],P;
int vis[N];
void bfs(int x){
	vis[x]=1;
	P.erase(x);
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		set<int>::iterator it;
		for(it=P.begin();it!=P.end();){
			int v=*it;
			++it;
			if(G[u].find(v)==G[u].end()){
				vis[v]=1;
				q.push(v);
				P.erase(v);
			}
		} 
	} 
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)P.insert(i);
	rep(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].insert(v);
		G[v].insert(u);
	} 
	int ans=0;
	rep(i,1,n+1){
		if(!vis[i]){
			ans++;
			bfs(i);
		}
	}
	printf("%d",ans-1);
}