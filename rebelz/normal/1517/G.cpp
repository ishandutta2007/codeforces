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

const ll inf=1ll<<60;
int n,tot,src,sink;
int v[20005],rev[20005],nxt[20005],h[2005],lev[2005],q[20005],x[2005],y[2005];
ll c[20005],z[2005];
int knd[2][2]={1,2,0,3};

void addedge(int x,int y,ll z){
	v[++tot]=y; c[tot]=z; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=0; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
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

ll dfs(int u,ll low){
	if(u==sink) return low;
	ll res=0;
	for(int p=h[u];p;p=nxt[p]){
		if(c[p]&&lev[v[p]]==lev[u]+1){
			ll flow=dfs(v[p],min(c[p],low));
			res+=flow,low-=flow,c[p]-=flow,c[rev[p]]+=flow;
		}
	}
	if(!res) lev[u]=-1;
	return res;
}

ll dinic(){
	ll ret=0;
	while(bfs()) ret+=dfs(src,inf);
	return ret;
}

int main(){
	n=readint();
	ll all=0;
	for(int i=1;i<=n;i++) x[i]=readint(),y[i]=readint(),z[i]=readint(),all+=z[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j&&(ll)abs(x[i]-x[j])+(ll)abs(y[i]-y[j])<=1&&knd[x[j]&1][y[j]&1]==knd[x[i]&1][y[i]&1]+1) addedge(i+n,j,inf);
	src=0,sink=n+n+1;
	for(int i=1;i<=n;i++) if(knd[x[i]&1][y[i]&1]==0) addedge(src,i,inf);
	for(int i=1;i<=n;i++) if(knd[x[i]&1][y[i]&1]==3) addedge(i+n,sink,inf);
	for(int i=1;i<=n;i++) addedge(i,i+n,z[i]);
	printf("%lld\n",all-dinic());
	return 0;
}