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

const int inf=1<<30;
int n,m,k,st,tot,src,sink;
int v[10005],c[10005],nxt[10005],rev[10005],h[105],lev[105],q[105],bel[105],now[55],x[55],y[55],num[55];
bool vis[105];

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; rev[tot]=tot+1; h[x]=tot;
	v[++tot]=x; c[tot]=0; nxt[tot]=h[y]; rev[tot]=tot-1; h[y]=tot;
}

bool bfs(){
	memset(lev,-1,sizeof(lev));
	int front=0,rear=0;
	q[rear++]=src,lev[src]=0;
	while(front<rear){
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p]){
			if(c[p]&&lev[v[p]]<0){
				lev[v[p]]=lev[t]+1;
				q[rear++]=v[p];
			}
		}
		if(lev[sink]>=0) return true;
	}
	return false;
}

int dfs(int u,int low){
	if(u==sink) return low;
	int res=0;
	for(int p=h[u];p;p=nxt[p]){
		if(c[p]&&lev[v[p]]==lev[u]+1){
			int flow=dfs(v[p],min(c[p],low));
			low-=flow,res+=flow,c[p]-=flow,c[rev[p]]+=flow;
			if(low<=0) break;
		}
	}
	if(!res) lev[u]=-1;
	return res;
}

int dinic(){
	int ret=0;
	while(bfs()) ret+=dfs(src,inf);
	return ret;
}

void dfs1(int u){
	if(u>=1&&u<=n) bel[u]=2;
	if(u>=n+1&&u<=n+n) bel[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]||!c[p]) continue;
		vis[v[p]]=1;
		dfs1(v[p]);
	}
}

ll check(int i,bool fl=0){
	int mina=inf,opt=0;
	ll res=0;
	for(int j=1;j<=k;j++) now[j]=x[j],res+=x[j];
	for(int j=1;j<=k;j++){
		if(j>=i) opt=i;
		if(j<i&&chkmin(mina,y[j])) opt=j;
		if(st>j) continue;
		res-=now[opt];
		now[opt]-=y[opt],chkmax(now[opt],0);
		res+=now[opt];
		if(fl) num[opt]++;
	}
	if(fl){
		vis[src]=1;
		for(int i=1;i<=n;i++) bel[i]=1; //cut
		for(int i=n+1;i<=n+n;i++) bel[i]=2; //non cut
		dfs1(src);
		vector<int> vec(0);
		for(int i=1;i<=n+n;i++) if(bel[i]==1) vec.pb(i);
		int pl=0;
		printf("%d\n",k+max(0,k-st+1));
		for(int i=1;i<=k;i++){
			for(int j=0;j<num[i];j++) printf("%d ",vec[pl+j]<=n?vec[pl+j]:-vec[pl+j]+n);
			printf("0 ");
			pl+=num[i];
		}
		printf("\n");
	}
	return res;
}

int main(){
	n=readint(); m=readint(); k=readint();
	for(int i=1;i<=m;i++){
		int x,y;
		x=readint(); y=readint();
		addedge(x,y+n,inf);
	}
	src=0,sink=n+n+1;
	for(int i=1;i<=n;i++) addedge(src,i,1);
	for(int i=1;i<=n;i++) addedge(i+n,sink,1);
	st=n-dinic();
	for(int i=1;i<=k;i++) x[i]=readint(),y[i]=readint();
	ll ans=-1;
	int pl=0;
	for(int i=1;i<=k;i++) if(chkmax(ans,check(i))) pl=i;
	check(pl,1);
	return 0;
}