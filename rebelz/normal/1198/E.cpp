#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}



struct node{
	int x1,y1,x2,y2;
}a[55];

const int inf=1<<30;
int n,m,nx,ny,tot,src,sink;
ll px[105],py[105],hv[105][105],v[200005],c[200005],rev[200005],nxt[200005],h[100005],level[100005];
ll d[105][105],q[200005];

void addedge(int x,int y,int z){
//	cout<<"edge "<<x<<' '<<y<<' '<<z<<endl;
	v[++tot]=y; c[tot]=z; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=0; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
}

bool bfs(){
	memset(level,-1,sizeof(level));
	int front=0,rear=0;
	q[rear++]=src; level[src]=0;
	while(front<rear){
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p]){
			if(c[p]&&level[v[p]]<0){
				level[v[p]]=level[t]+1;
				q[rear++]=v[p];
			}
		}
		if(level[sink]>0) return true;
	}
	return false;
}

int dfs(int u,ll low){
	if(u==sink) return low;
	ll res=0;
	for(int p=h[u];p;p=nxt[p]){
		if(level[v[p]]==level[u]+1&&c[p]){
			int flow=dfs(v[p],min(low,c[p]));
			res+=flow,low-=flow,c[p]-=flow,c[rev[p]]+=flow;
			if(low<=0) break;
		}
	}
	return res;
}

int dinic(){
	int maxflow=0;
	while(bfs()) maxflow+=dfs(src,inf);
	return maxflow;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) a[i].x1=readint(),a[i].y1=readint(),a[i].x2=readint()+1,a[i].y2=readint()+1;
	for(int i=1;i<=m;i++) px[2*i-1]=a[i].x1,px[2*i]=a[i].x2,py[2*i-1]=a[i].y1,py[2*i]=a[i].y2;
	sort(px+1,px+2*m+1);
	sort(py+1,py+2*m+1);
	nx=unique(px+1,px+2*m+1)-px-1;
	ny=unique(py+1,py+2*m+1)-py-1;
	for(int i=1;i<=m;i++) a[i].x1=lower_bound(px+1,px+nx+1,a[i].x1)-px,a[i].y1=lower_bound(py+1,py+ny+1,a[i].y1)-py,a[i].x2=lower_bound(px+1,px+nx+1,a[i].x2)-px,a[i].y2=lower_bound(py+1,py+ny+1,a[i].y2)-py;
	for(int i=1;i<=m;i++)
		for(int j=a[i].x1;j<a[i].x2;j++)
			for(int k=a[i].y1;k<a[i].y2;k++)
				hv[j][k]=1;
	sink=nx*ny+2*max(nx,ny)+1;
	for(int j=1;j<=nx-1;j++) for(int k=1;k<=ny-1;k++) if(hv[j][k]) addedge(nx*ny+j,(j-1)*ny+k,inf),addedge((j-1)*ny+k,nx*ny+max(nx,ny)+k,inf);
	for(int i=1;i<=nx-1;i++) addedge(src,nx*ny+i,px[i+1]-px[i]);
	for(int i=1;i<=ny-1;i++) addedge(nx*ny+max(nx,ny)+i,sink,py[i+1]-py[i]);
	cout<<dinic()<<endl;
	return 0;
}