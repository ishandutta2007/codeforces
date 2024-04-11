#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int Maxn=150000;
struct Tree{
	#define lc x<<1
	#define rc x<<1|1
	#define mid ((l+r)>>1)
	struct Node{
		ll a,b;
	}tree[Maxn<<2|5];
	void ins(int x,int l,int r,ll a,ll b){
		if(tree[x].a*l+tree[x].b<=a*l+b&&tree[x].a*r+tree[x].b<=a*r+b){
			tree[x].a=a;
			tree[x].b=b;
			return;
		}
		if(tree[x].a*l+tree[x].b>=a*l+b&&tree[x].a*r+tree[x].b>=a*r+b){
			return;
		}
		if(tree[x].a*mid+tree[x].b<a*mid+b){
			swap(tree[x].a,a);
			swap(tree[x].b,b);
		}
		if(a<tree[x].a){
			ins(lc,l,mid,a,b);
		}
		else{
			ins(rc,mid+1,r,a,b);
		}
	}
	void build(int x,int l,int r){
		tree[x].a=tree[x].b=0;
		if(l==r){
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	ll query(int x,int l,int r,int p){
		ll ans=tree[x].a*p+tree[x].b;
		if(l==r){
			return ans;
		}
		if(p<=mid){
			ans=max(ans,query(lc,l,mid,p));
		}
		else{
			ans=max(ans,query(rc,mid+1,r,p));
		}
		return ans;
	}
	#undef lc
	#undef rc
	#undef mid
}T;
struct Edge{
	int to;
	int nxt;
}e[Maxn<<1|5];
int n,m,edgenum,head[Maxn+5],dep[Maxn+5],maxd;
int pa[Maxn+5],size[Maxn+5],root,maxs[Maxn+5];
int st[Maxn+5],top;
ll a[Maxn+5],v1[Maxn+5],v2[Maxn+5],l[Maxn+5],s[Maxn+5],x[Maxn+5],maxv[Maxn+5],ans;
bool flag[Maxn+5];
void add(int u,int v){
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void getroot(int node,int tot){
	size[node]=1;
	maxs[node]=0;
	for(int hd=head[node];hd;hd=e[hd].nxt){
		int to=e[hd].to;
		if(to==pa[node]||flag[to]){
			continue;
		}
		pa[to]=node;
		getroot(to,tot);
		size[node]+=size[to];
		maxs[node]=max(maxs[node],size[to]);
	}
	maxs[node]=max(maxs[node],tot-size[node]);
	if(maxs[root]>maxs[node]){
		root=node;
	}
	pa[node]=0;
}
void dfs(int node,ll val1,ll val2,ll sum,int from){
	if(node!=root&&!from){
		from=node;
	}
	dep[node]=dep[pa[node]]+1;
	maxd=max(maxd,dep[node]);
	bool f=0;
	size[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt){
		int to=e[hd].to;
		if(to==pa[node]||flag[to]){
			continue;
		}
		pa[to]=node;
		f=1;
		dfs(to,val1+sum+a[to],val2+a[to]*dep[node],sum+a[to],from);
		size[node]+=size[to];
	}
	if(!f){
		st[++top]=node;
		v1[top]=val1;
		v2[top]=val2;
		s[top]=sum-a[root];
		l[top]=dep[node];
		x[top]=from;
	}
}
void solve(){
	flag[root]=1;
	maxd=0;
	top=0;
	pa[root]=0;
	dfs(root,a[root],0,a[root],0);
	st[++top]=root;
	v1[top]=a[root];
	l[top]=1;
	v2[top]=s[top]=x[top]=0;
	T.build(1,1,maxd);
	x[top+1]=x[0]=-1;
	for(int i=1;i<=top;){
		int j=i;
		while(x[j]==x[i]){
			ans=max(ans,T.query(1,1,maxd,(int)l[j])+v1[j]);
			j++;
		}
		j=i;
		while(x[j]==x[i]){
			T.ins(1,1,maxd,s[j],v2[j]);
			j++;
		}
		i=j;
	}
	T.build(1,1,maxd);
	for(int i=top;i>0;){
		int j=i;
		while(x[j]==x[i]){
			ans=max(ans,T.query(1,1,maxd,(int)l[j])+v1[j]);
			j--;
		}
		j=i;
		while(x[j]==x[i]){
			T.ins(1,1,maxd,s[j],v2[j]);
			j--;
		}
		i=j;
	}
	int x=root;
	for(int hd=head[x];hd;hd=e[hd].nxt){
		int to=e[hd].to;
		if(flag[to]||size[to]==1){
			continue;
		}
		int t=size[to];
		root=0;
		getroot(to,t);
		solve();
	}
}
int main(){
	maxs[0]=2147483647;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	getroot(1,n);
	solve();
	printf("%lld\n",ans);
	return 0;
}