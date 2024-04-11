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
int n,q,src,sink,tot=0;
int v[20005],c[20005],w[20005],rev[20005],nxt[20005],h[20005],dis[20005],prec[20005],pree[20005],mina[20005],maxa[20005];
bool vis[20005];

void addedge(int x,int y,int z,int f){
	v[++tot]=y; c[tot]=z; w[tot]=f; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=0; w[tot]=-f; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
}

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
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) mina[i]=1,maxa[i]=n;
	int opt,x,y,z;
	while(q--){
		opt=readint(); x=readint(); y=readint(); z=readint();
		if(opt==1) for(int i=x;i<=y;i++) mina[i]=max(mina[i],z);
		else for(int i=x;i<=y;i++) maxa[i]=min(maxa[i],z);
	}
	for(int i=1;i<=n;i++) if(mina[i]>maxa[i]) return printf("-1\n"),0;
	src=0,sink=n+n+1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) addedge(src,i,1,2*j-1);
	for(int i=1;i<=n;i++) for(int j=mina[i];j<=maxa[i];j++) addedge(j,i+n,1,0);
	for(int i=1;i<=n;i++) addedge(i+n,sink,1,0);
	int ans=0;
	while(spfa()) ans+=augment()*dis[sink];
	printf("%d\n",ans);
	return 0;
}