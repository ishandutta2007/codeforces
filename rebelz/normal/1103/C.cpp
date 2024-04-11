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

int n,m,k,tot,cnt;
int v[1000005],nxt[1000005],h[500005],dep[500005],f[500005];
bool vis[500005],nson[500005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u){
	if(dep[u]>=(n-1)/k+1){
		printf("PATH\n");
		printf("%d\n",dep[u]);
		for(int i=u;i;i=f[i]) printf("%d ",i);
		printf("\n");
		exit(0);
	}
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u]||vis[v[p]]) continue;
		vis[v[p]]=1;
		f[v[p]]=u,dep[v[p]]=dep[u]+1,nson[u]=1;
		dfs1(v[p]);
	}
}

void dfs2(int u){
	vector<int> tmp(0);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u]) continue;
		if(!nson[u]&&f[v[p]]!=u) tmp.pb(v[p]);
		if(f[v[p]]!=u) continue;
		dfs2(v[p]);
	}
	if(nson[u]) return;
	cnt++;
	if((dep[u]-dep[tmp[0]]+1)%3!=0){
		printf("%d\n",dep[u]-dep[tmp[0]]+1);
		for(int i=u;i!=f[tmp[0]];i=f[i]) printf("%d ",i);
		printf("\n");
	}
	else if((dep[u]-dep[tmp[1]]+1)%3!=0){
		printf("%d\n",dep[u]-dep[tmp[1]]+1);
		for(int i=u;i!=f[tmp[1]];i=f[i]) printf("%d ",i);
		printf("\n");
	}
	else{
		if(dep[tmp[0]]<dep[tmp[1]]) swap(tmp[0],tmp[1]);
		printf("%d\n",dep[tmp[0]]-dep[tmp[1]]+2);
		printf("%d ",u);
		for(int i=tmp[0];i!=f[tmp[1]];i=f[i]) printf("%d ",i);
		printf("\n");
	}
	if(cnt==k) exit(0);
}

int main(){
	n=readint(); m=readint(); k=readint();
	for(int i=1;i<=m;i++) addedge(readint(),readint());
	dep[1]=vis[1]=1; dfs1(1);
	printf("CYCLES\n");
	dfs2(1);
	return 0;
}