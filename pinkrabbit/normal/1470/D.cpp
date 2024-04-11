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
int n,m,vis[MN],stk[MN];
vector<int>G[MN],ans;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	ans.clear();
	F(i,1,n){
		G[i].clear();
		vis[i]=0;
	}
	F(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].pb(y);
		G[y].pb(x);
	}
	int tp=0,cnt=0;
	stk[++tp]=1;
	while(tp){
		int u=stk[tp--];
		if(vis[u])continue;
		++cnt,vis[u]=1;
		ans.pb(u);
		for(int v:G[u])if(!vis[v]){
			++cnt,vis[v]=1;
			for(int x:G[v])if(!vis[x])
				stk[++tp]=x;
		}
	}
	if(cnt!=n)puts("NO");
	else{
		puts("YES");
		printf("%d\n",(int)ans.size());
		for(int x:ans)printf("%d ",x);
		puts("");
	}
}	return 0;
}