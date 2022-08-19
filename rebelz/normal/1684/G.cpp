// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int inf=1<<30;
int n,m,tot,src,sink;
int v[800005],c[800005],rev[800005],nxt[800005],h[200005],lev[200005],q[200005];
ll a[1005];
bool vis[200005];

void addedge(int x,int y,int z){
//	cout<<"edge "<<x<<' '<<y<<endl;
	v[++tot]=y; c[tot]=z; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=0; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
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
 
int dfs(int u,int low){
	if(u==sink) return low;
	int res=0;
	for(int p=h[u];p;p=nxt[p]){
		if(c[p]&&lev[v[p]]==lev[u]+1){
			int flow=dfs(v[p],min(low,c[p]));
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

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int num=0;
	src=0,sink=n+1;
	for(int i=1;i<=n;i++){
		if(3*a[i]<=m) addedge(src,i,1);
		else{
			num++;
			addedge(i,sink,1);
			for(int j=1;j<=n;j++)
				if(3*a[j]<=m&&a[i]%a[j]==0&&2*a[i]+a[j]<=m)
					addedge(j,i,1);
		}
	}
	if(dinic()!=num) return printf("-1\n"),0;
	vector<pii> vec(0);
	for(int i=1;i<=n;i++){
		if(3*a[i]>m){
			for(int p=h[i];p;p=nxt[p])
				if(c[p]&&v[p]<=n)
					vec.pb(mp(2*a[i]+a[v[p]],a[i]+a[v[p]])),vis[v[p]]=1;//,cout<<"??? "<<i<<' '<<v[p]<<endl;
		}
	}
	for(int i=1;i<=n;i++) if(3*a[i]<=m&&!vis[i]) vec.pb(mp(3*a[i],2*a[i]));
	printf("%d\n",vec.size());
	for(auto r:vec) printf("%d %d\n",r.fi,r.se);
	return 0;
}