#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 105
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<ll,int> pli;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,k;ll ans=inf;
int a[MN][MN];
pli b[MN][MN][5];
int stk[MN],tp,vis[MN];
void chk(){
	stk[tp+1]=1;
	ll now=0;
	F(i,1,tp){
		int u=stk[i],v=stk[i+1];
		int j=1;
		while(vis[b[u][v][j].se])++j;
		now+=b[u][v][j].fi;
	}
	ans=min(ans,now);
}
void DFS(int st){
	if(st==1){
		chk();
		return;
	}
	F(i,1,n){
		stk[++tp]=i,++vis[i];
		DFS(st-1);
		--vis[i],--tp;
	}
}
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&k);
	F(i,1,n)F(j,1,n)scanf("%d",&a[i][j]);
	F(i,1,n)F(j,1,n){
		static pli d[MN];int c=0;
		F(k,1,n)if(i!=k&&j!=k)d[++c]=pli(a[i][k]+a[k][j],k);
		sort(d+1,d+c+1);
		F(k,1,min(4,c))b[i][j][k]=d[k];
		F(k,min(4,c)+1,4)b[i][j][k]=pli(inf,0);
	}
	stk[tp=1]=1,++vis[1],DFS(k/2);
	printf("%lld\n",ans);
}	return 0;
}