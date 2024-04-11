// LUOGU_RID: 92451723
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=3e5+5;
int n,fa[maxn];
vector<int> g[maxn];
int sz[maxn],son[maxn];
void dfs1(int u){
	sz[u]=1;
	for(int v:g[u]){
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
int pos[maxn],cnt=0,top[maxn],bot[maxn];
void dfs2(int u){
	pos[u]=cnt++;
	top[u]=son[fa[u]]==u?top[fa[u]]:u;
	if(son[u]){
		dfs2(son[u]);
		bot[u]=bot[son[u]];
	}
	else bot[u]=u;
	for(int v:g[u]) if(v!=son[u]) dfs2(v);
}
struct dt{
	int x,y1,y2,s1,s2;
	dt operator +(dt b){
		dt c;
		c.x=b.x;
		c.y1=b.y1==x?y1:y2;
		c.y2=b.y2==x?y1:y2;
		c.s1=b.s1+(b.y1==x?s1:s2);
		c.s2=b.s2+(b.y2==x?s1:s2);
		return c;
	}
};
struct node{
	int l,r;
	node* ch[2];
	dt val={0,-1,-1,0,0};
	void pushup(){
		val=ch[0]->val+ch[1]->val;
	}
	node(int l,int r):l(l),r(r){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void modify(int x,int k1,int k2){
		if(l==r){
			val={k1,k2,k1,k2,k1};
			return;
		}
		ch[x>=ch[1]->l]->modify(x,k1,k2);
		pushup();
	}
	dt query(int ql,int qr){
		if(ql<=l&&qr>=r) return val;
		if(qr<=ch[0]->r) return ch[0]->query(ql,qr);
		else if(ql>=ch[1]->l) return ch[1]->query(ql,qr);
		else return ch[0]->query(ql,qr)+ch[1]->query(ql,qr);
	}
}*rt;
int c[maxn][20];
void upd(int u){
	int x=0;
	while(c[u][x]) x++;
	int y=x+1;
	while(c[u][y]) y++;
	rt->modify(pos[u],x,y);
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read()+1;
	for(int i=2;i<=n;i++) g[fa[i]=read()].push_back(i);
	dfs1(1);
	dfs2(1);
	rt=new node(0,n-1);
	upd(1);
	int ans=0;
	for(int i=2;i<=n;i++){
		int u=top[fa[i]];
		while(u!=1){
			dt res=rt->query(pos[u],pos[bot[u]]);
			c[fa[u]][res.y2]--;
			ans-=res.s2;
			u=top[fa[u]];
		}
		upd(i);
		u=top[i];
		while(u!=1){
			dt res=rt->query(pos[u],pos[bot[u]]);
			c[fa[u]][res.y2]++;
			ans+=res.s2;
			upd(fa[u]);
			u=top[fa[u]];
		}
		printf("%d\n",ans+rt->query(0,pos[bot[1]]).s2);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}