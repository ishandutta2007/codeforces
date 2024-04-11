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

int n,m,k,tot;
int v[400005],nxt[400005],h[200005],q[200005][2],dis[2][200005],maxa[200005],a[200005];
pii p[200005];
bool vis[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void bfs(int s,int id){
	int front=0,rear=0;
	q[rear][0]=s,q[rear++][1]=0;
	while(front<rear){
		int u=q[front][0],t=q[front++][1];
		for(int p=h[u];p;p=nxt[p]){
			if(vis[v[p]]) continue;
			vis[v[p]]=1,dis[id][v[p]]=t+1;
			q[rear][0]=v[p],q[rear++][1]=t+1;
		}
	}
}

bool check(int x){
	maxa[k+1]=-(1<<30);
	for(int i=k;i>=1;i--){
		int pl=lower_bound(p+1,p+k+1,mp(x-1-dis[0][p[i].se],0))-p;
		chkmax(pl,i+1);
		if(maxa[pl]+dis[1][p[i].se]+1>=x) return true;
		maxa[i]=max(maxa[i+1],dis[0][p[i].se]);
	}
	return false;
}

int main(){
	n=readint(); m=readint(); k=readint();
	for(int i=1;i<=k;i++) a[i]=readint();
	for(int i=1;i<=m;i++) addedge(readint(),readint());
	vis[1]=1; bfs(1,0);
	memset(vis,0,sizeof(vis));
	vis[n]=1; bfs(n,1);
	int ans=dis[0][n];
	for(int i=1;i<=k;i++) p[i]=mp(dis[1][a[i]],a[i]);
	sort(p+1,p+k+1);
	int l=1,r=ans,res=ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) res=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",res);
	return 0;
}