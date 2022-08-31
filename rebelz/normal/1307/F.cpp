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

int n,k,r,qq,tot;
int v[800005],nxt[800005],h[400005],f[400005][20],dep[400005],col[400005],F[400005],q[400005][2];

int getf(int x){return x==F[x]?x:F[x]=getf(F[x]);}

void merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy) return;
	F[fx]=fy;
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=dep[u]+1,f[v[p]][0]=u;
		dfs(v[p],u);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int find(int x,int y){
	for(int i=19;i>=0;i--) if(y&(1<<i)) x=f[x][i];
	return x;
}

int main(){
	n=readint(); k=readint(); r=readint();
	int x,y;
	for(int i=1;i<n;i++){
		x=readint(); y=readint();
		addedge(x,n+i),addedge(y,n+i);
	}
	int front=0,rear=0;
	for(int i=1;i<=r;i++){
		x=readint();
		q[rear][0]=x,q[rear++][1]=0,col[x]=i;
	}
	for(int i=1;i<=r;i++) F[i]=i;
	while(front<rear){
		int t=q[front][0],step=q[front++][1];
		if(step==k) continue;
		for(int p=h[t];p;p=nxt[p]){
			if(col[v[p]]) merge(col[t],col[v[p]]);
			else{
				col[v[p]]=col[t];
				q[rear][0]=v[p],q[rear++][1]=step+1;
			}
		}
	}
	dep[1]=1; dfs(1,-1);
	qq=readint();
	while(qq--){
		x=readint(); y=readint();
		if(col[x]&&getf(col[x])==getf(col[y])){
			printf("YES\n");
			continue;
		}
		int l=lca(x,y),tx,ty;
		if(dep[x]+dep[y]-dep[l]-dep[l]<=k+k){
			printf("YES\n");
			continue;
		}
		if(dep[x]-dep[l]>=k) tx=find(x,k);
		else tx=find(y,dep[y]-dep[l]-k+dep[x]-dep[l]);
		if(dep[y]-dep[l]>=k) ty=find(y,k);
		else ty=find(x,dep[x]-dep[l]-k+dep[y]-dep[l]);
		if(col[tx]&&getf(col[tx])==getf(col[ty])) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}