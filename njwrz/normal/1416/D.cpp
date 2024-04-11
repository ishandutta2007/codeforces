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
int p[200005],fa[200005],n,m,q,siz[200005];
set<int> s[200005],ts[200005];
bool era[500005];
P<int,int> ed[500005];
int tap[500005],num[500005];
V<P<int,int> > mer;
bool used[200005];
int getfa(int x){
	RE (fa[x]==x)?x:getfa(fa[x]);
}
void merge(int x,int y){
	x=getfa(x);
	y=getfa(y);
	if(x==y){
		mer.PB(MP(-1,-1));
	}else if(siz[x]<siz[y]){
		fa[x]=y;
		for(auto u:s[x])s[y].emplace(u);
		mer.PB(MP(x,y));
		siz[y]+=siz[x];
	}else{
		fa[y]=x;
		for(auto u:s[y])s[x].emplace(u);
		mer.PB(MP(y,x));
		siz[x]+=siz[y];
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	FOR(i,1,n)cin>>p[i];
	FOR(i,1,m)cin>>ed[i].F>>ed[i].S;
	FOR(i,1,q){
		cin>>tap[i]>>num[i];
		if(tap[i]==2){
			era[num[i]]=1;
		}
	}
	FOR(i,1,n)fa[i]=i,s[i].emplace(p[i]),siz[i]=1;
	FOR(i,1,m)if(!era[i]){
		merge(ed[i].F,ed[i].S);
	}
	for(int i=q;i>=1;i--){
		if(tap[i]==2){
			merge(ed[num[i]].F,ed[num[i]].S);
		}
	}
	FOR(i,1,q){
		if(tap[i]==1){
			num[i]=getfa(num[i]);
			if(s[num[i]].empty()){
				cout<<0<<'\n';
			}else {
				auto u=s[num[i]].end();
				u--;
				int t=*u;
				s[num[i]].erase(t);
				used[t]=1;
				cout<<t<<'\n';
			}
		}else{
			if(mer.back().F!=-1){
				int fr=mer.back().S;
				int in=mer.back().F;
				V<int> e;
				for(auto u:s[in]){
					if(!used[u]){
						s[fr].erase(u);
					}else e.PB(u);
				}
				for(auto u:e)s[in].erase(u);
				fa[in]=in;
			}
			mer.pop_back();
		}
	}
	RE 0;
}