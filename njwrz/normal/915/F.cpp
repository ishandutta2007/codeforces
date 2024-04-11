#include<bits/stdc++.h>
#define ll long long
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
int a[1000005],siz[1000005],n,fa[1000005];
V<int> v[1000005];
P<int,int> p[1000005];
int getfa(int x){
	RE (fa[x]==x)?x:(fa[x]=getfa(fa[x]));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];p[i]=MP(a[i],i);
	}
	FOR(i,1,n-1){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	FOR(i,1,n)fa[i]=i,siz[i]=1;
	sort(p+1,p+n+1);
	ll ans=0;
	FOR(i,1,n){
		int x=p[i].S;
		for(auto u:v[x])if(MP(a[u],u)<MP(a[x],x)){
			int y=getfa(u);
			fa[y]=x;
			ans+=1ll*siz[x]*siz[y]*a[x];
			siz[x]+=siz[y];
		}
	}
	FOR(i,1,n)fa[i]=i,siz[i]=1;
	for(int i=n;i>=1;i--){
		int x=p[i].S;
		for(auto u:v[x])if(MP(a[u],u)>MP(a[x],x)){
			int y=getfa(u);
			fa[y]=x;
			ans-=1ll*siz[x]*siz[y]*a[x];
			siz[x]+=siz[y];
		}
	}
	cout<<ans;
	RE 0;
}