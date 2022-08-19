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

int n,tot,cnt,hv,leaf,num;
int v[400005],nxt[400005],h[200005];
bool lf[200005],bud[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	int son=0,fl=1,tmp=0;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		if(bud[v[p]]) continue;
		if(!lf[v[p]]) fl=0;
		if(lf[v[p]]) tmp=1;
		son++;
	}
	if(!son) lf[u]=1;
	if(fl==1&&son&&u!=1){
		bud[u]=1,cnt++;
		for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa&&!bud[v[p]]) leaf++;
	}
	else if(son&&tmp) hv=1;
}

void dfs2(int u,int fa){
	int son=0;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		if(bud[v[p]]) continue;
		dfs2(v[p],u);
		son++;
	}
	if(!son) num++;
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) h[i]=lf[i]=bud[i]=0; tot=0;
		hv=0,cnt=0,leaf=0,num=0;
		for(int i=1;i<n;i++) addedge(readint(),readint());
		dfs(1,-1);
		dfs2(1,-1);
		printf("%d\n",num+leaf-cnt);
	}
	return 0;
}