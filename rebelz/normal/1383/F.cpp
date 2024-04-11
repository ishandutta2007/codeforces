#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k,Q,tot,src,sink,top,vcnt;
int v[20005],c[20005],rev[20005],nxt[20005],h[10005],level[10005],q[10005],th[15][10005],tc[15][20005];
int d[2000],sum[2000],lg2[2000],x[10005],y[10005],z[10005],bef[15],vis[10005],fr[10005],fe[10005];

void addedge(int x,int y,ll z){
	v[++tot]=y; c[tot]=z; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=0; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
}

bool bfs(){
	memset(level,-1,sizeof(level));
	int front=0,rear=0;
	level[src]=0,q[rear++]=src;
	while(front<rear){
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p]){
			if(level[v[p]]<0&&c[p]){
				level[v[p]]=level[t]+1;
				q[rear++]=v[p];
			}
		}
		if(level[sink]>=0) return true;
	}
	return false;
}

int dfs(int u,int low){
	if(u==sink) return low;
	int res=0;
	for(int p=h[u];p;p=nxt[p]){
		if(level[v[p]]==level[u]+1&&c[p]){
			int flow=dfs(v[p],min(low,c[p]));
			res+=flow,low-=flow,c[p]-=flow,c[rev[p]]+=flow;
			if(low<=0) break;
		}
	}
	if(!res) level[u]=-1;
	return res;
}

int dinic(){
	int ret=0;
	while(bfs()) ret+=dfs(src,1<<30);
	return ret;
}

int bfss(){
	int front=0,rear=0;
	q[rear++]=src,vis[src]=++vcnt;
	while(front<rear){
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p]){
			if(vis[v[p]]!=vcnt&&c[p]){
				vis[v[p]]=vcnt;
				fr[v[p]]=t,fe[v[p]]=p;
				if(v[p]==n){
					int flow=1<<30;
					for(int u=n;u!=src;u=fr[u]) chkmin(flow,c[fe[u]]);
					for(int u=n;u!=src;u=fr[u]) c[fe[u]]-=flow,c[rev[fe[u]]]+=flow;
					return flow;
				}
				q[rear++]=v[p];
			}
		}
	}
	return 0;
}

int work(){
	int ret=0;
	while(1){
		int tmp=bfss();
		if(!tmp) return ret;
		ret+=tmp;
	}
}

int main(){
	n=readint(); m=readint(); k=readint(); Q=readint();
	src=1,sink=n;
	for(int i=1;i<=m;i++){
		x[i]=readint(); y[i]=readint(); z[i]=readint();
		if(z[i]) addedge(x[i],y[i],z[i]);
	}
	bef[1]=dinic();
	top=1;
	for(int i=1;i<=n;i++) th[1][i]=h[i];
	for(int i=1;i<=tot;i++) tc[1][i]=c[i];
	d[0]=bef[1];
	for(int i=1;i<(1<<k);i++){
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				for(int l=1;l<=n;l++) h[l]=th[top][l];
				for(int l=1;l<=tot;l++) c[l]=tc[top][l];
				addedge(x[j+1],y[j+1],25);
				break;
			}
			else top--,tot-=2;
		}
		d[i]=bef[top]+work();
		bef[++top]=d[i];
		for(int j=1;j<=n;j++) th[top][j]=h[j];
		for(int j=1;j<=tot;j++) tc[top][j]=c[j];
	}
	for(int i=2;i<(1<<k);i++) lg2[i]=lg2[i>>1]+1;
	while(Q--){
		for(int i=1;i<=k;i++) z[i]=readint();
		int ans=1<<30;
		for(int i=0;i<(1<<k);i++){
			if(i) sum[i]=sum[i^(i&(-i))]+z[lg2[i&(-i)]+1];
			chkmin(ans,d[i^((1<<k)-1)]+sum[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}