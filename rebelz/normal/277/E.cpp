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
int n,tot,src,sink;
int v[500005],c[500005],rev[500005],nxt[500005],h[2005],pree[2005],prec[2005];
double w[500005],dis[2005],x[2005],y[2005];
bool vis[2005];

void addedge(int x,int y,int z,double f){
	v[++tot]=y; c[tot]=z; w[tot]=f; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=0; w[tot]=-f; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
}

double dist(int i,int j){return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));}

bool spfa(){
	for(int i=src;i<=sink;i++) dis[i]=inf;
	memset(vis,false,sizeof(vis));
	queue<int> q;
	dis[src]=0,vis[src]=true; q.push(src);
	while(!q.empty()){
		int t=q.front(); q.pop();
		vis[t]=false;
		for(int p=h[t];p;p=nxt[p]){
			if(c[p]>0&&dis[v[p]]>dis[t]+w[p]){
				dis[v[p]]=dis[t]+w[p];
				prec[v[p]]=t,pree[v[p]]=p;
				if(!vis[v[p]]){
					vis[v[p]]=true;
					q.push(v[p]);
				}
			}
		}
	}
	if(dis[sink]<inf) return true;
	return false;
}

int augment(){
	int flow=inf;
	for(int u=sink;u!=src;u=prec[u]) flow=min(flow,c[pree[u]]);
	for(int u=sink;u!=src;u=prec[u]){
		c[pree[u]]-=flow;
		c[rev[pree[u]]]+=flow;
	}
	return flow;
}

int main(){
	n=readint();
	src=0,sink=n+n+1;
	for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
	for(int i=1;i<=n;i++) addedge(src,i,2,0);
	for(int i=1;i<=n;i++) addedge(i+n,sink,1,0);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j&&y[i]>y[j]) addedge(i,j+n,1,dist(i,j));
	double maxflow=0,mincost=0,flow;
	while(spfa()){
		flow=augment();
//		cout<<"TEST "<<flow<<' '<<dis[sink]<<' '<<inf<<endl;
//		for(int i=src;i<=sink;i++) for(int p=h[i];p;p=nxt[p]) if(c[p]>0) cout<<i<<"->"<<v[p]<<' '<<c[p]<<endl;
		maxflow+=flow,mincost+=flow*dis[sink];
	}
	if(maxflow!=n-1) return printf("-1\n"),0;
	printf("%.10lf\n",mincost);
	return 0;
}