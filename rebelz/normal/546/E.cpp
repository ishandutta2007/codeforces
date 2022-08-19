#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int inf=1<<30;
int n,m,tot=0,src,sink;
int v[4005],c[4005],rev[4005],nxt[4005],h[1005],a[105],b[105],ans[105][105],level[1005],q[1005];

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; rev[tot]=tot+1; h[x]=tot;
	v[++tot]=x; c[tot]=0; nxt[tot]=h[y]; rev[tot]=tot-1; h[y]=tot;
}

bool bfs(){
	memset(level,-1,sizeof(level));
	int front=0,rear=0;
	level[src]=0; q[rear++]=src;
	while(front<rear){
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p]){
			if(c[p]>0&&level[v[p]]<0){
				level[v[p]]=level[t]+1;
				q[rear++]=v[p];
			}
		}
	}
	if(level[sink]>0) return true;
	return false;
}

int dfs(int u,int low){
	if(u==sink) return low;
	int res=0;
	for(int p=h[u];p;p=nxt[p]){
		if(c[p]>0&&level[v[p]]==level[u]+1){
			int flow=dfs(v[p],min(low,c[p]));
			res+=flow,c[p]-=flow,c[rev[p]]+=flow,low-=flow;
			if(low<=0) break;
		}
	}
	if(!res) level[u]=-1;
	return res;
}

int main(){
	n=readint(); m=readint();
	src=0,sink=n+n+1;
	int suma=0,sumb=0;
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) b[i]=readint();
	for(int i=1;i<=n;i++) suma+=a[i],sumb+=b[i];
	for(int i=1;i<=n;i++) addedge(src,i,a[i]),addedge(i+n,sink,b[i]);
	for(int i=1;i<=n;i++) addedge(i,i+n,inf);
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		addedge(x,y+n,inf); addedge(y,x+n,inf);
	}
	int maxflow=0;
	while(bfs()) maxflow+=dfs(src,inf);
	if(maxflow!=suma||maxflow!=sumb) return printf("NO\n"),0;
	printf("YES\n");
	for(int i=1;i<=n;i++) for(int p=h[i];p;p=nxt[p]) if(v[p]>=n+1&&v[p]<=n+n) ans[i][v[p]-n]=c[rev[p]];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}