#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int fa[100005],n,a[100005],siz[100005];
int f[100005];
V<int> v[100005];
bool cmp(int x,int y){
	RE a[x]>a[y];
}
int find(int x){
	if(fa[x]==x)RE x;
	else RE fa[x]=find(fa[x]);
}
signed main(){
	int m,x,y;
	scanf("%lld%lld",&n,&m);
	FOR(i,1,n)scanf("%lld",&a[i]),f[i]=fa[i]=i,siz[i]=1;
	FOR(i,1,m){
		scanf("%lld%lld",&x,&y);
		v[x].PB(y);
		v[y].PB(x);
	}
	sort(f+1,f+n+1,cmp);
	int l,r,ans=0,now;
	FOR(i,1,n){
		now=f[i];
		for(auto u:v[now])if(MP(a[u],u)>MP(a[now],now)){
			l=find(now);r=find(u);
			if(l==r)continue;
			ans+=siz[l]*siz[r]*a[now];
			fa[l]=r;siz[r]+=siz[l];
		}
	}
	double t=1.0*ans/n/(n-1)*2;
	printf("%.10f",t);
	RE 0;
}