#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m,gg[MN],d[MN],q[MN],l,r;
vector<int>G[MN],iG[MN];
int v1[MN],v2[MN];
void dfs1(int u){
	gg[u]=v1[u]=1;
	for(int v:G[u])if(!v1[v])dfs1(v);
}
void dfs2(int u){
	gg[u]=v2[u]=1;
	for(int v:iG[u])if(!v2[v])dfs2(v);
}
char s[MN];int c;
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].pb(y);
		iG[y].pb(x);
		gg[max(x,y)]=1;
		++d[y];
	}
	l=1,r=0;
	F(i,1,n)if(!d[i])q[++r]=i;
	while(l<=r){
		int u=q[l++];
		for(int v:G[u])if(!--d[v])q[++r]=v;
	}
	if(r!=n)return puts("-1"),0;
	F(i,1,n){
		if(!gg[i])s[i]='A',++c;
		else s[i]='E';
		dfs1(i),dfs2(i);
	}
	printf("%d\n%s\n",c,s+1);
	return 0;
}