#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int inf=0x3f3f3f3f;
int n,k,src,sink,tot=0,ncnt,vcnt;
int a[1100000],lab[1100000],tmp[1100000];
pair<int,pii> val[22000000];
int dis[80005],v[1000005],c[1000005],w[1000005],rev[1000005],nxt[1000005],h[80005],prv[80005],pre[80005],q[1000005];
bool vis[80005];

void addedge(int x,int y,int z,int f){
	v[++tot]=y; c[tot]=z; w[tot]=f; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=0; w[tot]=-f; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
}

bool spfa(){
	for(int i=0;i<=ncnt+1;i++) dis[i]=inf,vis[i]=0;
	int front=0,rear=0;
	dis[src]=0,vis[src]=true;
	q[rear++]=src;
	while(front<rear){
		int t=q[front++];
		vis[t]=false;
		for(int p=h[t];p;p=nxt[p]){
			if(c[p]>0&&dis[v[p]]>dis[t]+w[p]){
				dis[v[p]]=dis[t]+w[p];
				prv[v[p]]=t;
				pre[v[p]]=p;
				if(!vis[v[p]]){
					vis[v[p]]=true;
					q[rear++]=v[p];
				}
			}
		}
	}
	if(dis[sink]<inf) return true;
	return false;
}

int augment(){
	int flow=inf;
	for(int u=sink;u!=src;u=prv[u]) flow=min(flow,c[pre[u]]);
	for(int u=sink;u!=src;u=prv[u]){
		c[pre[u]]-=flow;
		c[rev[pre[u]]]+=flow;
	}
	return flow;
}

int mincostflow(){
	int maxflow=0,totcost=0,flow;
	while(spfa()){
		flow=augment();
		maxflow+=flow,totcost+=flow*dis[sink];
		if(maxflow==k) break;
	}
	return totcost;
}

int main(){
	n=readint(); k=readint();
	for(int i=0;i<(1<<n);i++) a[i]=readint();
	for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) if(!(i&(1<<j))) val[++vcnt]=mp(-a[i]-a[i^(1<<j)],mp(i,i^(1<<j)));
	int C=min(2*k*n,vcnt);
	nth_element(val+1,val+C+1,val+vcnt+1);
	for(int i=1;i<=C;i++){
		if(!lab[val[i].se.fi]) lab[val[i].se.fi]=++ncnt,tmp[ncnt]=val[i].se.fi;
		if(!lab[val[i].se.se]) lab[val[i].se.se]=++ncnt,tmp[ncnt]=val[i].se.se;
	}
	src=0,sink=ncnt+1;
	for(int i=1;i<=ncnt;i++){
		if(__builtin_popcount(tmp[i])&1) addedge(src,i,1,0);
		else addedge(i,sink,1,0);
	}
	for(int i=1;i<=C;i++){
		if(__builtin_popcount(val[i].se.fi)&1) addedge(lab[val[i].se.fi],lab[val[i].se.se],1,val[i].fi);
		else addedge(lab[val[i].se.se],lab[val[i].se.fi],1,val[i].fi);
	}
	printf("%d\n",-mincostflow());
	return 0;
}