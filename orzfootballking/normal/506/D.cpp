#pragma GCC optimize("Ofast")
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
struct dsu{
	int n,fa[100005];
	void init(int len){
		n=len;
		FOR(i,1,n)fa[i]=i;
	}
	int get(int x){
		RE fa[x]==x?x:(fa[x]=get(fa[x]));
	}
	void up(int x,int y){
		x=get(x);
		y=get(y);
		if(rand()&1){
			fa[x]=y;
		}else fa[y]=x;
	}
}D; 
V<P<int,int>> co[100005];
const int len=300;
P<int,int> qs[100005];
int ans[100005];
ll s[16000000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	int n,m;
	cin>>n>>m;
	int x,y,z;
	FOR(i,1,m){
		cin>>x>>y>>z;
		co[z].PB(MP(x,y));
	}
	int q;
	cin>>q;
	FOR(i,1,q){
		cin>>qs[i].F>>qs[i].S;
		if(qs[i].F>qs[i].S)swap(qs[i].F,qs[i].S);
	}
	int cnt=0;
	FOR(i,1,m){
		if(co[i].size()>=len){
			D.init(n);
			for(auto u:co[i])D.up(u.F,u.S);
			FOR(j,1,q){
				if(D.get(qs[j].F)==D.get(qs[j].S))ans[j]++;
			}
		}else{
			V<int> v;
			for(auto u:co[i])v.PB(u.F),v.PB(u.S);
			sort(ALL(v));
			v.erase(unique(ALL(v)),v.end());
			int l=v.size();
			D.init(l);
			for(auto u:co[i]){
				D.up(lwb(ALL(v),u.F)-v.begin()+1,
				lwb(ALL(v),u.S)-v.begin()+1);
			}
			rep(i1,0,l){
				rep(i2,i1+1,l){
					if(D.get(i1+1)==D.get(i2+1)){
						s[++cnt]=1ll*v[i1]*(n+1)+v[i2];
					}
				}
			}
		}
	}
	sort(s+1,s+cnt+1);
	FOR(i,1,q){
		ll t=1ll*qs[i].F*(n+1)+qs[i].S;
		ans[i]+=upb(s+1,s+cnt+1,t)-lwb(s+1,s+cnt+1,t);
		cout<<ans[i]<<'\n';
	}
	RE 0;
}