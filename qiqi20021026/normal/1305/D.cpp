#include<bits/stdc++.h>

using namespace std;

#define N 1200

bool vis[N];
int n,xb,d[N],q[N];
vector<int> g[N];

void ers(int x){
	vis[x]=1;
	for (int i:g[x])
		if ((--d[i])==1){q[++xb]=i;}
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		g[x].push_back(y); g[y].push_back(x);
		++d[x]; ++d[y];
	}
	for (int i=1;i<=n;++i)
		if (d[i]==1){q[++xb]=i;}
	for (int i=1,t=0;i<=n/2;++i){
		int x=q[++t],y=q[++t];
		printf("? %d %d\n",x,y); fflush(stdout);
		int z; scanf("%d",&z);
		if (z==x||z==y){printf("! %d\n",z); fflush(stdout); return 0;}
		ers(x); ers(y);
	}
	for (int i=1;i<=n;++i) if (!vis[i]){printf("! %d\n",i); fflush(stdout); return 0;}
	
	return 0;
}