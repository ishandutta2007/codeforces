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
vector<pii>G[MN],V[MN];
inline int tr(pii p){
	return p.fi*(p.fi-1)/2+p.se;
}
int gg[99][99];
int seq[99],ans;
void DFS(int i){
	if(i>k){
		++ans;
//		F(j,1,k)printf("%d,",seq[j]);puts("");
		return;
	}
	F(j,1,i){
		seq[i]=tr({i,j});
		int ok=1;
		F(o,1,i)if(gg[seq[o]][seq[i]])ok=0;
		if(ok)DFS(i+1);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,m){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		G[x].push_back({y,z});
	}
	F(i,1,n){
		sort(G[i].begin(),G[i].end(),[](pii x,pii y){return x.se<y.se;});
		int deg=G[i].size();
		F(j,1,deg)V[G[i][j-1].fi].push_back({deg,j});
	}
	F(i,1,n){
		sort(V[i].begin(),V[i].end());
		int siz=V[i].size();
		F2(j,1,siz)if(V[i][j]==V[i][j-1])gg[tr(V[i][j])][tr(V[i][j])]=1;
		V[i].resize(unique(V[i].begin(),V[i].end())-V[i].begin());
		siz=V[i].size();
//		F2(j,0,siz)printf("(%d,%d), ",V[i][j].fi,V[i][j].se);puts("");
		F2(j,0,siz)F2(o,0,j)gg[tr(V[i][o])][tr(V[i][j])]=1;
	}
	DFS(1);
	printf("%d\n",ans);
	return 0;
}