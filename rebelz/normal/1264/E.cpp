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

const int inf=0x3f3f3f3f;
int n,m,src,sink,cnt,tot;
int v[100005],c[100005],w[100005],rev[100005],nxt[100005],h[5005],du[105],dis[5005],pre[5005],prv[5005],q[100005],res[55][55];
bool vis[5005];

void addedge(int x,int y,int z,int f){
	v[++tot]=y; c[tot]=z; w[tot]=f; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=0; w[tot]=-f; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
}

bool spfa(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	int front=0,rear=0;
	dis[src]=0,q[rear++]=src;
	while(front<rear){
		int t=q[front++];
		vis[t]=0;
		for(int p=h[t];p;p=nxt[p]){
			if(c[p]&&chkmin(dis[v[p]],dis[t]+w[p])){
				pre[v[p]]=p,prv[v[p]]=t;
				if(!vis[v[p]]) q[rear++]=v[p],vis[v[p]]=1;
			}
		}
	}
	return dis[sink]<inf;
}

int augment(){
	int flow=inf;
	for(int u=sink;u!=src;u=prv[u]) chkmin(flow,c[pre[u]]);
	for(int u=sink;u!=src;u=prv[u]) c[pre[u]]-=flow,c[rev[pre[u]]]+=flow;
	return flow;
}

int mincostflow(){
	int ret=0;
	while(spfa()) ret+=augment()*dis[sink];
	return ret;
}

int main(){
	n=readint(); m=readint();
	cnt=n;
	int ans=0;
	memset(res,-1,sizeof(res));
	for(int i=1;i<=n;i++) res[i][i]=0;
	for(int i=1;i<=m;i++){
		int x=readint(),y=readint();
		ans+=du[x],du[x]++;
		res[x][y]=1,res[y][x]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(res[i][j]>=0) continue;
			if(i>=j) continue;
			cnt++;
			addedge(0,cnt,1,0);
			addedge(cnt,i,1,0);
			addedge(cnt,j,1,0);
		}
	}
	for(int i=1;i<=n;i++) for(int j=du[i]+1;j<=n;j++) addedge(i,cnt+1,1,j-1);
	src=0,sink=cnt+1;
	mincostflow();
	for(int i=n+1;i<=cnt;i++){
		vector<int> vec(0); int tmp=0;
		for(int p=h[i];p;p=nxt[p]){
			vec.pb(v[p]);
			if(!c[p]) tmp=v[p];
		}
		if(tmp==vec[0]) res[vec[0]][vec[1]]=1,res[vec[1]][vec[0]]=0;
		else res[vec[1]][vec[0]]=1,res[vec[0]][vec[1]]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) printf("%d",res[i][j]);
		printf("\n");
	}
	return 0;
}