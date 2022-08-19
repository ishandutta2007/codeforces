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

const int cys=998244353;
int n,m,N,tot;
int x[200005],y[200005],v[8000005],nxt[8000005],h[4000005];
bool vis[4000005];
pii dis[4000005],c[8000005];
priority_queue<pair<pii,int> > q;

void addedge(int x,int y,int z,int w=0){v[++tot]=y; c[tot]=mp(z,w); nxt[tot]=h[x]; h[x]=tot;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

pii operator+(const pii x,const pii y){return mp(x.fi+y.fi,x.se+y.se);}

void dij(int s){
	for(int i=1;i<=N;i++) dis[i]=mp(1<<30,0),vis[i]=0;
	dis[s]=mp(0,0),q.push(mp(mp(0,0),s));
	while(!q.empty()){
		int t=q.top().se; q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int p=h[t];p;p=nxt[p])
			if(chkmin(dis[v[p]],dis[t]+c[p]))
				q.push(mp(mp(-dis[v[p]].fi,-dis[v[p]].se),v[p]));
	}
}

int work1(){
	N=n+n;
	for(int i=1;i<=m;i++) addedge(x[i],y[i],0),addedge(y[i]+n,x[i]+n,0);
	for(int i=1;i<=n;i++) addedge(i,i+n,1),addedge(i+n,i,1);
	dij(1);
	return min(dis[n],dis[n+n]).fi;
}

void work2(){
	N=n+n;
	for(int i=1;i<=N;i++) h[i]=0; tot=0;
	for(int i=1;i<=m;i++) addedge(x[i],y[i],0,1),addedge(y[i]+n,x[i]+n,0,1);
	for(int i=1;i<=n;i++) addedge(i,i+n,1,0),addedge(i+n,i,1,0);
	dij(1);
	pii tmp=min(dis[n],dis[n+n]);
	printf("%lld\n",(qpow(2,tmp.fi)+cys-1+tmp.se)%cys);
}

void work3(){
	N=19*n;
	for(int i=1;i<=N;i++) h[i]=0; tot=0;
	for(int i=1;i<=19;i++){
		for(int j=1;j<=m;j++){
			if(i&1) addedge(x[j]+(i-1)*n,y[j]+(i-1)*n,1);
			else addedge(y[j]+(i-1)*n,x[j]+(i-1)*n,1);
		}
		if(i<19){
			for(int j=1;j<=n;j++) addedge(j+(i-1)*n,j+i*n,1<<(i-1));
		}
	}
	dij(1);
	pii ans=mp(1<<30,0);
	for(int i=1;i<=19;i++) chkmin(ans,dis[i*n]);
	printf("%d\n",ans.fi);
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) x[i]=readint(),y[i]=readint();
	int tmp=work1();
	if(tmp>=20) work2();
	else work3();
	return 0;
}