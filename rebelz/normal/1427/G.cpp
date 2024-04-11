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

const ll inf=1ll<<50;
const int dir[4][2]={0,1,0,-1,1,0,-1,0};
int n,m,tot,src,sink;
int v[1000005],nxt[1000005],rev[1000005],h[80005],lev[80005],res[205][205],lf[205][205],rg[205][205],a[205][205],q[80005],bel[80005],p[40005],lab[205][205];
bool vis[80005];
ll c[1000005];

void addedge(int x,int y,ll z,bool fl=0){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; rev[tot]=tot+1; h[x]=tot;
	v[++tot]=x; c[tot]=fl?z:0; nxt[tot]=h[y]; rev[tot]=tot-1; h[y]=tot;
}

bool bfs(){
	for(int i=src;i<=sink;i++) lev[i]=-1;
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
			low-=flow,res+=flow,c[p]-=flow,c[rev[p]]+=flow;
			if(low<=0) break;
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

void dfs1(int u,int t){
	if(u<=t&&u>=1) bel[u]=2;
	for(int p=h[u];p;p=nxt[p]){
		if(c[p]&&!vis[v[p]]){
			vis[v[p]]=1;
			dfs1(v[p],t);
		}
	}
}

void solve(int l,int r,vector<pii> &vec){
	if(!vec.size()) return;
	if(l==r){
		for(auto s:vec) res[s.fi][s.se]=p[l];
		return;
	}
	int mid=(l+r)/2;
	src=0,sink=vec.size()+1;
	for(int i=src;i<=sink;i++) h[i]=0; tot=0;
	for(int i=0;i<vec.size();i++) lab[vec[i].fi][vec[i].se]=i+1;
	for(int i=0;i<vec.size();i++){
		pii now=vec[i];
		ll cost1=0,cost2=0;
		for(int j=0;j<4;j++){
			int dx=now.fi+dir[j][0],dy=now.se+dir[j][1];
			if(a[dx][dy]<0) continue;
			if(dx==1||dx==n||dy==1||dy==n){
				if(a[dx][dy]<=p[mid]) cost2++;
				else cost1++;
			}
			else if(rg[dx][dy]<l) cost2++;
			else if(lf[dx][dy]>r) cost1++;
			else if(now.fi<=dx&&now.se<=dy) addedge(i+1,lab[dx][dy],1,1);
		}
		addedge(src,i+1,cost1);
		addedge(i+1,sink,cost2);
	}
	for(int i=0;i<vec.size();i++) lab[vec[i].fi][vec[i].se]=0;
	dinic();
	for(int i=0;i<vec.size();i++) bel[i+1]=1;
	for(int i=src;i<=sink;i++) vis[i]=0;
	vis[src]=1;
	dfs1(src,vec.size());
	vector<pii> lson(0),rson(0);
	for(int i=0;i<vec.size();i++){
		if(bel[i+1]==1) lson.pb(vec[i]),rg[vec[i].fi][vec[i].se]=mid;
		else rson.pb(vec[i]),lf[vec[i].fi][vec[i].se]=mid+1;
	}
	solve(l,mid,lson);
	solve(mid+1,r,rson);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=readint();
	ll ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[i][j]>0) p[++m]=a[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) res[i][j]=a[i][j];
	sort(p+1,p+m+1);
	m=unique(p+1,p+m+1)-p-1;
	vector<pii> vec(0);
	for(int i=2;i<n;i++) for(int j=2;j<n;j++) if(a[i][j]==0) vec.pb(mp(i,j)),lf[i][j]=1,rg[i][j]=m;
	solve(1,m,vec);
	for(int i=1;i<n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]>=0&&a[i+1][j]>=0) ans+=abs(res[i][j]-res[i+1][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<n;j++)
			if(a[i][j]>=0&&a[i][j+1]>=0) ans+=abs(res[i][j]-res[i][j+1]);
	printf("%lld\n",ans);
	return 0;
}