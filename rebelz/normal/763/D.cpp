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

int n,tot,ans,now,cho;
int v[200005],nxt[200005],h[100005],siz[100005];
ull d[100005];
map<ull,int> cnt[100005];

void add(int t,ull x){if(!(cnt[t][x]++)) now++;}
void del(int t,ull x){if(!(--cnt[t][x])) now--;}
ull f(ull x){return 19260817*x*x*x+x+7;}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs1(v[p],u);
		d[u]+=f(d[v[p]]),siz[u]+=siz[v[p]];
	}
}

void dfs2(int u,int fa){
	if(chkmax(ans,now)) cho=u;
	del(siz[u],d[u]);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		del(siz[v[p]],d[v[p]]);
		siz[u]-=siz[v[p]],siz[v[p]]+=siz[u];
		d[u]-=f(d[v[p]]),d[v[p]]+=f(d[u]);
		add(siz[u],d[u]),add(siz[v[p]],d[v[p]]);
		dfs2(v[p],u);
		del(siz[v[p]],d[v[p]]),del(siz[u],d[u]);
		d[v[p]]-=f(d[u]),d[u]+=f(d[v[p]]);
		siz[v[p]]-=siz[u],siz[u]+=siz[v[p]];
		add(siz[v[p]],d[v[p]]);
	}
	add(siz[u],d[u]);
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dfs1(1,-1);
	for(int i=1;i<=n;i++) add(siz[i],d[i]);
	dfs2(1,-1);
	printf("%d\n",cho);
	return 0;
}