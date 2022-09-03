#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dist[102][102];
const int inf=1<<29;
int c;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);/**/
	int t,n;
	scanf("%d",&t);
	while(t--){
			   scanf("%d",&n);
			   for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i==j)dist[i][j]=0;else dist[i][j]=inf;
			   for(int i=1;i<n;i++){
			   		   int x,y;
			   		   scanf("%d%d",&x,&y);
			   		   dist[x][y]=dist[y][x]=1;
		}
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		if(dist[i][k]+dist[j][k]<dist[i][j])
		dist[i][j]=dist[i][k]+dist[k][j];
		int mx=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)mx=max(mx,dist[i][j]);
		c+=mx;
	}
	printf("%d\n",c);
	
	return 0;
}