#include<iostream>
#include<string.h>

using namespace std;

int n,m,s,t;
int q[1005],c[1005][1005],dep1[1005],dep2[1005];
bool vis[1005];

void bfs1(int u){
	int front=0,rear=0;
	q[rear++]=u;
	dep1[u]=0;
	vis[u]=true;
	while(front<rear){
		int t=q[front++];
		for(int i=1;i<=n;i++){
			if(!vis[i]&&c[t][i]==1){
				dep1[i]=dep1[t]+1;
				vis[i]=true;
				q[rear++]=i;
			}
		}
	}
}

void bfs2(int u){
	memset(vis,false,sizeof(vis));
	int front=0,rear=0;
	q[rear++]=u;
	dep2[u]=0;
	vis[u]=true;
	while(front<rear){
		int t=q[front++];
		for(int i=1;i<=n;i++){
			if(!vis[i]&&c[t][i]==1){
				dep2[i]=dep2[t]+1;
				vis[i]=true;
				q[rear++]=i;
			}
		}
	}
}

int main(){
	cin>>n>>m>>s>>t;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		c[x][y]=c[y][x]=1;
	}
	for(int i=1;i<=n;i++)
		c[i][i]=1;
	bfs1(s);
	bfs2(t);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!c[i][j]&&min(dep1[i]+dep2[j]+1,dep1[j]+dep2[i]+1)>=dep1[t]){
				ans++;
				c[i][j]=c[j][i]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}