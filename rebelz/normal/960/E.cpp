#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,tot,ans;
int siz[200005][2],col[200005],a[200005],v[400005],nxt[400005],h[200005];

int mod(int x){return x>=cys?x-cys:x;}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	siz[u][col[u]]++;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		col[v[p]]=col[u]^1;
		dfs(v[p],u);
		ans=mod(ans+1ll*a[u]*mod(1ll*siz[v[p]][col[u]]*siz[u][col[u]]%cys+cys-1ll*siz[v[p]][col[u]^1]*siz[u][col[u]^1]%cys)%cys);
		siz[u][0]+=siz[v[p]][0],siz[u][1]+=siz[v[p]][1];
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=mod(cys+readint());
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	col[1]=1;
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		ans=mod(ans+1ll*(siz[1][col[i]]-siz[i][col[i]])*siz[i][col[i]]%cys*a[i]%cys);
		ans=mod(ans+cys-1ll*(siz[1][col[i]^1]-siz[i][col[i]^1])*siz[i][col[i]^1]%cys*a[i]%cys);
	}
	ans=mod(ans<<1);
	for(int i=1;i<=n;i++) ans=mod(ans+a[i]);
	cout<<ans<<endl;
	return 0;
}