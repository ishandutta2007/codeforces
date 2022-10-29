#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,b,a) for(int i=b-1;i>=a;i--)
#define N (int)1e6+9
using namespace std;
struct edge {
	int v,net;
}e[N];
int vis[N],head[N],ecnt,match[N];
void add(int u,int v){
	e[++ecnt]=(edge){u,head[v]},head[v]=ecnt;
	e[++ecnt]=(edge){v,head[u]},head[u]=ecnt;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		ecnt=0;
		scanf("%d%d",&n,&m);
		rep(i,1,3*n+1)vis[i]=0,head[i]=-1;
		rep(i,1,m+1){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		int cnt=0;
		rep(i,1,3*n+1){
			if(vis[i])continue;
			for(int u=head[i];~u;u=e[u].net){
				int v=e[u].v;
				if(vis[v])continue;
				vis[i]=1,vis[v]=1,match[++cnt]=(u+1)>>1;
				break;
			}
		}
		if(cnt>=n){
			printf("Matching\n");
			rep(i,1,n+1)printf("%d ",match[i]);
			printf("\n");
			continue; 
		}
		cnt=0;
		printf("IndSet\n");
		rep(i,1,3*n+1){
			if(!vis[i]){
				cnt++;
				printf("%d ",i);
			}
			if(cnt==n)break;
		}
		printf("\n");
	}
}