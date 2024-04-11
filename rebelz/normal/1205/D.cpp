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

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot,nans,rt;
int v[2005],nxt[2005],h[1005],siz[1005],mx[1005],f[1005];
vector<pii> sz;
vector<pair<pii,int> > ans;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	siz[u]=1,mx[u]=0;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs1(v[p],u);
		mx[u]=max(mx[u],siz[v[p]]);
		siz[u]+=siz[v[p]];
	}
	mx[u]=max(mx[u],n-siz[u]);
	if(chkmin(nans,mx[u])) rt=u;
}

void getf(int u){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=f[u]) f[v[p]]=u,getf(v[p]),siz[u]+=siz[v[p]];
}

void dfs2(int u,int l,int r,int x){
	ans.push_back(mp(mp(f[u],u),l*x));
	r-=l,l=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u]) continue;
		dfs2(v[p],l,l+siz[v[p]]-1,x);
		l+=siz[v[p]];
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	nans=1<<30; dfs1(1,-1);
	getf(rt);
	for(int p=h[rt];p;p=nxt[p]) sz.push_back(mp(siz[v[p]],v[p]));
	sort(sz.begin(),sz.end());
	int now=0,lst=0;
	for(auto x:sz){
		if(now<n/3){
			now+=x.fi;
			dfs2(x.se,lst+1,lst+x.fi,1);
			lst+=x.fi;
			if(now>=n/3) lst=0;
		}
		else{
			assert((n-now-1)*(now+1)>=2*n*n/9);
			dfs2(x.se,lst+1,lst+x.fi,now+1);
			lst+=x.fi;
		}
	}
	for(auto x:ans) printf("%d %d %d\n",x.fi.fi,x.fi.se,x.se);
	return 0;
}