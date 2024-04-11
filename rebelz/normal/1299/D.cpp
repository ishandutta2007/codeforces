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

int pw[5]={14,12,9,5,0};
 
struct node{
	int a[5],hs;
	bool operator<(const node c)const{return hs<c.hs;}
	bool add(int x){
		for(int i=4;i>=0;i--){
			if(x&(1<<i)){
				if(a[i]) x^=a[i];
				else{
					a[i]=x;
					hs+=x*(1<<pw[i]);
					return true;
				}
			}
		}
		return false;
	}
}xj[100005];
 
const int cys=1000000007;
int n,m,tot,stacnt;
int x[100005],y[100005],z[100005],v[200005],nxt[200005],c[200005],h[100005],dep[100005],f[100005],k[100005],fr[100005],id[70000];
bool vis[100005],cat[100005];
int d[70000],g[70000],tun[505][505];
ll ta[505];
map<int,int> tid;
 
int mod(int x){return x>=cys?x-cys:x;}
 
void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}
 
void dfs(int u,int t){
	fr[u]=t;
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]) continue;
		vis[v[p]]=1,f[v[p]]=u,dep[v[p]]=dep[u]^c[p];
		dfs(v[p],t<0?v[p]:t);
	}
}

void init(){
	int now[5];
	for(int i=0;i<(1<<15);i++){
		for(int j=0;j<=4;j++) now[j]=(i>>pw[j])&((1<<(j+1))-1);
		bool fl=1;
		for(int j=0;j<=4;j++) if(now[j]&&!(now[j]&(1<<j))) fl=0;
		if(!fl) continue;
		ll sta=0;
		for(int j=0;j<=4;j++){
			if(now[j]){
				for(int k=0;k<32;k++) if((sta>>k)&1) sta|=1ll<<(now[j]^k);
				sta|=1ll<<now[j];
			}
		}
		if(tid.count(sta)) id[i]=tid[sta];
		else id[i]=tid[sta]=++stacnt,ta[stacnt]=sta;
	}
	for(int i=1;i<=stacnt;i++){
		for(int j=1;j<=stacnt;j++){
			if(ta[i]&ta[j]){
				tun[i][j]=-1;
				continue;
			}
			ll sta=ta[i]|ta[j];
			for(int k=0;k<32;k++)
				if((ta[i]>>k)&1)
					for(int l=0;l<32;l++)
						if((ta[j]>>l)&1)
							sta|=1ll<<(k^l);
			tun[i][j]=tid[sta];
		}
	}
}

int main(){
	init();
	n=readint(); m=readint();
	for(int i=1;i<=m;i++){
		x[i]=readint(); y[i]=readint(); z[i]=readint();
		addedge(x[i],y[i],z[i]);
	}
	vis[1]=1;
	dfs(1,-1);
	memset(k,-1,sizeof(k));
	for(int i=1;i<=m;i++){
		if(f[x[i]]==y[i]||f[y[i]]==x[i]) continue;
		if(y[i]==1) swap(x[i],y[i]);
		if(x[i]==1) k[fr[y[i]]]=z[i]^dep[y[i]];
		else if(!xj[fr[y[i]]].add(z[i]^dep[y[i]]^dep[x[i]])) cat[fr[y[i]]]=1;
	}
	vector<int> son(0);
	for(int p=h[1];p;p=nxt[p]) if(f[v[p]]==1) son.push_back(v[p]);
	d[tid[0]]=g[tid[0]]=1;
	for(int i=0;i<son.size();i++){
		int u=son[i];
		if(cat[u]) continue;
		if(k[u]>=0){
			for(int j=1;j<=stacnt;j++){
				if(!d[j]) continue;
				ll tmp=tun[j][id[xj[u].hs]];
				if(tmp>=0) g[tmp]=mod(g[tmp]+mod(d[j]*2));
				if(tmp>=0) tmp=tun[tmp][tid[1ll<<k[u]]];
				if(tmp>=0) g[tmp]=mod(g[tmp]+d[j]);
			}
		}
		else{
			for(int j=1;j<=stacnt;j++){
				ll tmp=tun[j][id[xj[u].hs]];
				if(tmp>=0) g[tmp]=mod(g[tmp]+d[j]);
			}
		}
		for(int j=1;j<=stacnt;j++) d[j]=g[j];
	}
	ll ans=0;
	for(int i=1;i<=stacnt;i++) ans=mod(ans+d[i]);
	printf("%lld\n",ans);
	return 0;
}