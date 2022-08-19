// xtqqwq
#include<bits/stdc++.h>

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

int n,m,k,tot,leaf;
int v[400005],nxt[400005],h[200005],son[200005],a[200005],mxd[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	int num=0;
	mxd[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs1(v[p],u);
		num++;
		if(chkmax(mxd[u],mxd[v[p]]+1)) son[u]=v[p];
	}
	if(!num) leaf++;
}

void dfs2(int u,int fa){
	if(son[u]) dfs2(son[u],u);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||v[p]==son[u]) continue;
		a[++m]=mxd[v[p]];
		dfs2(v[p],u);
	}
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dfs1(1,-1);
	if(k>=leaf){
		ll ans=0;
		for(int i=leaf;i<=k;i++) chkmax(ans,1ll*i*(n-i));
		printf("%lld\n",ans);
		return 0;
	}
	a[++m]=mxd[1];
	dfs2(1,-1);
	sort(a+1,a+m+1);
	reverse(a+1,a+m+1);
	int rem=n;
	for(int i=1;i<=k;i++) rem-=a[i];
	ll ans=1ll<<60;
	for(int i=0;i<=rem;i++) chkmin(ans,1ll*(n-k-i)*(k-i));
	printf("%lld\n",ans);
	return 0;
}