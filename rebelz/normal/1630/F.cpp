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

const int inf=1<<30,N=50000;
int n,tot,src,sink;
int h[200005],v[10000005],nxt[10000005],c[10000005],rev[10000005],lev[200005],q[200005],a[50005],hv[50005];
vector<int> dv[50005];

int id(int x,int y){return 4*(x-1)+y;}

void clear(){
	for(int i=src;i<=sink;i++) h[i]=0; tot=0;
}

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; rev[tot]=tot+1; h[x]=tot;
	v[++tot]=x; c[tot]=0; nxt[tot]=h[y]; rev[tot]=tot-1; h[y]=tot;
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
			res+=flow,low-=flow,c[p]-=flow,c[rev[p]]+=flow;
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

int main(){
	for(int i=1;i<=N;i++)
		for(int j=i+i;j<=N;j+=i)
			dv[j].pb(i);
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n;i++) hv[a[i]]=i;
		src=0,sink=4*n+1;
		clear();
		for(int i=1;i<=n;i++) addedge(src,id(i,1),1),addedge(id(i,2),id(i,3),1),addedge(id(i,4),sink,1);
		for(int i=1;i<=n;i++){
			for(auto r:dv[a[i]]){
				if(hv[r]){
					addedge(id(hv[r],1),id(i,2),1);
					addedge(id(hv[r],3),id(i,4),1);
				}
			}
		}
		printf("%d\n",dinic());
		for(int i=1;i<=n;i++) hv[a[i]]=0;
	}
	return 0;
}