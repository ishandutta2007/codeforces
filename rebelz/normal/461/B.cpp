#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

const int cys=1000000007;
int n,tot=0;
int v[200005],nxt[200005],h[100005],c[100005];
long long d[100005][2];

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void dfs(int u){
	if(c[u]==0)
		d[u][0]=1,d[u][1]=0;
	else
		d[u][0]=0,d[u][1]=1;
	for(int p=h[u];p;p=nxt[p]){
		dfs(v[p]);
		d[u][1]=(d[u][1]*(d[v[p]][0]+d[v[p]][1])%cys+d[u][0]*d[v[p]][1]%cys)%cys;
		d[u][0]=d[u][0]*(d[v[p]][0]+d[v[p]][1])%cys;
	}
}

int main(){
	scanf("%d",&n);
	int x;
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		addedge(x+1,i);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	dfs(1);
	printf("%lld\n",d[1][1]);
	return 0;
}