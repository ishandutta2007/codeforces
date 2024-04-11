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

int n,tot; ll ans=0;
ll a[300005],v[600005],nxt[600005],h[300005],c[600005],max1[300005],max2[300005];

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		ll tmp=max1[v[p]]+a[v[p]]-c[p];
		if(tmp>max1[u]) max2[u]=max1[u],max1[u]=tmp;
		else chkmax(max2[u],tmp);
	}
	chkmax(ans,max1[u]+max2[u]+a[u]);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int x,y,z;
	for(int i=1;i<n;i++){
		x=readint(); y=readint(); z=readint();
		addedge(x,y,z);
	}
	dfs(1,-1);
	printf("%lld\n",ans);
	return 0;
}