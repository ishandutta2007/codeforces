#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=3e5+5;
int n,m,c[maxn];
vector<int> g[maxn],q1[maxn],q2[maxn];
int p[maxn],ch[maxn][2],val[maxn],add[maxn];
void pushtag(int x,int k){
	val[x]+=k;
	add[x]+=k;
}
void pushdown(int x){
	if(ch[x][0]) pushtag(ch[x][0],add[x]);
	if(ch[x][1]) pushtag(ch[x][1],add[x]);
	add[x]=0;
}
int merge(int a,int b){
	if(!a) return b;
	if(!b) return a;
	if(val[a]>val[b]) swap(a,b);
	pushdown(a);
	ch[a][0]=merge(ch[a][0],b);
	if(ch[a][0]) p[ch[a][0]]=a;
	swap(ch[a][0],ch[a][1]);
	return a;
}
int rt[maxn];
ll ans=0;
void dfs(int u,int fa){
	for(int v:g[u]) if(v!=fa){
		dfs(v,u);
		rt[u]=merge(rt[u],rt[v]);
	}
	for(int x:q1[u]){
		val[x]=c[x];
		rt[u]=merge(rt[u],x);
	}
	for(int x:q2[u]){
		pushdown(x);
		int y=merge(ch[x][0],ch[x][1]);
		if(y) p[y]=p[x];
		if(p[x]) ch[p[x]][ch[p[x]][1]==x]=y;
		else rt[u]=y;
	}
	if(u==1) return;
	if(!rt[u]){
		printf("-1\n");
		exit(0);
	}
	ans+=val[rt[u]];
	pushtag(rt[u],-val[rt[u]]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=1;i<n;i++){
		int x,y;
		x=readint();
		y=readint();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=m;i++){
		q1[readint()].push_back(i);
		q2[readint()].push_back(i);
		c[i]=readint();
	}
	dfs(1,0);
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}