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

int n,k,tot;
int d[205][30005],path[205][30005],pt[205],f[30005],v[60005],nxt[60005],h[30005],chk[30005];
bool vis[30005];
map<int,int> s[30005];
vector<pii> vec[30005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		chk[v[p]]=chk[u]+1;
		dfs(v[p],u);
	}
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) d[i][j]=readint();
		for(int j=1;j<=n;j++) if(d[i][j]==0) pt[i]=j;
		if(!pt[i]) return printf("-1\n"),0;
	}
	for(int i=1;i<=n;i++) f[i]=i;
	vis[pt[1]]=1;
	for(int i=2;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(pt[1]==j||pt[i]==j) continue;
			if(d[1][j]+d[i][j]==d[1][pt[i]]) path[i][d[1][j]]=j;
		}
		for(int j=1;j<d[1][pt[i]];j++) if(!path[i][j]) return printf("-1\n"),0;
		path[i][0]=pt[1],path[i][d[1][pt[i]]]=pt[i];
		for(int j=0;j<d[1][pt[i]];j++){
			if(s[path[i][j]].count(path[i][j+1])) continue;
			s[path[i][j]][path[i][j+1]]=1;
			int fx=getf(path[i][j]),fy=getf(path[i][j+1]);
			if(fx==fy) return printf("-1\n"),0;
			f[fx]=fy;
			addedge(path[i][j],path[i][j+1]);
		}
		for(int j=1;j<=d[1][pt[i]];j++) vis[path[i][j]]=1;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int maxa=0; pii opt;
		for(int j=2;j<=k;j++){
			int dis=(d[1][i]+d[j][i]-d[1][pt[j]])/2;
			if(dis==d[1][i]) continue;
			if(dis<0||dis>d[1][i]) return printf("-1\n"),0;
			vis[i]=1;
			if(chkmax(maxa,d[1][i]-dis)) opt=mp(j,dis);
		}
		if(maxa) vec[path[opt.fi][maxa]].pb(mp(opt.se,i));
	}
	for(int i=1;i<=n;i++) if(!vis[i]) vec[pt[1]].pb(mp(d[1][i],i));
	for(int i=1;i<=n;i++){
		sort(vec[i].begin(),vec[i].end());
		pii lst0=mp(0,i),lst1=mp(0,0);
		for(auto r:vec[i]){
			if(r.fi>lst0.fi+1) return printf("-1\n"),0;
			if(r.fi==lst0.fi+1) addedge(lst0.se,r.se);
			else if(r.fi==lst1.fi+1) addedge(lst1.se,r.se);
			if(r.fi==lst0.fi+1) lst1=lst0,lst0=r;
		}
	}
	for(int i=1;i<=k;i++){
		memset(chk,0,sizeof(chk));
		dfs(pt[i],-1);
		for(int j=1;j<=n;j++) if(chk[j]!=d[i][j]) return printf("-1\n"),0;
	}
	for(int i=1;i<=n;i++) for(int p=h[i];p;p=nxt[p]) if(i<v[p]) printf("%d %d\n",i,v[p]);
	return 0;
}