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

int n,tot;
ll ans1=0,ans2=0;
ll v[500005],nxt[500005],c[500005],h[200005],siz[200005];

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		if(siz[v[p]]&1) ans1+=c[p];
		ans2+=c[p]*min(siz[v[p]],n+n-siz[v[p]]);
		siz[u]+=siz[v[p]];
	}
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n+n;i++) h[i]=0; tot=0;
		int x,y,z;
		for(int i=1;i<n+n;i++){
			x=readint(); y=readint(); z=readint();
			addedge(x,y,z);
		}
		ans1=ans2=0;
		dfs(1,-1);
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}