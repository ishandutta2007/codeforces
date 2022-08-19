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

const int cys=1000000007;
int n,vcnt,ecnt,tot;
int x[100005],y[100005],px[100005],py[100005],v[200005],nxt[200005],h[200005];
ll pw[200005];
bool vis[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u){
	vcnt++;
	for(int p=h[u];p;p=nxt[p]){
		ecnt++;
		if(vis[v[p]]) continue;
		vis[v[p]]=1;
		dfs(v[p]);
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) px[i]=x[i]=readint(),py[i]=y[i]=readint();
	sort(px+1,px+n+1);
	sort(py+1,py+n+1);
	for(int i=1;i<=n;i++) x[i]=lower_bound(px+1,px+n+1,x[i])-px,y[i]=lower_bound(py+1,py+n+1,y[i])-py;
	for(int i=1;i<=n;i++) addedge(x[i],y[i]+n);
	pw[0]=1;
	for(int i=1;i<=n+n;i++) pw[i]=pw[i-1]*2%cys;
	ll ans=1;
	for(int i=1;i<=n+n;i++){
		if(vis[i]) continue;
		vcnt=ecnt=0,vis[i]=1;
		dfs(i);
		ecnt/=2;
		if(vcnt==ecnt+1) ans=1ll*ans*(pw[vcnt]-1)%cys;
		else ans=1ll*ans*pw[vcnt]%cys;
	}
	printf("%lld\n",ans);
	return 0;
}