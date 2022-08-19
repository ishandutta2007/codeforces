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

int lt,rt,n,m,cnt,tot,l0,r0,l1,r1;
int l[100005],r[100005],v[200005],nxt[200005],h[100005],col[100005],ans[100005],bl[100005];
pair<pii,pii> a[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

bool dfs(int u,int c){
	col[u]=c;
	if(!c) chkmax(l0,l[u]),chkmin(r0,r[u]);
	else chkmax(l1,l[u]),chkmin(r1,r[u]);
	for(int p=h[u];p;p=nxt[p]){
		if(col[v[p]]<0&&!dfs(v[p],c^1)) return false;
		else if(col[v[p]]>=0&&col[v[p]]!=(c^1)) return false;
	}
	return true;
}

void getans(int u,int c){
	ans[u]=c;
	for(int p=h[u];p;p=nxt[p]) if(ans[v[p]]<0) getans(v[p],c^1);
}

int main(){
	lt=readint(); rt=readint(); n=readint(); m=readint();
	for(int i=1;i<=n;i++) l[i]=readint(),r[i]=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		addedge(x,y);
	}
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n;i++){
		if(col[i]<0){
			l0=0,r0=1e9,l1=0,r1=1e9;
			if(!dfs(i,0)) return printf("IMPOSSIBLE\n"),0;
			if(l0>0||r0<1e9) a[++cnt]=mp(mp(l0,r0),mp(i,0));
			if(l1>0||r1<1e9) a[++cnt]=mp(mp(l1,r1),mp(i,1));
		}
	}
	int lf=1e9,rg=0;
	for(int i=1;i<=cnt;i++) chkmin(lf,a[i].fi.se),chkmax(rg,a[i].fi.fi);
	if(lf+rg<lt) rg=lt-lf;
	else if(lf+rg>rt) lf=rt-rg;
	if(lf<0||rg<0) return printf("IMPOSSIBLE\n"),0;
	for(int i=1;i<=cnt;i++) if(a[i].fi.fi>lf&&a[i].fi.se<rg) return printf("IMPOSSIBLE\n"),0;
	memset(bl,-1,sizeof(bl));
	for(int i=1;i<=cnt;i++){
		if(bl[a[i].se.fi]>=0){
			if((bl[a[i].se.fi]^a[i].se.se)==1&&a[i].fi.se<rg) return printf("IMPOSSIBLE\n"),0;
			else if((bl[a[i].se.fi]^a[i].se.se)==0&&a[i].fi.fi>lf) return printf("IMPOSSIBLE\n"),0;
			continue;
		}
		if(a[i].fi.se<rg) bl[a[i].se.fi]=a[i].se.se;
		if(a[i].fi.fi>lf) bl[a[i].se.fi]=a[i].se.se^1;
	}
	for(int i=1;i<=cnt;i++) if(bl[a[i].se.fi]<0) bl[a[i].se.fi]=0;
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=n;i++) if(bl[i]>=0) getans(i,bl[i]);
	printf("POSSIBLE\n%d %d\n",lf,rg);
	for(int i=1;i<=n;i++) printf("%d",ans[i]+1);
	printf("\n");
	return 0;
}