#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T;
int n,m;
int x,y;
struct node{
	int next,to;
}a[N*2];
int head[N],cnt;
void add(int e,int r){
	a[++cnt].next=head[e];a[cnt].to=r;head[e]=cnt;
}
struct fz{
	int id,val;
	friend bool operator < (fz x,fz y){
		return x.val>y.val;
	}
};
priority_queue<fz>q;
int dis[N],pd[N];
void diji(){
	memset(dis,10,sizeof(dis));
	memset(pd,0,sizeof(pd));
	dis[1]=0;
	q.push((fz){1,0});
	while(!q.empty()){
		fz u=q.top();
		q.pop();
		if(pd[u.id])continue;
		pd[u.id]=1;
		for(int i=head[u.id];i;i=a[i].next){
			if(dis[a[i].to]>dis[u.id]+1){
				dis[a[i].to]=dis[u.id]+1;
				q.push((fz){a[i].to,dis[a[i].to]});
			}
		}
	}
}
int f[N];
int dfs(int u){
	if(f[u]<1000086)return f[u];
	for(int i=head[u];i;i=a[i].next){
		if(dis[a[i].to]>dis[u]){
			f[u]=min(f[u],dfs(a[i].to));
		}
		else{
			f[u]=min(f[u],dis[a[i].to]);
		}
	}
	f[u]=min(f[u],dis[u]);
	return f[u];
}
int da[N];
int main(){
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		cnt=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		diji();
		memset(f,10,sizeof(f));
		for(int i=1;i<=n;i++){
			da[i]=dfs(i);
			printf("%d ",da[i]);
		}
		puts("");
	}
	return 0;
}