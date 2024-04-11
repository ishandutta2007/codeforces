#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

map<int,int> mp;
const int inf=1<<30;
int n,tot,src,sink,cnt,k;
int v[10005],c[10005],w[10005],rev[10005],nxt[10005],h[10005],dis[10005],prec[10005],pree[10005],s[10005],t[10005],d[10005],g[10005];
bool vis[10005];

int addedge(int x,int y,int z,int f){
	v[++tot]=y; c[tot]=z; w[tot]=f; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=0; w[tot]=-f; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
	return tot-1;
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
	n=readint(); k=readint();
	for(int i=1;i<=n;i++){
		s[i]=readint(); t[i]=readint(); d[i]=readint();
		t[i]=s[i]+t[i]-1;
		mp[s[i]]=1,mp[t[i]+1]=1;
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) it->second=++cnt;
	src=0,sink=cnt+1;
	for(int i=1;i<=cnt-1;i++) addedge(i,i+1,k,0);
	addedge(src,1,k,0); addedge(cnt,sink,k,0);
	for(int i=1;i<=n;i++) g[i]=addedge(mp[s[i]],mp[t[i]+1],1,-d[i]);
	while(spfa()) augment();
	for(int i=1;i<=n;i++) printf("%d ",c[rev[g[i]]]);
	printf("\n");
	return 0;
}