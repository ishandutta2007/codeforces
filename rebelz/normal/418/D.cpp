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

int n,m,ncnt;
int dfn[100005],rnk[100005],siz[100005],top[100005],son[100005],f[100005][20],emx[100005],mxd[100005],dep[100005],pre[100005];
vector<int> adj[100005],st[100005],tmp;

struct node{
	int val[300000];
	void build(int id,int l,int r,int tp){
//		if(l==r) cout<<"build "<<tp<<' '<<emx[son[rnk[l]]]+tp*dep[rnk[l]]<<endl;
		if(l==r) return (void)(val[id]=emx[son[rnk[l]]]+tp*dep[rnk[l]]);
		int mid=(l+r)/2;
		build(id<<1,l,mid,tp);
		build(id<<1|1,mid+1,r,tp);
		val[id]=max(val[id<<1],val[id<<1|1]);
	}
	int query(int id,int l,int r,int ql,int qr){
		if(ql>qr) return -(1<<30);
		if(l==ql&&r==qr) return val[id];
		int mid=(l+r)/2;
		if(qr<=mid) return query(id<<1,l,mid,ql,qr);
		else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
		else return max(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
	}
	int qlist(int x,int y,int tp){
		int ret=-(1<<30);
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			chkmax(ret,query(1,1,n,dfn[top[x]],dfn[x]-1));
			chkmax(ret,emx[top[x]]+tp*dep[f[top[x]][0]]);
			x=f[top[x]][0];
		}
		if(dfn[x]>dfn[y]) swap(x,y);
		return max(ret,query(1,1,n,dfn[x],dfn[y]-1));
	}
}t[3];

void dfs1(int u,int fa){
	siz[u]=1;
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:adj[u]){
		if(v==fa) continue;
		dep[v]=dep[u]+1,f[v][0]=u;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
		chkmax(mxd[u],mxd[v]+1);
	}
}

void dfs2(int u,int fa){
	dfn[u]=++ncnt,rnk[ncnt]=u;
	if(son[u]){
		top[son[u]]=top[u];
		dfs2(son[u],u);
	}
	for(auto v:adj[u]){
		if(v==fa||v==son[u]) continue;
		top[v]=v;
		dfs2(v,u);
	}
}

void dfs3(int u,int fa){
	tmp.clear();
	for(auto v:adj[u]) if(v!=fa) tmp.push_back(v);
	swap(adj[u],tmp);
	for(int i=0;i<adj[u].size();i++){
		if(i==0) pre[i]=mxd[adj[u][i]]+1;
		else pre[i]=max(pre[i-1],mxd[adj[u][i]]+1);
	}
	int nowmax=0;
	for(int i=adj[u].size()-1;i>=0;i--){
		if(i==0) emx[adj[u][i]]=nowmax;
		else emx[adj[u][i]]=max(nowmax,pre[i-1]);
		chkmax(nowmax,mxd[adj[u][i]]+1);
	}
	for(auto v:adj[u]) dfs3(v,u),st[u].push_back(mxd[v]+1);
}

int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=f[top[x]][0];
	}
	return dep[x]<dep[y]?x:y;
}

int jump(int x,int y){
	for(int i=19;i>=0;i--) if(y&(1<<i)) x=f[x][i];
	return x;
}

