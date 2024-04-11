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
int n,m,k;
int a[MN];
vector<int>G[MN];
int d1[MN],d2[MN];
void BFS(int s,int*d){
	static int q[MN];
	int l,r;
	F(i,1,n)d[i]=inf;
	q[l=r=1]=s,d[s]=0;
	while(l<=r){
		int u=q[l++];
		for(auto v:G[u])if(d[v]>d[u]+1)d[v]=d[u]+1,q[++r]=v;
	}
}
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,k)scanf("%d",a+i);
	F(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].pb(y),G[y].pb(x);
	}
	BFS(1,d1);
	BFS(n,d2);
	sort(a+1,a+k+1,[](int i,int j){return d1[i]>d1[j];});
	int ans=0,val=d2[a[1]];
	F(i,2,k){
		int u=a[i];
//		printf("u=%d\n",u);
		ans=max(ans,min(d1[n],d1[u]+1+val));
//		printf("ans=%d\n",min(d1[n],d1[u]+1+val));
		val=max(val,d2[u]);
	}
	printf("%d\n",ans);
}	return 0;
}