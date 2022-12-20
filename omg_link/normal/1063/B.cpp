#include <stdio.h>
#include <queue>
#define MN 2000
typedef struct{int x,y;}pii;
int n,m,x,y,l,r,ans=0;
int L[MN+5][MN+5],R[MN+5][MN+5];
bool vis[MN+5][MN+5];
char mp[MN+5][MN+5];
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&l,&r);
	for(int i=1;i<=n;i++)
		scanf("%s",&mp[i][1]);
	std::deque<pii> q;
	L[x][y]=l,R[x][y]=r,vis[x][y]=true,ans++,q.push_front((pii){x,y}); 
	while(!q.empty()){
		pii u=q.front(); q.pop_front();
		if(u.x!=1&&mp[u.x-1][u.y]!='*'&&(!vis[u.x-1][u.y]))
			L[u.x-1][u.y]=L[u.x][u.y],R[u.x-1][u.y]=R[u.x][u.y],vis[u.x-1][u.y]=true,ans++,q.push_front((pii){u.x-1,u.y});
		if(u.x!=n&&mp[u.x+1][u.y]!='*'&&(!vis[u.x+1][u.y]))
			L[u.x+1][u.y]=L[u.x][u.y],R[u.x+1][u.y]=R[u.x][u.y],vis[u.x+1][u.y]=true,ans++,q.push_front((pii){u.x+1,u.y});
		if(u.y!=1&&mp[u.x][u.y-1]!='*'&&(!vis[u.x][u.y-1])&&L[u.x][u.y]!=0)
			L[u.x][u.y-1]=L[u.x][u.y]-1,R[u.x][u.y-1]=R[u.x][u.y],vis[u.x][u.y-1]=true,ans++,q.push_back((pii){u.x,u.y-1});
		if(u.y!=m&&mp[u.x][u.y+1]!='*'&&(!vis[u.x][u.y+1])&&R[u.x][u.y]!=0)
			L[u.x][u.y+1]=L[u.x][u.y],R[u.x][u.y+1]=R[u.x][u.y]-1,vis[u.x][u.y+1]=true,ans++,q.push_back((pii){u.x,u.y+1});
	}
	printf("%d",ans);
}