int main(){
	n=readint();
	int x,y;
	for(int i=1;i<n;i++){
		x=readint(); y=readint();
		adj[x].push_back(y),adj[y].push_back(x);
	}
	dep[1]=1; dfs1(1,-1);
	top[1]=1; dfs2(1,-1);
	dfs3(1,-1);
//	for(int i=1;i<=n;i++) cout<<emx[i]<<' ';
//	cout<<endl;
	for(int i=1;i<=n;i++) sort(st[i].begin(),st[i].end());
	t[1].build(1,1,n,1);
	t[2].build(1,1,n,-1);
	m=readint();
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		int l=lca(x,y),k=(dep[x]+dep[y]-dep[l]-dep[l])/2,md1,md2;
		if(dep[x]-dep[l]>=k) md1=jump(x,k);
		else md1=jump(y,k),swap(x,y);
		if(md1==l) md2=jump(y,dep[y]-dep[l]-1);
		else md2=f[md1][0];
		int tx=jump(x,dep[x]-dep[l]-1),ty=jump(y,dep[y]-dep[l]-1);
//		cout<<"shit "<<x<<' '<<y<<' '<<md1<<' '<<md2<<endl;
		if(l==md1){
			int ans=t[2].qlist(1,l,-1)+dep[x];
			if(x!=l) chkmax(ans,t[2].qlist(tx,x,-1)+dep[x]);
			if(x!=l&&y!=l){
				int tmp=st[l].size()-1;
//				cout<<"test "<<mxd[tx]+1<<' '<<mxd[ty]+1<<' '<<st[l][tmp]<<' '<<st[l][tmp-1]<<' '<<st[l][tmp-2]<<endl;
				if(mxd[tx]+1==st[l][tmp]&&mxd[ty]+1==st[l][tmp-1]){
					if(tmp>=2) chkmax(ans,st[l][tmp-2]+min(dep[x],dep[y])-dep[l]);
				}
				else if(mxd[tx]+1==st[l][tmp-1]&&mxd[ty]+1==st[l][tmp]){
					if(tmp>=2) chkmax(ans,st[l][tmp-2]+min(dep[x],dep[y])-dep[l]);
				}
				else if(mxd[tx]+1==st[l][tmp]) chkmax(ans,st[l][tmp-1]+min(dep[x],dep[y])-dep[l]);
				else if(mxd[ty]+1==st[l][tmp]) chkmax(ans,st[l][tmp-1]+min(dep[x],dep[y])-dep[l]);
				else chkmax(ans,st[l][tmp]+min(dep[x],dep[y])-dep[l]);
			}
			chkmax(ans,dep[x]-dep[l]);
//			cout<<"test "<<ans<<endl;
			if(x!=l) chkmax(ans,mxd[x]);
			else chkmax(ans,emx[ty]);
//			cout<<"test2 "<<ans<<endl;
			chkmax(ans,t[2].qlist(md2,y,-1)+dep[y]);
			chkmax(ans,mxd[y]);
			printf("%d\n",ans);
		}
		else{
			int ans=t[2].qlist(1,l,-1)+dep[y];
			if(y!=l) chkmax(ans,t[2].qlist(ty,y,-1)+dep[y]);
			chkmax(ans,dep[y]-dep[l]);
			if(x!=l&&y!=l){
				int tmp=st[l].size()-1;
//				cout<<"test "<<mxd[tx]+1<<' '<<mxd[ty]+1<<' '<<st[l][tmp]<<' '<<st[l][tmp-1]<<' '<<st[l][tmp-2]<<endl;
				if(mxd[tx]+1==st[l][tmp]&&mxd[ty]+1==st[l][tmp-1]){
					if(tmp>=2) chkmax(ans,st[l][tmp-2]+min(dep[x],dep[y])-dep[l]);
				}
				else if(mxd[tx]+1==st[l][tmp-1]&&mxd[ty]+1==st[l][tmp]){
					if(tmp>=2) chkmax(ans,st[l][tmp-2]+min(dep[x],dep[y])-dep[l]);
				}
				else if(mxd[tx]+1==st[l][tmp]) chkmax(ans,st[l][tmp-1]+min(dep[x],dep[y])-dep[l]);
				else if(mxd[ty]+1==st[l][tmp]) chkmax(ans,st[l][tmp-1]+min(dep[x],dep[y])-dep[l]);
				else chkmax(ans,st[l][tmp]+min(dep[x],dep[y])-dep[l]);
			}
//			cout<<"test "<<ans<<endl;
			chkmax(ans,t[1].qlist(md1,tx,1)-dep[l]+dep[y]-dep[l]);
//			cout<<"test2 "<<ans<<endl;
			if(y!=l) chkmax(ans,mxd[y]);
			else chkmax(ans,emx[tx]);
//			cout<<"testsdf "<<ans<<endl;
			chkmax(ans,t[2].qlist(md1,x,-1)+dep[x]);
//			cout<<"test3 "<<ans<<endl;
			chkmax(ans,mxd[x]);
			printf("%d\n",ans);
		}
	}
	return 0;
}