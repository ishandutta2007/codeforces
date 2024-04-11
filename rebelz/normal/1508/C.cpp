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

struct node{
	int x,y,z;
	bool operator<(const node c)const{return z<c.z;}
}e[500005],ee[1005];

int n,m,ecnt;
int c[1005][1005],f[200005],siz[200005],num[200005];
vector<int> adj[200005];
bool vis[500005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

ll solve(int x,int y,int z){
	ll ret=0;
	for(int i=1;i<=ecnt;i++){
		if(z<ee[i].z){
			int fx=getf(x),fy=getf(y);
			if(fx!=fy) f[fx]=fy,ret+=z;
			z=1<<30;
		}
		int fx=getf(ee[i].x),fy=getf(ee[i].y);
		if(fx!=fy) f[fx]=fy,ret+=ee[i].z;
	}
	if(z<(1<<30)){
		int fx=getf(x),fy=getf(y);
		if(fx!=fy) f[fx]=fy,ret+=z;
	}
	return ret;
}

int main(){
	n=readint(); m=readint();
	if(n<=1000){
		memset(c,-1,sizeof(c));
		int all=0,x,y,z;
		for(int i=1;i<=m;i++){
			x=readint(); y=readint(); z=readint();
			c[x][y]=c[y][x]=z,all^=z;
			if(x>y) swap(x,y);
			adj[y].pb(x);
			e[i].x=x,e[i].y=y,e[i].z=z;
		}
		for(int i=1;i<=n;i++) f[i]=i;
		bool fl=0;
		vector<pii> v(0);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(c[i][j]>=0) continue;
				int fx=getf(i),fy=getf(j);
				if(fx==fy){
					fl=1;
					break;
				}
				f[fx]=fy;
				v.pb(mp(i,j));
			}
			if(fl) break;
		}
		if(!fl){
			sort(e+1,e+m+1);
			for(int i=1;i<=n;i++) f[i]=i;
			for(int i=1;i<=m;i++){
				int fx=getf(e[i].x),fy=getf(e[i].y);
				if(fx==fy) continue;
				f[fx]=fy,ee[++ecnt]=e[i];
			}
			ll ans=1ll<<60;
			for(int i=0;i<v.size();i++){
				for(int j=1;j<=n;j++) f[j]=j;
				for(int j=0;j<v.size();j++) if(i!=j) c[v[j].fi][v[j].se]=c[v[j].se][v[j].fi]=0,f[getf(v[j].fi)]=getf(v[j].se);
				c[v[i].fi][v[i].se]=c[v[i].se][v[i].fi]=all;
				chkmin(ans,solve(v[i].fi,v[i].se,all));
			}
			printf("%lld\n",ans);
			return 0;
		}
	}
	else{
		int x,y,z,all=0;
		for(int i=1;i<=m;i++){
			x=readint(); y=readint(); z=readint();
			all^=z;
			if(x>y) swap(x,y);
			adj[y].pb(x);
			e[i].x=x,e[i].y=y,e[i].z=z;
		}
	}
	for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
	set<int> s;
	for(int i=1;i<=n;i++){
		for(auto v:adj[i]) num[getf(v)]++;
		vector<int> pt(0);
		for(auto r:s){
			if(num[r]!=siz[r]) pt.pb(r),f[r]=i,siz[i]+=siz[r];
			num[r]=0;
		}
		for(auto r:pt) s.erase(r);
		s.insert(i);
	}
	ll ans=0;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int fx=getf(e[i].x),fy=getf(e[i].y);
		if(fx==fy) continue;
		f[fx]=fy,ans+=e[i].z;
	}
	printf("%lld\n",ans);
	return 0;
}