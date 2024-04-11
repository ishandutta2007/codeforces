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
#define mp make_pair
#define fi first
#define se second
int n,m,k,d[MN],b[MN],g[MN];
set<int>s,t[MN];
void dfs(int u){
	s.erase(u);
	++b[k],g[u]=k;
	auto it=s.begin();
	while(it!=s.end()){
		while(it!=s.end()&&t[u].count(*it))++it;
		if(it!=s.end()){int v=*it;dfs(v);it=s.lower_bound(v);}
	}
}
int main(){
	int x,y;
	scanf("%d%d",&n,&m);
	F(i,1,m)scanf("%d%d",&x,&y),t[x].insert(y),t[y].insert(x),++d[x],++d[y];
	F(i,1,n)s.insert(i);
	F(i,1,n)if(s.count(i))++k,dfs(i);
	if(k!=3)return puts("-1"),0;
	F(i,1,n)if(d[i]!=b[1]+b[2]+b[3]-b[g[i]])return puts("-1"),0;
	F(i,1,n)printf("%d ",g[i]);
	return 0;
}