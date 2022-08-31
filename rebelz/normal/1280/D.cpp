#include<bits/stdc++.h>

#define y1 dmytxdy
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

int n,m,tot;
ll a[3005],b[3005],v[6005],nxt[6005],h[3005],siz[3005];
pll d[3005][3005],tmp[3005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	d[u][0]=mp(0,a[u]);
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		for(int i=0;i<=min((ll)m,siz[u]+siz[v[p]]);i++) tmp[i]=mp(0,-(1ll<<60));
		for(int i=0;i<=min(siz[u],(ll)m);i++){
			for(int j=0;j<=min(siz[v[p]],(ll)m-i);j++){
				chkmax(tmp[i+j],mp(d[u][i].fi+d[v[p]][j].fi,d[u][i].se+d[v[p]][j].se));
				chkmax(tmp[i+j+1],mp(d[u][i].fi+d[v[p]][j].fi+(d[v[p]][j].se>0),d[u][i].se));
			}
		}
		siz[u]+=siz[v[p]];
		for(int i=0;i<=min(siz[u],(ll)m);i++) d[u][i]=tmp[i];
	}
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++) h[i]=0; tot=0;
		for(int i=1;i<=n;i++) b[i]=readint();
		for(int i=1;i<=n;i++) a[i]=readint()-b[i];
		for(int i=1;i<n;i++) addedge(readint(),readint());
		dfs(1,-1);
		printf("%lld\n",d[1][m-1].fi+(d[1][m-1].se>0));
	}
	return 0;
}